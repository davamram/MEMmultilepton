
#ifndef MULTILEPTON_H
#define MULTILEPTON_H

#include <algorithm>

#include "MEPhaseSpace.h"

#define kJetPair_HighestPt 0
#define kJetPair_MwClosest 1
#define kJetPair_MjjLowest 2
#define kJetPair_HighestEta 3
#define kJetSingle 4
#define kJetSingleHighestEta 5
#define kTwoJetPair_MwClosest_2ndMwClosest 6
#define kTwoJetPair_MwClosest_2ndMjjLowest 7
#define kTwoJetPair_MwClosest_2ndHighestPt 8
#define kThreeJets_MwClosest_HighestPt 9
#define kTreatFirstBjetAsJet 10

#define kBjet_Present 0
#define kBjet_Missing 1

#define kJet_PresentBoth 0
#define kJet_MissingFirst 1
#define kJet_MissingSecond 2
#define kJet_MissingBoth 3
#define kJet_Present 4
#define kJet_Missing 5



struct Particle {
  int   Id;
  int   Label;
  float DeltaR;
  float CSV;
  float JEC_Up;
  float JEC_Down;
  float JER_Up;
  float JER_Down;
  float pt_ref;
  float energy_ref;
  TLorentzVector P4;
};


class MultiLepton
{
  public:
  MultiLepton();
  ~MultiLepton();

  int verbosity;

  vector<Particle> Bjets;
  vector<Particle> BjetsMatched;
  vector<Particle> Leptons;
  vector<Particle> LeptonsMatched;
  vector<Particle> Jets;
  vector<Particle> AllJets;
  vector<Particle> JetsHighestPt;
  vector<Particle> JetsClosestMw;
  vector<Particle> JetsLowestMjj;
  vector<Particle> JetsHighestEta;
  vector<Particle> ParticleGen;

  TLorentzVector Ptot;
  TLorentzVector mET;
  float sumET;
  double mET_cov00, mET_cov01, mET_cov10, mET_cov11;

  double *xL;
  double *xU;
  int nParam;

  double mB;
  double JetTFfracmin;
  double JetTFfracmax;
  double NeutMaxE;
  double MissingBMaxE;
  double MissingJetMaxE;
  double tWmin;
  double tWmaxTop;
  double tWmaxHiggs;

  unsigned int ipermlin_lep;
  unsigned int ipermlin_jet;
  unsigned int ipermlin_bjet;

  int iperm_bmiss;
  int iperm_jmiss;
  int iperm_bmiss_max;
  int iperm_jmiss_max;

  int kCatJets;

  void SetVerbosity(int);

  void FillParticle(string, Particle&);
  void FillParticle(string, int, TLorentzVector);
  void FillParticle(string, int, TLorentzVector, float);
  void FillParticle(string, int, float, float, float, float, float, TLorentzVector);

  void FillParticleMatched(string, float, int, int, TLorentzVector);
  void FillParticleGen(string, int, int, TLorentzVector);

  void LoadIntegrationRange(MEPhaseSpace**);
  void FillParticlesHypothesis(int, MEPhaseSpace**);

  void DoSort(vector<Particle>*);
  int DoPermutation(vector<Particle>*);
  int DoPermutationLinear(string, vector<Particle>*);
  int CheckPermutationHyp(int);

  int DoPermutationMissingJet(string);
  void SetPresenceBandJets(MEPhaseSpace**, int, int);

  void SwitchJetsFromAllJets(int);
  void SwitchJetSyst(int);

  void FillTTHFullyLepHyp(MEPhaseSpace**);
  void FillTTLLHyp(MEPhaseSpace**);
  void FillTTHSemiLepHyp(MEPhaseSpace**);
  void FillTTWHyp(MEPhaseSpace**, bool);
  void FillTTbarFullyLepHyp(MEPhaseSpace**);
  void FillTTbarSemiLepHyp(MEPhaseSpace**);
  void FillTLLJHyp(MEPhaseSpace**);
  void FillWZJJHyp(MEPhaseSpace**);
  void FillTHJHyp(MEPhaseSpace**);

  void AddIntegrationBound_TopLep(MEPhaseSpace**, int*, int, int, int);
  void AddIntegrationBound_TopHad(MEPhaseSpace**, int*, int, int*, int, int);
  void AddIntegrationBound_HiggsFullyLep(MEPhaseSpace**, int*);
  void AddIntegrationBound_HiggsSemiLep(MEPhaseSpace**, int*, int*, int);
  void AddIntegrationBound_Woffshell(MEPhaseSpace**, int*, int, int, bool);
  void AddIntegrationBound_OneJet(MEPhaseSpace**, int*, int, int);
  void ReadIntegrationBoundaries(int, MEPhaseSpace**);

  struct ComparePt{
    bool operator() (const Particle& PA, const Particle& PB) const {
      return PA.P4.Pt()>PB.P4.Pt();
    }
  };

  private:
};

#endif
