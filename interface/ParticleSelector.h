#ifndef PARTICLESELECTOR_H
#define PARTICLESELECTOR_H

#include "MultiLepton.h"

class ParticleSelector{

public:

  ParticleSelector();
  ~ParticleSelector();

  int nActualLeptons;
  int nActualJets;
  int nActualBjets;

  int nIntrinsicLeptons;
  int nIntrinsicJets;
  int nIntrinsicBjets;

  bool doSelectOnlyBtaggedJets;
  double csvthresh;

  void SetIntrinsicNumOfParticles(MultiLepton*, int);

  void FillAllJets(MultiLepton*);

  int SelectJetsAndBjetsFromAllJet(MultiLepton*);
  void SelectBjets(MultiLepton*, string, int*, int*, bool);

private:

};

#endif
