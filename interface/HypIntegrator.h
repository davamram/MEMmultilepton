
#ifndef SETUPINTEGRATOR_H
#define SETUPINTEGRATOR_H

#include "Math/Integrator.h"
#include "Math/Factory.h"
#include "Math/Functor.h"
#include "Math/GSLMCIntegrator.h"
#include "Math/IntegratorMultiDim.h"
#include "Math/IOptions.h"
//#include "Math/IntegratorOptions.h"
//#include "Math/AllIntegrationTypes.h"
//#include "Math/AdaptiveIntegratorMultiDim.h"
//#include "Minuit2/Minuit2Minimizer.h"
#include "TRandom2.h"
//#include "TPluginManager.h"

#include "MEPhaseSpace.h"
#include "ConfigParser.h"

struct IntegrationResult {
  double weight;
  double weightlog;
  double time;
  double err;
  double chi2;
  std::vector<double> intvar;
} ;


class HypIntegrator
{
 public:
  HypIntegrator();
  ~HypIntegrator();

  MEPhaseSpace* meIntegrator;

  int nPointsCatHyp;
  ROOT::Math::Functor** toIntegrate;

  ROOT::Math::GSLMCIntegrator* ig2;
  ROOT::Math::VegasParameters* param;

  //ROOT::Minuit2::Minuit2Minimizer* minimizer;
  ROOT::Math::Minimizer* minimizer;

  TRandom2 rnd;

  int nparam;
  int intPoints;

  int doMinimization;
  string jetChoice;
  int nPermutationJetSyst;
  double csvthresh;

  void InitializeIntegrator(ConfigParser*);
  void SetNCalls(int);
  void ResetCounters();
  void SetupIntegrationHypothesis(int, int, int);
  IntegrationResult DoIntegration(double* , double*, int, int);
  void FillErrHist(TH1F**);

  void SetupMinimizerHypothesis(int , int , int , int );
  double* FindMinimizationiInitialValues(double*, double*);
  IntegrationResult DoMinimization(double*, double*,double*);

 private:
};

#endif
