/***************************************************/
/*  Example of simple producer for MEM weights     */
/*  Author : N. Chanon (IPNL)                      */
/***************************************************/

#include "../src/HypIntegrator.cpp"
#include "../src/MultiLepton.cpp"
#include "../src/ConfigParser.cpp"
#include "../src/Tools.cpp"
#include "../src/Permutations.cpp"

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{

  cout << "Simple example of MEM weight computation" <<endl;

  int nhyp;
  string* shyp;
  int* hyp;
  int* nPointsHyp;
  int* index_hyp;

  //Load configuration from config file and get info on the MEM hypotheses to be computed
  ConfigParser cfgParser;
  cfgParser.LoadConfig(string(argv[1]));
  cfgParser.GetHypotheses(&nhyp, &shyp, &hyp, &nPointsHyp, &index_hyp);

  //Initialize the integrator
  HypIntegrator hypIntegrator;
  hypIntegrator.InitializeIntegrator(&cfgParser);

  //Create multiLepton object, to be filled at each event before computing the MEM weights
  MultiLepton multiLepton;

  //Prepare looping over permutations for a given hypothesis. 
  //TTH annd TTbar are a special case, since the semi-leptonic and fully leptonic case are computed separately.
  //int nHypAllowed_TTH = 0, nHypAllowed_TTbar = 0;
  Permutations* MEMpermutations = new Permutations[nhyp];
  Permutations* MEMpermutationsTTH = new Permutations();
  Permutations* MEMpermutationsTTbar = new Permutations();

  //Loop on events (here, give only an example for one event)
  //For each event, setup multiLepton object with leptons and jets in the event.
  //Enter in the "lepton" selection only the leptons (2lss, 3l or 4l) selected in the analysis 
  //Enter here all jets: jets considered as b-jets and other needed jets will be selected from the global "alljet" collection
  TLorentzVector Lepton1; Lepton1.SetPtEtaPhiE(112.2630, -0.3393633, 2.704189, 118.7898);
  multiLepton.FillParticle("lepton", -13, Lepton1);
  TLorentzVector Lepton2; Lepton2.SetPtEtaPhiE(96.21953, -1.136115, -0.1781794, 165.2912);
  multiLepton.FillParticle("lepton", -13, Lepton2);
  TLorentzVector Jet1; Jet1.SetPtEtaPhiE(56.04011, -0.7021231, 1.718880, 71.17232);
  multiLepton.FillParticle("alljet", -13, Jet1, 0.9652954);
  TLorentzVector Jet2; Jet2.SetPtEtaPhiE(75.35954 , 0.8866753, -1.743217, 107.9244);
  multiLepton.FillParticle("alljet", -13, Jet2, 0.1090842);
  TLorentzVector Jet3; Jet3.SetPtEtaPhiE(26.48424, 2.596374, 2.769826, 178.7654);
  multiLepton.FillParticle("alljet", -13, Jet3, -2.);

  //Need also to input mET and sumET information, for transfer functions
  TLorentzVector mET; mET.SetPxPyPzE(39.84192, 9.747291, 0, sqrt(39.84192*39.84192+9.747291*9.747291));
  multiLepton.mET = mET;
  multiLepton.sumET = 3270.752;

  //nHypAllowed_TTH = 0;
  //nHypAllowed_TTbar = 0;

  int initresult = 0;
  for (int ih=0; ih<nhyp; ih++){ //Loop on each MEM hypothesis defined in the config

    //Setup permutations for each hyppothesis: leptons, jets and b-jets will be permutated within the multiLepton object
    MEMpermutations[ih].SetMultiLepton(&multiLepton, &hypIntegrator);
    initresult = MEMpermutations[ih].InitializeHyp(&hypIntegrator, hyp[ih], nPointsHyp[ih], shyp[ih]);
    //Computation of all weights, and average of the MEM weights over permutations
    if (initresult==1) MEMpermutations[ih].LoopPermutations(&hypIntegrator);

  }

  cout << "-------- MEM RESULTS --------"<<endl;
  for (int ih=0; ih<10; ih++){
    //cout << "ih="<<ih<<" index_hyp="<<index_hyp[ih]<<endl;
    if (index_hyp[ih]!=-1){
      if (MEMpermutations[index_hyp[ih]].computeHyp){
	cout << "MEM hypothesis "<< shyp[index_hyp[ih]]<<" weight="<< MEMpermutations[index_hyp[ih]].resMEM_avgExl0.weight<<" kinfitscore="<<MEMpermutations[index_hyp[ih]].resKin_maxKinFit_Int.weight<<endl;
      }
    }
  }

  if (index_hyp[1]!=-1 || index_hyp[2]!=-1) {
    CombineTwoHypotheses(&MEMpermutations[index_hyp[1]], index_hyp[1], &MEMpermutations[index_hyp[2]], index_hyp[2], MEMpermutationsTTH);
    cout << "MEM hypothesis TTH weight="<< MEMpermutationsTTH->resMEM_avgExl0.weight<<" kinfitscore="<<MEMpermutationsTTH->resKin_maxKinFit_Int.weight<<endl;
  }
  if (index_hyp[5]!=-1 || index_hyp[6]!=-1) {
    CombineTwoHypotheses(&MEMpermutations[index_hyp[5]], index_hyp[5], &MEMpermutations[index_hyp[6]], index_hyp[6], MEMpermutationsTTbar);
    cout << "MEM hypothesis TTbar weight="<< MEMpermutationsTTbar->resMEM_avgExl0.weight<<" kinfitscore="<<MEMpermutationsTTbar->resKin_maxKinFit_Int.weight<<endl;
  }

  return 0;
}
