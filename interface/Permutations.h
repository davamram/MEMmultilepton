#ifndef PERMUTATIONS_H
#define PERMUTATIONS_H

#include "HypIntegrator.h"
#include "MultiLepton.h"
#include "ParticleSelector.h"

using namespace std;

class Permutations {

  public:

  MultiLepton multiLepton;
  ParticleSelector* particleSelector;

  int verbosity;

  int Hypothesis;
  string HypothesisName;

  bool computeHyp;

  int doMinimization;

  bool doPermutationLep;
  bool doPermutationJet;
  bool doPermutationBjet;
  int nPermutationJetSyst;

  int stage;
  int iterationNumber;

  IntegrationResult resMEM_max;
  IntegrationResult resMEM_maxKinFit;
  IntegrationResult resKin_maxKinFit;
  IntegrationResult resMEM_maxKinFit_Int;
  IntegrationResult resKin_maxKinFit_Int;

  std::vector<IntegrationResult> resMEM_all;
  std::vector<IntegrationResult> resMEM_all_JEC_up;
  std::vector<IntegrationResult> resMEM_all_JEC_down;
  std::vector<IntegrationResult> resMEM_all_JER_up;
  std::vector<IntegrationResult> resMEM_all_JER_down;
  IntegrationResult resMEM_logavgExl0;
  IntegrationResult resMEM_avgExl0;
  IntegrationResult resMEM_avgIncl0;
  IntegrationResult resMEM_avgExl0_JEC_up;
  IntegrationResult resMEM_avgExl0_JEC_down;
  IntegrationResult resMEM_avgExl0_JER_up;
  IntegrationResult resMEM_avgExl0_JER_down;

  int nHypAllowed;
  int nNullResult;

  Permutations();
  ~Permutations();
  void SetMultiLepton(MultiLepton*, HypIntegrator*);
  int InitializeHyp(HypIntegrator*, int, int, string);//, int, string, int);
  void LoopPermutations(HypIntegrator*);

  IntegrationResult GetMEMKinFitResult(HypIntegrator*, int);
  void GetMEMResult_Syst(HypIntegrator*, IntegrationResult**);
  IntegrationResult GetMEMResult(HypIntegrator*);

  void UpdateAverageWeight(IntegrationResult*, std::vector<IntegrationResult>, bool, string);

  void CopyResults(Permutations);

  private:

  double xs;
  double xsTTH;
  double xsTTLL;
  double xsTTLL_EFT;
  double xsTTLL_EFT_only;
  double xsTTW;
  double xsTTbar;
  double xsTLLJ;
  double xsWZJJ;
  double xsTHJ;

  IntegrationResult res;
  IntegrationResult* res_syst;
  IntegrationResult resMinimized;

};

#endif
