
#ifndef SETUPINTEGRATOR_CPP
#define SETUPINTEGRATOR_CPP

#include "Math/Integrator.h"
#include "Math/Factory.h"
#include "Math/Functor.h"
#include "Math/GSLMCIntegrator.h"
#include "Math/IntegratorMultiDim.h"
#include "Math/IOptions.h"
#include "Math/IntegratorOptions.h"
#include "Math/AllIntegrationTypes.h"
#include "Math/AdaptiveIntegratorMultiDim.h"
#include "Minuit2/Minuit2Minimizer.h"
#include "TRandom2.h"
#include "TPluginManager.h"

#include "../interface/HypIntegrator.h"
#include "../interface/MEPhaseSpace.h"
#include "../interface/ConfigParser.h"
#include "../interface/MultiLepton.h"
//#include "../Minimizer/SubGradient.h"

#include <ctime>

HypIntegrator::HypIntegrator(){

  //gPluginMgr->AddHandler("ROOT::Math::Minimizer", "subgradient", "SubGradientDescent", "SubGradient_h", "SubGradientDescent(const char*)");

  meIntegrator = new MEPhaseSpace();

  toIntegrate = new ROOT::Math::Functor*[16];
  for (int i=0; i<16; i++){
    toIntegrate[i] = new ROOT::Math::Functor(meIntegrator, &MEPhaseSpace::Eval, i);
  }

  intPoints = 10000;
  ig2 = new ROOT::Math::GSLMCIntegrator( ROOT::Math::IntegrationMultiDim::kVEGAS, 1.e-12, 1.e-5, intPoints);
  param = new ROOT::Math::VegasParameters( *(ig2->ExtraOptions()) );

  minimizer = new ROOT::Minuit2::Minuit2Minimizer( ROOT::Minuit2::kMigrad );
  //minimizer = ROOT::Math::Factory::CreateMinimizer("subgradient","");


  //minimizer->SetPrintLevel(0); //FIXME -- put back

}

HypIntegrator::~HypIntegrator(){


}

void HypIntegrator::InitializeIntegrator(ConfigParser* cfgParser){

  meIntegrator->SetVerbosity(cfgParser->valVerbosity);

  meIntegrator->SetComEnergy(cfgParser->valComEnergy);
  meIntegrator->SetGenerator(cfgParser->valGenerator);
  meIntegrator->InitializeLHAPDF(cfgParser->valPdf);
  meIntegrator->InitializeMadgraphProcesses(cfgParser->valMadgraphDir);

  meIntegrator->SetOptimization(cfgParser->valOptim);
  meIntegrator->SetOptimization(cfgParser->valOptimTopHad, cfgParser->valOptimTopLep, cfgParser->valOptimHiggs, cfgParser->valOptimW);

  meIntegrator->JetTFfracmin = cfgParser->valJetTFfracmin;
  meIntegrator->JetTFfracmax = cfgParser->valJetTFfracmax;
  meIntegrator->NeutMaxE = cfgParser->valNeutMaxE;

  meIntegrator->transferFunctions->SetVerbosity(cfgParser->valVerbosity);
  meIntegrator->transferFunctions->SetTFChoice(cfgParser->valTFChoice);
  meIntegrator->transferFunctions->SetTFOption(cfgParser->valTFOption);
  meIntegrator->transferFunctions->LoadTFfromHisto(cfgParser->valTFfile);

  if (cfgParser->valVerbosity>=1) cout << "Before loading minimizers" << endl;

  doMinimization = cfgParser->valDoMinimization;
  jetChoice = cfgParser->valJetChoice;
  nPermutationJetSyst = cfgParser->nJetSyst;
  csvthresh = cfgParser->valCsvThresh;

  if (doMinimization==1) minimizer = ROOT::Math::Factory::CreateMinimizer("Minuit2", "Migrad");
  if (doMinimization==2) minimizer = ROOT::Math::Factory::CreateMinimizer("Minuit2", "Simplex");
  //if (doMinimization==3) minimizer = ROOT::Math::Factory::CreateMinimizer("subgradient","");

  if (cfgParser->valVerbosity>=1) cout << "End of InitializeIntegrator" <<endl;
  //minimizer->SetPrintLevel(0); //FIXME -- put back

 return;
}

void HypIntegrator::SetNCalls(int nPoints)
{
  intPoints = nPoints;
  ROOT::Math::IntegratorMultiDimOptions opts = ig2->Options();
  opts.SetNCalls( intPoints  );
  ig2->SetOptions( opts ) ;
  return;
}

void HypIntegrator::SetupIntegrationHypothesis(int kMode, int kCat, int nPoints){

  meIntegrator->SetIntegrationMode(kMode);

  nparam = meIntegrator->GetNumberIntegrationVar(kMode, kCat);

  ROOT::Math::Functor* FunctorHyp = NULL;
  FunctorHyp = toIntegrate[nparam];

  //ig2 = new ROOT::Math::GSLMCIntegrator( ROOT::Math::IntegrationMultiDim::kVEGAS, 1.e-12, 1.e-5, intPoints);
  //param = new ROOT::Math::VegasParameters( *(ig2->ExtraOptions()) );

  ig2->SetFunction(*FunctorHyp);

  //param->stage      = stageValue;
  //ig2->SetParameters(*param);

  nPointsCatHyp = nPoints;
  if (meIntegrator->iNleptons==3){
    if (kMode!=kMEM_TTW_TopAntitopDecay && kMode!=kMEM_TTbar_TopAntitopFullyLepDecay && kMode!=kMEM_TLLJ_TopLepDecay && kMode!=kMEM_THJ_TopLepDecay && kMode!=kMEM_WZJJ_LepDecay){
      if (kCat==kCat_3l_1b_2j || kCat==kCat_3l_2b_1j) nPointsCatHyp *= 10;
      if (kCat==kCat_3l_1b_1j || kCat==kCat_3l_2b_0j) nPointsCatHyp *= 50;
    }
    if (kMode==kMEM_TTW_TopAntitopDecay || kMode==kMEM_TTbar_TopAntitopFullyLepDecay){
      if (kCat==kCat_3l_1b_2j || kCat==kCat_3l_1b_1j) nPointsCatHyp *= 10;
    }
  }
  else if (meIntegrator->iNleptons==4){
    if (kCat==kCat_4l_2b) nPointsCatHyp *= 3;
    if (kCat==kCat_4l_1b) nPointsCatHyp *= 30;
  }
  else if (meIntegrator->iNleptons==2){
    if (kMode!=kMEM_TTW_TopAntitopDecay && kMode!=kMEM_TTbar_TopAntitopSemiLepDecay && kMode!=kMEM_THJ_TopLepDecay && kMode!=kMEM_THJ_TopLepDecay){
      if (kCat==kCat_2lss_2b_3j || kCat==kCat_2lss_1b_4j) nPointsCatHyp *= 10;
      if (kCat==kCat_2lss_1b_3j || kCat==kCat_2lss_2b_2j) nPointsCatHyp *= 50;
    }
    if (kMode==kMEM_TTW_TopAntitopDecay || kMode==kMEM_TTbar_TopAntitopSemiLepDecay){
      if (kCat==kCat_2lss_1b_4j || kCat==kCat_2lss_1b_3j || kCat==kCat_2lss_1b_2j) nPointsCatHyp *= 10;
      if (kCat==kCat_2lss_1b_1j) nPointsCatHyp *= 50;
    }
    if (kMode==kMEM_THJ_TopLepDecay){
      if (kCat==kCat_2lss_2b_2j || kCat==kCat_2lss_1b_2j) nPointsCatHyp *= 10;
      if (kCat==kCat_2lss_2b_1j || kCat==kCat_2lss_1b_1j) nPointsCatHyp *= 50;
    }
  }

  SetNCalls(nPointsCatHyp);
  ResetCounters();

  meIntegrator->weight_max_intvar.clear();// = new float[nparam];

  return;
}

void HypIntegrator::SetupMinimizerHypothesis(int kMode, int kCat, int stageValue, int nPoints){

  meIntegrator->SetIntegrationMode(kMode);

  nparam = meIntegrator->GetNumberIntegrationVar(kMode, kCat);

  ROOT::Math::Functor* FunctorHyp = NULL;
  FunctorHyp = toIntegrate[nparam];

  minimizer->SetFunction(*FunctorHyp);

  minimizer->SetMaxFunctionCalls(nPointsCatHyp);
  //minimizer->SetPrintLevel(0); //FIXME -- put back

  //subgd->SetFunction(*FunctorHyp);

  return;
}

void HypIntegrator::ResetCounters(){

  meIntegrator->iIteration = 0;
  meIntegrator->iCall = 0;
  meIntegrator->weight_max = 0;

  for (int i=0; i<20; i++) meIntegrator->errorCounter[i]=0;

  return;
}

IntegrationResult HypIntegrator::DoIntegration(double* xL, double* xU, int stageValue, int iterationNumber)
{

  param->stage      = stageValue;
  param->iterations = iterationNumber;
  ig2->SetParameters(*param);

  ResetCounters();
  IntegrationResult res;

  double click1 = std::clock();

  res.weight = ig2->Integral(xL, xU);
  res.time = ( std::clock() - click1 ) / (double) CLOCKS_PER_SEC;
  res.err = ig2->Error();
  res.chi2 = ig2->ChiSqr();

  //ig2->~GSLMCIntegrator();
  //param->~VegasParameters();

  return res;
}

double* HypIntegrator::FindMinimizationiInitialValues(double* xL, double* xU)
{

  ResetCounters();

  double* varbest = new double[minimizer->NDim()];
  double* var = new double[minimizer->NDim()];

  double val = 1000;
  double valmin = 1000;
  //int ival=0;
  for (int i=0; i<nPointsCatHyp; i++){
    for (unsigned int ivar=0; ivar<minimizer->NDim(); ivar++){
      var[ivar] = xL[ivar] + rnd.Uniform()*(xU[ivar]-xL[ivar]);
    }
    val = meIntegrator->Eval(var);
    //cout << "val=" << val<< endl;
    if (val<valmin) {
      valmin = val;
      //ival=i;
      for (unsigned int ivarb=0; ivarb<minimizer->NDim(); ivarb++) varbest[ivarb] = var[ivarb];
      }
  }

    if (valmin!=1000) {
      //cout << "Found initial point for minimization, at iteration "<< ival<<"; -log(Integrand)="<<valmin<<endl;
    }
    if (valmin==1000){
      for (unsigned int ivar=0; ivar<minimizer->NDim(); ivar++){
        varbest[ivar] = 0.5*(xL[ivar]+xU[ivar]);
      }
    }

  return varbest;
}

IntegrationResult HypIntegrator::DoMinimization(double* xL, double* xU, double* xInit)
{

  ResetCounters();

  IntegrationResult res;

  string si;
  stringstream* ss = new stringstream[minimizer->NDim()];
  for (unsigned int i=0; i<minimizer->NDim(); i++){
    ss[i] << i;
    ss[i] >> si;
    minimizer->SetLimitedVariable(i, si, xInit[i], 0.01, xL[i], xU[i]);
  }

  double click1 = std::clock();

  minimizer->Minimize();

  res.time = ( std::clock() - click1 ) / (double) CLOCKS_PER_SEC;

  const double *xs = minimizer->X();
  res.weight = meIntegrator->Eval(xs);
  res.intvar = meIntegrator->weight_max_intvar;

  return res;
}

void HypIntegrator::FillErrHist(TH1F** h){

  //cout << "FillErrHist nIteration="<<meIntegrator->iIteration<<endl;

  for (int i=0; i<5; i++) {
    //cout << "Err "<<i<<", sum "<<meIntegrator->errorCounter[i]<<endl;
    //cout<<"proba "<<((double)meIntegrator->errorCounter[i])/((double)meIntegrator->iIteration)<<endl;
    (*h)->Fill(i+0.5, ((double)meIntegrator->errorCounter[i])/((double)meIntegrator->iIteration));
  }

  return;
}
#endif
