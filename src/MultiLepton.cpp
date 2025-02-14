
#ifndef MULTILEPTON_CPP
#define MULTILEPTON_CPP

#include <algorithm>

#include "../interface/MultiLepton.h"
#include "../interface/MEPhaseSpace.h"

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

MultiLepton::MultiLepton(){

  verbosity = 0;

  kCatJets = -1;

  nParam = 15;
  xL = new double[nParam];
  xU = new double[nParam];

  mB = 4.7;
  JetTFfracmin = 0.65;//0.65; //next try 0.5 (5 sigma at 100 GeV for a 0.2*Egen gaussian width)
  JetTFfracmax = 2.0;//2.0; //next try 5.0 (4.5 sigma at 100 GeV)
  NeutMaxE = 300.; //try 500 or 1000 ?
  MissingBMaxE = 500;
  MissingJetMaxE = 500;

  tWmin = TMath::ATan(-80.419/2.0476);
  tWmaxTop = TMath::ATan((173*173-mB*mB-80.419*80.419)/(80.419*2.0476));
  tWmaxHiggs = TMath::ATan((125*125-80.419*80.419)/(80.419*2.0476));

  ipermlin_lep = 0;
  ipermlin_jet = 0;
  ipermlin_bjet = 0;
  iperm_bmiss = 0;
  iperm_jmiss = 0;

  iperm_bmiss_max = 0;
  iperm_jmiss_max = 0;

}

MultiLepton::~MultiLepton(){

}

void MultiLepton::FillParticle(string Type, Particle &p){

  if (Type=="lepton") Leptons.push_back(p);
  if (Type=="jet") Jets.push_back(p);
  if (Type=="bjet") Bjets.push_back(p);
  if (Type=="alljet") AllJets.push_back(p);
  if (Type=="jetHighestPt") JetsHighestPt.push_back(p);
  if (Type=="jetClosestMw") JetsClosestMw.push_back(p);
  if (Type=="jetLowestMjj") JetsLowestMjj.push_back(p);
  if (Type=="jetHighestEta") JetsHighestEta.push_back(p);

  if (verbosity>=1) cout << Type << " " << p.Id << " pt="<<p.P4.Pt()<<" eta="<<p.P4.Eta()<<" phi="<<p.P4.Phi()<<" E="<<p.P4.E() << endl;

  return;
}

void MultiLepton::FillParticle(string Type, int id, TLorentzVector p4){

  Particle p;
  p.Id = id;
  p.P4 = p4;
  if (Type=="lepton") Leptons.push_back(p);
  if (Type=="jet") Jets.push_back(p);
  if (Type=="bjet") Bjets.push_back(p);
  if (Type=="alljet") AllJets.push_back(p);
  if (Type=="jetHighestPt") JetsHighestPt.push_back(p);
  if (Type=="jetClosestMw") JetsClosestMw.push_back(p);
  if (Type=="jetLowestMjj") JetsLowestMjj.push_back(p);
  if (Type=="jetHighestEta") JetsHighestEta.push_back(p);

  if (verbosity>=1) cout << Type << " " << id << " pt="<<p.P4.Pt()<<" eta="<<p.P4.Eta()<<" phi="<<p.P4.Phi()<<" E="<<p.P4.E() << endl;

  return;
}

void MultiLepton::FillParticle(string Type, int id, TLorentzVector p4, float csv){

  Particle p;
  p.Id = id;
  p.P4 = p4;
  p.CSV = csv;
  if (Type=="lepton") Leptons.push_back(p);
  if (Type=="jet") Jets.push_back(p);
  if (Type=="bjet") Bjets.push_back(p);
  if (Type=="alljet") AllJets.push_back(p);
  if (Type=="jetHighestPt") JetsHighestPt.push_back(p);
  if (Type=="jetClosestMw") JetsClosestMw.push_back(p);
  if (Type=="jetLowestMjj") JetsLowestMjj.push_back(p);
  if (Type=="jetHighestEta") JetsHighestEta.push_back(p);

  if (verbosity>=1) cout << Type << " " << id << " pt="<<p.P4.Pt()<<" eta="<<p.P4.Eta()<<" phi="<<p.P4.Phi()<<" E="<<p.P4.E() << endl;

  return;
}

void MultiLepton::FillParticle(string Type, int id, float csv, float jec_up, float jec_down, float jer_up, float jer_down, TLorentzVector p4){

  Particle p;
  p.Id = id;
  p.P4 = p4;
  p.CSV = csv;
  p.JEC_Up = jec_up;
  p.JEC_Down = jec_down;
  p.JER_Up = jer_up;
  p.JER_Down = jer_down;

  if (Type=="jet") Jets.push_back(p);
  if (Type=="bjet") Bjets.push_back(p);
  if (Type=="alljet") AllJets.push_back(p);
  if (Type=="jetHighestPt") JetsHighestPt.push_back(p);
  if (Type=="jetClosestMw") JetsClosestMw.push_back(p);
  if (Type=="jetLowestMjj") JetsLowestMjj.push_back(p);
  if (Type=="jetHighestEta") JetsHighestEta.push_back(p);

  if (verbosity>=1) cout << Type << " " << p.Id << " csv="<<p.CSV << " pt="<<p.P4.Pt()<<" eta="<<p.P4.Eta()<<" phi="<<p.P4.Phi()<<" E="<<p.P4.E() << endl;

  return;
}

void MultiLepton::FillParticleMatched(string Type, float deltaR, int label, int id, TLorentzVector p4){

  Particle 	p;
  p.DeltaR 	= deltaR;
  p.Label	= label;
  p.Id 		= id;
  p.P4 		= p4;

  if (Type=="lepton") 	LeptonsMatched.push_back(p);
  if (Type=="jet") 	BjetsMatched.push_back(p);

  return;
}

void MultiLepton::FillParticleGen(string Type, int label, int id, TLorentzVector p4){

  Particle      p;
  p.Label       = label;
  p.Id          = id;
  p.P4          = p4;

  ParticleGen.push_back(p);

  return;
}

void MultiLepton::DoSort(vector<Particle>* particles)
{
  std::sort(((*particles).begin()), ((*particles).end()), MultiLepton::ComparePt());
  return;
}

int MultiLepton::DoPermutation(vector<Particle>* particles)
{
  int res = std::next_permutation(((*particles).begin()), ((*particles).end()), MultiLepton::ComparePt());
  return res;
}

int MultiLepton::DoPermutationLinear(string Type, vector<Particle>* particles)
{
  if (verbosity>=1) cout << "doPermutation linear"<<endl;
  int res = 0;
  Particle p = (*particles).at(0);
  (*particles).erase((*particles).begin());
  (*particles).push_back(p);
  if (Type=="lepton") {
    ipermlin_lep++;
    if (ipermlin_lep>=(*particles).size()) {
      res=0;
      ipermlin_lep = 0;
    }
    else res=1;
  }
  if (Type=="jet") {
    ipermlin_jet++;
    if (ipermlin_jet>=(*particles).size()) {
      res=0;
      ipermlin_jet = 0;
    }
    else res=1;
  }
  if (Type=="bjet") {
    ipermlin_bjet++;
    if (ipermlin_bjet>=(*particles).size()) {
      res=0;
      ipermlin_bjet = 0;
    }
    else res=1;
  }

  return res;
}

int MultiLepton::DoPermutationMissingJet(string Type){

  int res = 1;
  if (Type=="bjet") {
    iperm_bmiss++;
    if (iperm_bmiss>=iperm_bmiss_max) {
      res=0;
      iperm_bmiss = 0;
    }
  }
  if (Type=="jet") {
    iperm_jmiss++;
    if (iperm_jmiss>=iperm_jmiss_max) {
      res=0;
      iperm_jmiss = 0;
    }
  }

  if (verbosity>=1) cout << "iperm_bmiss="<<iperm_bmiss<<" iperm_jmiss="<<iperm_jmiss<<endl;

  return res;
}

void MultiLepton::LoadIntegrationRange(MEPhaseSpace** meIntegrator)
{

  JetTFfracmin = (*meIntegrator)->JetTFfracmin;
  JetTFfracmax = (*meIntegrator)->JetTFfracmax;
  NeutMaxE = (*meIntegrator)->NeutMaxE;
  return;
}

void MultiLepton::FillParticlesHypothesis(int kMode, MEPhaseSpace** meIntegrator)
{

  if (kMode==kMEM_TTLL_TopAntitopDecay || kMode==kMEM_TTLL_EFT_TopAntitopDecay || kMode==kMEM_TTLL_EFT_only_TopAntitopDecay) FillTTLLHyp(meIntegrator);
  if (kMode==kMEM_TTH_TopAntitopHiggsDecay) FillTTHFullyLepHyp(meIntegrator);
  if (kMode==kMEM_TTH_TopAntitopHiggsSemiLepDecay) FillTTHSemiLepHyp(meIntegrator);
  if (kMode==kMEM_TTW_TopAntitopDecay) FillTTWHyp(meIntegrator, 0);
  if (kMode==kMEM_TTWJJ_TopAntitopDecay) FillTTWHyp(meIntegrator, 1);
  if (kMode==kMEM_TTbar_TopAntitopFullyLepDecay) FillTTbarFullyLepHyp(meIntegrator);
  if (kMode==kMEM_TTbar_TopAntitopSemiLepDecay) FillTTbarSemiLepHyp(meIntegrator);
  if (kMode==kMEM_TLLJ_TopLepDecay) FillTLLJHyp(meIntegrator);
  if (kMode==kMEM_WZJJ_LepDecay) FillWZJJHyp(meIntegrator);
  if (kMode==kMEM_THJ_TopLepDecay) FillTHJHyp(meIntegrator);

  (*meIntegrator)->transferFunctions->MeasuredVarForTF.mET_Px = mET.Px();
  (*meIntegrator)->transferFunctions->MeasuredVarForTF.mET_Py = mET.Py();
  (*meIntegrator)->transferFunctions->MeasuredVarForTF.sumET = sumET;
  (*meIntegrator)->transferFunctions->MeasuredVarForTF.mET_cov00 = mET_cov00;
  (*meIntegrator)->transferFunctions->MeasuredVarForTF.mET_cov01 = mET_cov01;
  (*meIntegrator)->transferFunctions->MeasuredVarForTF.mET_cov10 = mET_cov10;
  (*meIntegrator)->transferFunctions->MeasuredVarForTF.mET_cov11 = mET_cov11;

  Ptot.SetPxPyPzE(0,0,0,0);
  for (unsigned int i=0; i<Bjets.size(); i++) Ptot += Bjets[i].P4;
  for (unsigned int i=0; i<Jets.size(); i++) Ptot += Jets[i].P4;
  for (unsigned int i=0; i<Leptons.size(); i++) Ptot += Leptons[i].P4;
  Ptot += mET;

  (*meIntegrator)->transferFunctions->MeasuredVarForTF.Recoil_Px = -Ptot.Px();
  (*meIntegrator)->transferFunctions->MeasuredVarForTF.Recoil_Py = -Ptot.Py();

  ReadIntegrationBoundaries(kMode, meIntegrator);

  return;
}

void MultiLepton::ReadIntegrationBoundaries(int kMode, MEPhaseSpace** meIntegrator){

  int nparam = (*meIntegrator)->GetNumberIntegrationVar(kMode, kCatJets);

  for (int i=0; i<nparam; i++) {
     if (verbosity>=1) cout << "Var "<<i<<" xL="<<xL[i]<<" xU="<<xU[i]<<endl;
     if ((xU[i] < xL[i]) && (verbosity>=1)) cout << "Error: xU < xL" << endl;
  }
  return;
}
void MultiLepton::CheckHighestPtCouple(vector <Particle> Lepton, int *checking){

  if((Lepton[0].Id=Lepton[2].Id) && (Lepton[0].P4.Pt()<Lepton[2].P4.Pt())) {
    *checking=0;
  }
  if((Lepton[1].Id=Lepton[3].Id) && (Lepton[1].P4.Pt()<Lepton[3].P4.Pt())) {
    *checking=0;
  }
  if((Lepton[0].P4.Pt()+Lepton[1].P4.Pt())<(Lepton[2].P4.Pt()+Lepton[3].P4.Pt())){
    *checking=0;
  }
}
int MultiLepton::CheckPermutationHyp(int kMode){

  int check = 1;

  if (Leptons.size()==3){
    if (kMode==kMEM_TTLL_TopAntitopDecay || kMode==kMEM_TLLJ_TopLepDecay){
      if (Leptons[0].Id != -Leptons[1].Id) check=0; // opposite sign same flavour to make a Z
      if (!(Leptons[0].Id>0 && Leptons[1].Id<0)) check=0; // ME needs l+ l- ordering
    }
    if (kMode==kMEM_WZJJ_LepDecay){
      if (Leptons[1].Id != -Leptons[2].Id) check=0; // opposite sign same flavour to make a Z
      if (!(Leptons[1].Id>0 && Leptons[2].Id<0)) check=0; // ME needs l+ l- ordering
    }

    if (kMode==kMEM_TTH_TopAntitopHiggsDecay || kMode==kMEM_THJ_TopLepDecay){
      if (!(Leptons[0].Id>0 && Leptons[1].Id<0)) check=0; //opposite sign, and ME needs l+ l- ordering
    }

    if (kMode==kMEM_TTH_TopAntitopHiggsSemiLepDecay){
      if (!(Leptons[1].Id>0 && Leptons[2].Id<0)) check=0; //opposite sign leptons from tops, ordered
    }

    if (kMode==kMEM_TTW_TopAntitopDecay || kMode==kMEM_TTWJJ_TopAntitopDecay){
      if (!(Leptons[1].Id>0 && Leptons[2].Id<0)) check=0; //opposite sign leptons from tops, ordered
    }

    if (kMode==kMEM_TTbar_TopAntitopFullyLepDecay){
      if (!(Leptons[0].Id>0 && Leptons[1].Id<0)) check=0; //opposite sign leptons from tops, ordered
    }

    if (kMode==kMEM_TTbar_TopAntitopSemiLepDecay){
      check=1;
    }

  }
  if (Leptons.size()==4){
    if (kMode==kMEM_TTH_TopAntitopHiggsDecay){
      if (!(Leptons[0].Id>0 && Leptons[1].Id<0)) check=0; //opposite sign, and ME needs l+ l- ordering
      if (!(Leptons[2].Id>0 && Leptons[3].Id<0)) check=0; //opposite sign leptons from tops, ordered
    }
    if (kMode==kMEM_TTLL_TopAntitopDecay || kMode==kMEM_TTLL_EFT_TopAntitopDecay || kMode==kMEM_TTLL_EFT_only_TopAntitopDecay){
      if (Leptons[0].Id != -Leptons[1].Id) check=0; // opposite sign same flavour to make a Z
      if (!(Leptons[0].Id>0 && Leptons[1].Id<0)) check=0; // ME needs l+ l- ordering
      if (!(Leptons[2].Id>0 && Leptons[3].Id<0)) check=0; //opposite sign leptons from tops, ordered

      CheckHighestPtCouple(Leptons, &check); //Take only the highest pt-couple (cancel permutations, only one solution)
    }
    if (kMode==kMEM_TTbar_TopAntitopFullyLepDecay){
      if (!(Leptons[0].Id>0 && Leptons[1].Id<0)) check=0; //opposite sign leptons from tops, ordered
    }
  }
  if (Leptons.size()==2){
    if (kMode==kMEM_TTH_TopAntitopHiggsSemiLepDecay || kMode==kMEM_THJ_TopLepDecay){
      if (!(Leptons[0].Id * Leptons[1].Id > 0)) check=0; //same sign leptons
    }
    if (kMode==kMEM_TTW_TopAntitopDecay || kMode==kMEM_TTWJJ_TopAntitopDecay){
      if (!(Leptons[0].Id * Leptons[1].Id > 0)) check=0; //same sign leptons
    }
    if (kMode==kMEM_TTbar_TopAntitopSemiLepDecay){
      check=1;
    }
  }



  return check;
}

void MultiLepton::SwitchJetsFromAllJets(int kMode){

  Jets.clear();

  if (kMode==kJetSingle){
    Jets.push_back(JetsHighestPt[0]);
  }
  if (kMode==kJetSingleHighestEta){
    Jets.push_back(JetsHighestEta[0]);
  	//cout<<"JetsHighestEta.size() = "<<JetsHighestEta.size()<<endl;
  }
  if (kMode==kJetPair_HighestPt){
    Jets.push_back(JetsHighestPt[0]);
    Jets.push_back(JetsHighestPt[1]);
  }
  if (kMode==kJetPair_MwClosest){
    Jets.push_back(JetsClosestMw[0]);
    Jets.push_back(JetsClosestMw[1]);
  }
  if (kMode==kJetPair_MjjLowest){
    Jets.push_back(JetsLowestMjj[0]);
    Jets.push_back(JetsLowestMjj[1]);
  }
  if (kMode==kJetPair_HighestEta){
    Jets.push_back(JetsHighestEta[0]);
    Jets.push_back(JetsHighestEta[1]);
  }
  if (kMode==kTreatFirstBjetAsJet){
    Jets.push_back(Bjets[0]);
    Jets.push_back(JetsHighestPt[0]);
  }
  if (kMode==kTwoJetPair_MwClosest_2ndMwClosest){
    Jets.push_back(JetsClosestMw[0]);
    Jets.push_back(JetsClosestMw[1]);
    Jets.push_back(JetsClosestMw[2]);
    Jets.push_back(JetsClosestMw[3]);
  }
  if (kMode==kTwoJetPair_MwClosest_2ndMjjLowest){
    Jets.push_back(JetsClosestMw[0]);
    Jets.push_back(JetsClosestMw[1]);
    Jets.push_back(JetsLowestMjj[2]);
    Jets.push_back(JetsLowestMjj[3]);
  }
  if (kMode==kTwoJetPair_MwClosest_2ndHighestPt){
    Jets.push_back(JetsClosestMw[0]);
    Jets.push_back(JetsClosestMw[1]);
    Jets.push_back(JetsHighestPt[2]);
    Jets.push_back(JetsHighestPt[3]);
  }
  if (kMode==kThreeJets_MwClosest_HighestPt){
    Jets.push_back(JetsClosestMw[0]);
    Jets.push_back(JetsClosestMw[1]);
    Jets.push_back(JetsHighestPt[2]);
  }

  if (verbosity>=1) cout << "Using Jets mode "<<kMode<<endl;

  return;
}

void MultiLepton::SwitchJetSyst(int iperm_jsyst){

  //float pt, energy;
  for (unsigned int i=0; i<Bjets.size(); i++){
    //pt = Bjets[i].P4.Pt();
    //energy = Bjets[i].P4.E();
    if (iperm_jsyst==0) { Bjets[i].pt_ref = Bjets[i].P4.Pt(); Bjets[i].energy_ref = Bjets[i].P4.E(); };
    if (iperm_jsyst==1) Bjets[i].P4.SetPtEtaPhiE(Bjets[i].pt_ref*Bjets[i].JEC_Up/Bjets[i].energy_ref, Bjets[i].P4.Theta(), Bjets[i].P4.Phi(), Bjets[i].JEC_Up);
    if (iperm_jsyst==2) Bjets[i].P4.SetPtEtaPhiE(Bjets[i].pt_ref*Bjets[i].JEC_Down/Bjets[i].energy_ref, Bjets[i].P4.Theta(), Bjets[i].P4.Phi(), Bjets[i].JEC_Down);
    if (iperm_jsyst==3) Bjets[i].P4.SetPtEtaPhiE(Bjets[i].pt_ref*Bjets[i].JER_Up/Bjets[i].energy_ref, Bjets[i].P4.Theta(), Bjets[i].P4.Phi(), Bjets[i].JER_Up);
    if (iperm_jsyst==4) Bjets[i].P4.SetPtEtaPhiE(Bjets[i].pt_ref*Bjets[i].JER_Down/Bjets[i].energy_ref, Bjets[i].P4.Theta(), Bjets[i].P4.Phi(), Bjets[i].JER_Down);
  }

  for (unsigned int i=0; i<Jets.size(); i++){
    //pt = Jets[i].P4.Pt();
    //energy = Jets[i].P4.E();
    if (iperm_jsyst==0) { Jets[i].pt_ref = Jets[i].P4.Pt(); Jets[i].energy_ref = Jets[i].P4.E();};
    if (iperm_jsyst==1) Jets[i].P4.SetPtEtaPhiE(Jets[i].pt_ref*Jets[i].JEC_Up/Bjets[i].energy_ref, Jets[i].P4.Theta(), Jets[i].P4.Phi(), Jets[i].JEC_Up);
    if (iperm_jsyst==2) Jets[i].P4.SetPtEtaPhiE(Jets[i].pt_ref*Jets[i].JEC_Down/Bjets[i].energy_ref, Jets[i].P4.Theta(), Jets[i].P4.Phi(), Jets[i].JEC_Down);
    if (iperm_jsyst==3) Jets[i].P4.SetPtEtaPhiE(Jets[i].pt_ref*Jets[i].JER_Up/Bjets[i].energy_ref, Jets[i].P4.Theta(), Jets[i].P4.Phi(), Jets[i].JER_Up);
    if (iperm_jsyst==4) Jets[i].P4.SetPtEtaPhiE(Jets[i].pt_ref*Jets[i].JER_Down/Bjets[i].energy_ref, Jets[i].P4.Theta(), Jets[i].P4.Phi(), Jets[i].JER_Down);
  }

}

void MultiLepton::FillTTHFullyLepHyp(MEPhaseSpace** meIntegrator)
{

  if ((*meIntegrator)->iNleptons==3){

    (*meIntegrator)->FinalStateTTV.Boson_Type = kHfullylep;
    (*meIntegrator)->FinalStateTTV.Top1_Decay = kTopHadDecay;
    (*meIntegrator)->FinalStateTTV.Top1_Sign = (Leptons[2].Id>0)?kTop:kAntitop;
    (*meIntegrator)->FinalStateTTV.Top2_Decay = kTopLepDecay;
    (*meIntegrator)->FinalStateTTV.Top2_Sign = (Leptons[2].Id>0)?kAntitop:kTop;

    SetPresenceBandJets(meIntegrator, 0, 0);

    (*meIntegrator)->MEMFix_HiggsFullLep.Lep1_E = Leptons[0].P4.E();
    (*meIntegrator)->MEMFix_HiggsFullLep.Lep1_Theta = Leptons[0].P4.Theta();
    (*meIntegrator)->MEMFix_HiggsFullLep.Lep1_Phi = Leptons[0].P4.Phi();
    (*meIntegrator)->MEMFix_HiggsFullLep.Lep2_E = Leptons[1].P4.E();
    (*meIntegrator)->MEMFix_HiggsFullLep.Lep2_Theta = Leptons[1].P4.Theta();
    (*meIntegrator)->MEMFix_HiggsFullLep.Lep2_Phi = Leptons[1].P4.Phi();

    //(*meIntegrator)->MEMFix_TopHad.TopSign = (Leptons[2].Id>0)?-1:1;

    (*meIntegrator)->MEMFix_TopLep.Lep_E = Leptons[2].P4.E();
    (*meIntegrator)->MEMFix_TopLep.Lep_Theta = Leptons[2].P4.Theta();
    (*meIntegrator)->MEMFix_TopLep.Lep_Phi = Leptons[2].P4.Phi();
    //(*meIntegrator)->MEMFix_TopLep.TopSign = (Leptons[2].Id>0)?1:-1;

    int pos = 0;
    int numJet = 0;
    AddIntegrationBound_TopHad(meIntegrator, &pos, 0, &numJet, (*meIntegrator)->MEMFix_TopHad.isBmissing, (*meIntegrator)->MEMFix_TopHad.isJmissing);
    AddIntegrationBound_TopLep(meIntegrator, &pos, 1, 0, (*meIntegrator)->MEMFix_TopLep.isBmissing);
    AddIntegrationBound_HiggsFullyLep(meIntegrator, &pos);
  }
  if ((*meIntegrator)->iNleptons==4) {

    (*meIntegrator)->FinalStateTTV.Boson_Type = kHfullylep;
    (*meIntegrator)->FinalStateTTV.Top1_Decay = kTopLepDecay;
    (*meIntegrator)->FinalStateTTV.Top1_Sign = (Leptons[2].Id>0)?kAntitop:kTop;
    (*meIntegrator)->FinalStateTTV.Top2_Decay = kTopLepDecay;
    (*meIntegrator)->FinalStateTTV.Top2_Sign = (Leptons[3].Id>0)?kAntitop:kTop;

    SetPresenceBandJets(meIntegrator, 1, -1);

    (*meIntegrator)->MEMFix_HiggsFullLep.Lep1_E = Leptons[0].P4.E();
    (*meIntegrator)->MEMFix_HiggsFullLep.Lep1_Theta = Leptons[0].P4.Theta();
    (*meIntegrator)->MEMFix_HiggsFullLep.Lep1_Phi = Leptons[0].P4.Phi();
    (*meIntegrator)->MEMFix_HiggsFullLep.Lep2_E = Leptons[1].P4.E();
    (*meIntegrator)->MEMFix_HiggsFullLep.Lep2_Theta = Leptons[1].P4.Theta();
    (*meIntegrator)->MEMFix_HiggsFullLep.Lep2_Phi = Leptons[1].P4.Phi();
    (*meIntegrator)->MEMFix_HiggsFullLep.LepId=Leptons[0].Id;

    (*meIntegrator)->MEMFix_TopLep.Lep_E = Leptons[2].P4.E();
    (*meIntegrator)->MEMFix_TopLep.Lep_Theta = Leptons[2].P4.Theta();
    (*meIntegrator)->MEMFix_TopLep.Lep_Phi = Leptons[2].P4.Phi();
    //(*meIntegrator)->MEMFix_TopLep.TopSign = (Leptons[2].Id>0)?1:-1;

    (*meIntegrator)->MEMFix_TopLep2.Lep_E = Leptons[3].P4.E();
    (*meIntegrator)->MEMFix_TopLep2.Lep_Theta = Leptons[3].P4.Theta();
    (*meIntegrator)->MEMFix_TopLep2.Lep_Phi = Leptons[3].P4.Phi();
    //(*meIntegrator)->MEMFix_TopLep2.TopSign = (Leptons[3].Id>0)?1:-1;

    int pos = 0;
    AddIntegrationBound_TopLep(meIntegrator, &pos, 0, 0, (*meIntegrator)->MEMFix_TopLep.isBmissing);
    AddIntegrationBound_TopLep(meIntegrator, &pos, 1, 1, (*meIntegrator)->MEMFix_TopLep2.isBmissing);
    AddIntegrationBound_HiggsFullyLep(meIntegrator, &pos);
  }

  return;
}

void MultiLepton::FillTLLJHyp(MEPhaseSpace** meIntegrator)
{

  if ((*meIntegrator)->iNleptons==3){

    (*meIntegrator)->FinalStateTTV.Boson_Type = kLLJ;
    (*meIntegrator)->FinalStateTTV.Top1_Decay = kTopLepDecay;
    (*meIntegrator)->FinalStateTTV.Top1_Sign = (Leptons[2].Id>0)?kTop:kAntitop;
    (*meIntegrator)->FinalStateTTV.Top2_Decay = kNoTop;
    (*meIntegrator)->FinalStateTTV.Top2_Sign = kNoTop;

    SetPresenceBandJets(meIntegrator, -1, 0);

    (*meIntegrator)->MEMFix_HiggsFullLep.Lep1_E = Leptons[0].P4.E();
    (*meIntegrator)->MEMFix_HiggsFullLep.Lep1_Theta = Leptons[0].P4.Theta();
    (*meIntegrator)->MEMFix_HiggsFullLep.Lep1_Phi = Leptons[0].P4.Phi();
    (*meIntegrator)->MEMFix_HiggsFullLep.Lep2_E = Leptons[1].P4.E();
    (*meIntegrator)->MEMFix_HiggsFullLep.Lep2_Theta = Leptons[1].P4.Theta();
    (*meIntegrator)->MEMFix_HiggsFullLep.Lep2_Phi = Leptons[1].P4.Phi();

    (*meIntegrator)->MEMFix_TopLep.Lep_E = Leptons[2].P4.E();
    (*meIntegrator)->MEMFix_TopLep.Lep_Theta = Leptons[2].P4.Theta();
    (*meIntegrator)->MEMFix_TopLep.Lep_Phi = Leptons[2].P4.Phi();

    int pos = 0;
    AddIntegrationBound_TopLep(meIntegrator, &pos, 0, 0, (*meIntegrator)->MEMFix_TopLep.isBmissing);
    //AddIntegrationBound_HiggsFullyLep(meIntegrator, &pos);
    AddIntegrationBound_OneJet(meIntegrator, &pos, 0, (*meIntegrator)->MEMFix_OtherJets.isJmissing);
  }

}

void MultiLepton::FillTHJHyp(MEPhaseSpace** meIntegrator)
{

  if ((*meIntegrator)->iNleptons==3){

    (*meIntegrator)->FinalStateTTV.Boson_Type = kHfullylepJ;
    (*meIntegrator)->FinalStateTTV.Top1_Decay = kTopLepDecay;
    (*meIntegrator)->FinalStateTTV.Top1_Sign = (Leptons[2].Id>0)?kTop:kAntitop;
    (*meIntegrator)->FinalStateTTV.Top2_Decay = kNoTop;
    (*meIntegrator)->FinalStateTTV.Top2_Sign = kNoTop;

    SetPresenceBandJets(meIntegrator, -1, 0);

    (*meIntegrator)->MEMFix_HiggsFullLep.Lep1_E = Leptons[0].P4.E();
    (*meIntegrator)->MEMFix_HiggsFullLep.Lep1_Theta = Leptons[0].P4.Theta();
    (*meIntegrator)->MEMFix_HiggsFullLep.Lep1_Phi = Leptons[0].P4.Phi();
    (*meIntegrator)->MEMFix_HiggsFullLep.Lep2_E = Leptons[1].P4.E();
    (*meIntegrator)->MEMFix_HiggsFullLep.Lep2_Theta = Leptons[1].P4.Theta();
    (*meIntegrator)->MEMFix_HiggsFullLep.Lep2_Phi = Leptons[1].P4.Phi();

    (*meIntegrator)->MEMFix_TopLep.Lep_E = Leptons[2].P4.E();
    (*meIntegrator)->MEMFix_TopLep.Lep_Theta = Leptons[2].P4.Theta();
    (*meIntegrator)->MEMFix_TopLep.Lep_Phi = Leptons[2].P4.Phi();

    int pos = 0;
    AddIntegrationBound_TopLep(meIntegrator, &pos, 0, 0, (*meIntegrator)->MEMFix_TopLep.isBmissing);
    AddIntegrationBound_HiggsFullyLep(meIntegrator, &pos);
    AddIntegrationBound_OneJet(meIntegrator, &pos, 0, (*meIntegrator)->MEMFix_OtherJets.isJmissing);
  }

  if ((*meIntegrator)->iNleptons==2){

    (*meIntegrator)->FinalStateTTV.Boson_Type = kHsemilepJ;
    (*meIntegrator)->FinalStateTTV.Top1_Decay = kTopLepDecay;
    (*meIntegrator)->FinalStateTTV.Top1_Sign = (Leptons[1].Id>0)?kTop:kAntitop;
    (*meIntegrator)->FinalStateTTV.Top2_Decay = kNoTop;
    (*meIntegrator)->FinalStateTTV.Top2_Sign = kNoTop;

    SetPresenceBandJets(meIntegrator, -1, 1);

    (*meIntegrator)->MEMFix_HiggsSemiLep.Lep1_E = Leptons[0].P4.E();
    (*meIntegrator)->MEMFix_HiggsSemiLep.Lep1_Theta = Leptons[0].P4.Theta();
    (*meIntegrator)->MEMFix_HiggsSemiLep.Lep1_Phi = Leptons[0].P4.Phi();
    (*meIntegrator)->MEMFix_HiggsSemiLep.LepSign = (Leptons[0].Id>0)?1:-1;

    (*meIntegrator)->MEMFix_TopLep.Lep_E = Leptons[1].P4.E();
    (*meIntegrator)->MEMFix_TopLep.Lep_Theta = Leptons[1].P4.Theta();
    (*meIntegrator)->MEMFix_TopLep.Lep_Phi = Leptons[1].P4.Phi();

    int pos = 0;
    int numJet = 0;
    AddIntegrationBound_TopLep(meIntegrator, &pos, 0, 0, (*meIntegrator)->MEMFix_TopLep.isBmissing);
    AddIntegrationBound_HiggsSemiLep(meIntegrator, &pos, &numJet, (*meIntegrator)->MEMFix_HiggsSemiLep.isJmissing);
    AddIntegrationBound_OneJet(meIntegrator, &pos, numJet, (*meIntegrator)->MEMFix_OtherJets.isJmissing);

  }

}

void MultiLepton::FillWZJJHyp(MEPhaseSpace** meIntegrator)
{

  if ((*meIntegrator)->iNleptons==3){

    (*meIntegrator)->FinalStateTTV.Boson_Type = kLNuLLJJ;
    (*meIntegrator)->FinalStateTTV.Top1_Decay = kNoTop;
    (*meIntegrator)->FinalStateTTV.Top1_Sign = kNoTop;
    (*meIntegrator)->FinalStateTTV.Top2_Decay = kNoTop;
    (*meIntegrator)->FinalStateTTV.Top2_Sign = kNoTop;

    SetPresenceBandJets(meIntegrator, -2, 1);

    (*meIntegrator)->MEMFix_HiggsSemiLep.Lep1_E = Leptons[0].P4.E();
    (*meIntegrator)->MEMFix_HiggsSemiLep.Lep1_Theta = Leptons[0].P4.Theta();
    (*meIntegrator)->MEMFix_HiggsSemiLep.Lep1_Phi = Leptons[0].P4.Phi();
    (*meIntegrator)->MEMFix_HiggsSemiLep.LepSign = (Leptons[0].Id>0)?1:-1;

    (*meIntegrator)->MEMFix_HiggsFullLep.Lep1_E = Leptons[1].P4.E();
    (*meIntegrator)->MEMFix_HiggsFullLep.Lep1_Theta = Leptons[1].P4.Theta();
    (*meIntegrator)->MEMFix_HiggsFullLep.Lep1_Phi = Leptons[1].P4.Phi();
    (*meIntegrator)->MEMFix_HiggsFullLep.Lep2_E = Leptons[2].P4.E();
    (*meIntegrator)->MEMFix_HiggsFullLep.Lep2_Theta = Leptons[2].P4.Theta();
    (*meIntegrator)->MEMFix_HiggsFullLep.Lep2_Phi = Leptons[2].P4.Phi();

    int pos = 0;
    bool doTTWJJ = true;
    AddIntegrationBound_Woffshell(meIntegrator, &pos, 0, (*meIntegrator)->MEMFix_HiggsSemiLep.isJmissing, doTTWJJ);

  }
}

void MultiLepton::FillTTLLHyp(MEPhaseSpace** meIntegrator){

  FillTTHFullyLepHyp(meIntegrator);

  (*meIntegrator)->FinalStateTTV.Boson_Type = kLL;

  return;
}

void MultiLepton::FillTTHSemiLepHyp(MEPhaseSpace** meIntegrator)
{

  if ((*meIntegrator)->iNleptons==3){

    (*meIntegrator)->FinalStateTTV.Boson_Type = kHsemilep;
    (*meIntegrator)->FinalStateTTV.Top1_Decay = kTopLepDecay;
    (*meIntegrator)->FinalStateTTV.Top1_Sign = (Leptons[1].Id>0)?kAntitop:kTop;
    (*meIntegrator)->FinalStateTTV.Top2_Decay = kTopLepDecay;
    (*meIntegrator)->FinalStateTTV.Top2_Sign = (Leptons[2].Id>0)?kAntitop:kTop;

    SetPresenceBandJets(meIntegrator, 1, 1);

    (*meIntegrator)->MEMFix_HiggsSemiLep.Lep1_E = Leptons[0].P4.E();
    (*meIntegrator)->MEMFix_HiggsSemiLep.Lep1_Theta = Leptons[0].P4.Theta();
    (*meIntegrator)->MEMFix_HiggsSemiLep.Lep1_Phi = Leptons[0].P4.Phi();
    (*meIntegrator)->MEMFix_HiggsSemiLep.LepSign = (Leptons[0].Id>0)?1:-1;

    (*meIntegrator)->MEMFix_TopLep.Lep_E = Leptons[1].P4.E();
    (*meIntegrator)->MEMFix_TopLep.Lep_Theta = Leptons[1].P4.Theta();
    (*meIntegrator)->MEMFix_TopLep.Lep_Phi = Leptons[1].P4.Phi();
    //(*meIntegrator)->MEMFix_TopLep.TopSign = (Leptons[1].Id>0)?1:-1;

    (*meIntegrator)->MEMFix_TopLep2.Lep_E = Leptons[2].P4.E();
    (*meIntegrator)->MEMFix_TopLep2.Lep_Theta = Leptons[2].P4.Theta();
    (*meIntegrator)->MEMFix_TopLep2.Lep_Phi = Leptons[2].P4.Phi();
    //(*meIntegrator)->MEMFix_TopLep2.TopSign = (Leptons[2].Id>0)?1:-1;

    int pos = 0;
    int numJet = 0;
    AddIntegrationBound_TopLep(meIntegrator, &pos, 0, 0, (*meIntegrator)->MEMFix_TopLep.isBmissing);
    AddIntegrationBound_TopLep(meIntegrator, &pos, 1, 1, (*meIntegrator)->MEMFix_TopLep2.isBmissing);
    AddIntegrationBound_HiggsSemiLep(meIntegrator, &pos, &numJet, (*meIntegrator)->MEMFix_HiggsSemiLep.isJmissing);
  }
  if ((*meIntegrator)->iNleptons==2){

    (*meIntegrator)->FinalStateTTV.Boson_Type = kHsemilep;
    (*meIntegrator)->FinalStateTTV.Top1_Decay = kTopHadDecay;
    (*meIntegrator)->FinalStateTTV.Top1_Sign = (Leptons[1].Id>0)?kTop:kAntitop;
    (*meIntegrator)->FinalStateTTV.Top2_Decay = kTopLepDecay;
    (*meIntegrator)->FinalStateTTV.Top2_Sign = (Leptons[1].Id>0)?kAntitop:kTop;

    SetPresenceBandJets(meIntegrator, 0, 2);

    (*meIntegrator)->MEMFix_HiggsSemiLep.Lep1_E = Leptons[0].P4.E();
    (*meIntegrator)->MEMFix_HiggsSemiLep.Lep1_Theta = Leptons[0].P4.Theta();
    (*meIntegrator)->MEMFix_HiggsSemiLep.Lep1_Phi = Leptons[0].P4.Phi();
    (*meIntegrator)->MEMFix_HiggsSemiLep.LepSign = (Leptons[0].Id>0)?1:-1;

    (*meIntegrator)->MEMFix_TopLep.Lep_E = Leptons[1].P4.E();
    (*meIntegrator)->MEMFix_TopLep.Lep_Theta = Leptons[1].P4.Theta();
    (*meIntegrator)->MEMFix_TopLep.Lep_Phi = Leptons[1].P4.Phi();

    int pos = 0;
    int numJet = 0;
    AddIntegrationBound_TopHad(meIntegrator, &pos, 0, &numJet, (*meIntegrator)->MEMFix_TopHad.isBmissing, (*meIntegrator)->MEMFix_TopHad.isJmissing);
    AddIntegrationBound_TopLep(meIntegrator, &pos, 1, 0, (*meIntegrator)->MEMFix_TopLep.isBmissing);
    AddIntegrationBound_HiggsSemiLep(meIntegrator, &pos, &numJet, (*meIntegrator)->MEMFix_HiggsSemiLep.isJmissing);
  }


  return;
}

void MultiLepton::FillTTWHyp(MEPhaseSpace** meIntegrator, bool doTTWJJ)
{

  if (!doTTWJJ) (*meIntegrator)->FinalStateTTV.Boson_Type = kLNu;
  else if (doTTWJJ)  (*meIntegrator)->FinalStateTTV.Boson_Type = kLNuJJ;

  if ((*meIntegrator)->iNleptons==3){

    (*meIntegrator)->FinalStateTTV.Top1_Decay = kTopLepDecay;
    (*meIntegrator)->FinalStateTTV.Top1_Sign = (Leptons[1].Id>0)?kAntitop:kTop;
    (*meIntegrator)->FinalStateTTV.Top2_Decay = kTopLepDecay;
    (*meIntegrator)->FinalStateTTV.Top2_Sign = (Leptons[2].Id>0)?kAntitop:kTop;

    SetPresenceBandJets(meIntegrator, 1, 1);

    (*meIntegrator)->MEMFix_HiggsSemiLep.Lep1_E = Leptons[0].P4.E();
    (*meIntegrator)->MEMFix_HiggsSemiLep.Lep1_Theta = Leptons[0].P4.Theta();
    (*meIntegrator)->MEMFix_HiggsSemiLep.Lep1_Phi = Leptons[0].P4.Phi();
    (*meIntegrator)->MEMFix_HiggsSemiLep.LepSign = (Leptons[0].Id>0)?1:-1;

    (*meIntegrator)->MEMFix_TopLep.Lep_E = Leptons[1].P4.E();
    (*meIntegrator)->MEMFix_TopLep.Lep_Theta = Leptons[1].P4.Theta();
    (*meIntegrator)->MEMFix_TopLep.Lep_Phi = Leptons[1].P4.Phi();
    //(*meIntegrator)->MEMFix_TopLep.TopSign = (Leptons[1].Id>0)?1:-1;

    (*meIntegrator)->MEMFix_TopLep2.Lep_E = Leptons[2].P4.E();
    (*meIntegrator)->MEMFix_TopLep2.Lep_Theta = Leptons[2].P4.Theta();
    (*meIntegrator)->MEMFix_TopLep2.Lep_Phi = Leptons[2].P4.Phi();
    //(*meIntegrator)->MEMFix_TopLep2.TopSign = (Leptons[2].Id>0)?1:-1;

    int pos = 0;
    AddIntegrationBound_TopLep(meIntegrator, &pos, 0, 0, (*meIntegrator)->MEMFix_TopLep.isBmissing);
    AddIntegrationBound_TopLep(meIntegrator, &pos, 1, 1, (*meIntegrator)->MEMFix_TopLep2.isBmissing);
    AddIntegrationBound_Woffshell(meIntegrator, &pos, 0, (*meIntegrator)->MEMFix_HiggsSemiLep.isJmissing, doTTWJJ);
  }
  if ((*meIntegrator)->iNleptons==2){

    (*meIntegrator)->FinalStateTTV.Top1_Decay = kTopHadDecay;
    (*meIntegrator)->FinalStateTTV.Top1_Sign = (Leptons[1].Id>0)?kTop:kAntitop;
    (*meIntegrator)->FinalStateTTV.Top2_Decay = kTopLepDecay;
    (*meIntegrator)->FinalStateTTV.Top2_Sign = (Leptons[1].Id>0)?kAntitop:kTop;

    if (!doTTWJJ) {
      SetPresenceBandJets(meIntegrator, 0, 0); //Assumes TTW, not TTWJJ
      (*meIntegrator)->MEMFix_HiggsSemiLep.isJmissing = -1;
    }
    if (doTTWJJ) SetPresenceBandJets(meIntegrator, 0, 2);

    (*meIntegrator)->MEMFix_HiggsSemiLep.Lep1_E = Leptons[0].P4.E();
    (*meIntegrator)->MEMFix_HiggsSemiLep.Lep1_Theta = Leptons[0].P4.Theta();
    (*meIntegrator)->MEMFix_HiggsSemiLep.Lep1_Phi = Leptons[0].P4.Phi();
    (*meIntegrator)->MEMFix_HiggsSemiLep.LepSign = (Leptons[0].Id>0)?1:-1;

    (*meIntegrator)->MEMFix_TopLep.Lep_E = Leptons[1].P4.E();
    (*meIntegrator)->MEMFix_TopLep.Lep_Theta = Leptons[1].P4.Theta();
    (*meIntegrator)->MEMFix_TopLep.Lep_Phi = Leptons[1].P4.Phi();

    int pos = 0;
    int numJet = 0;
    AddIntegrationBound_TopHad(meIntegrator, &pos, 0, &numJet, (*meIntegrator)->MEMFix_TopHad.isBmissing, (*meIntegrator)->MEMFix_TopHad.isJmissing);
    AddIntegrationBound_TopLep(meIntegrator, &pos, 1, 0, (*meIntegrator)->MEMFix_TopLep.isBmissing);
    AddIntegrationBound_Woffshell(meIntegrator, &pos, numJet, (*meIntegrator)->MEMFix_HiggsSemiLep.isJmissing, doTTWJJ);
  }

  return;
}

void MultiLepton::FillTTbarSemiLepHyp(MEPhaseSpace** meIntegrator){

  if ((*meIntegrator)->iNleptons==3 || (*meIntegrator)->iNleptons==2){

    (*meIntegrator)->FinalStateTTV.Boson_Type = kNoBoson;
    (*meIntegrator)->FinalStateTTV.Top1_Decay = kTopHadDecay;
    (*meIntegrator)->FinalStateTTV.Top1_Sign = (Leptons[0].Id>0)?kTop:kAntitop;
    (*meIntegrator)->FinalStateTTV.Top2_Decay = kTopLepDecay;
    (*meIntegrator)->FinalStateTTV.Top2_Sign = (Leptons[0].Id>0)?kAntitop:kTop;

    SetPresenceBandJets(meIntegrator, 0, 0);

    //(*meIntegrator)->MEMFix_TopHad.TopSign = (Leptons[0].Id>0)?-1:1;

    (*meIntegrator)->MEMFix_TopLep.Lep_E = Leptons[0].P4.E();
    (*meIntegrator)->MEMFix_TopLep.Lep_Theta = Leptons[0].P4.Theta();
    (*meIntegrator)->MEMFix_TopLep.Lep_Phi = Leptons[0].P4.Phi();
    //(*meIntegrator)->MEMFix_TopLep.TopSign = (Leptons[0].Id>0)?1:-1;

    int numJet = 0;
    int pos = 0;
    AddIntegrationBound_TopHad(meIntegrator, &pos, 0, &numJet, (*meIntegrator)->MEMFix_TopHad.isBmissing, (*meIntegrator)->MEMFix_TopHad.isJmissing);
    AddIntegrationBound_TopLep(meIntegrator, &pos, 1, 0, (*meIntegrator)->MEMFix_TopLep.isBmissing);
  }

  return;
}

void MultiLepton::FillTTbarFullyLepHyp(MEPhaseSpace** meIntegrator){

  if ((*meIntegrator)->iNleptons==3 || (*meIntegrator)->iNleptons==4){

    (*meIntegrator)->FinalStateTTV.Boson_Type = kNoBoson;
    (*meIntegrator)->FinalStateTTV.Top1_Decay = kTopLepDecay;
    (*meIntegrator)->FinalStateTTV.Top1_Sign = (Leptons[0].Id>0)?kAntitop:kTop;
    (*meIntegrator)->FinalStateTTV.Top2_Decay = kTopLepDecay;
    (*meIntegrator)->FinalStateTTV.Top2_Sign = (Leptons[1].Id>0)?kAntitop:kTop;

    SetPresenceBandJets(meIntegrator, 1, -1);

    (*meIntegrator)->MEMFix_TopLep.Lep_E = Leptons[0].P4.E();
    (*meIntegrator)->MEMFix_TopLep.Lep_Theta = Leptons[0].P4.Theta();
    (*meIntegrator)->MEMFix_TopLep.Lep_Phi = Leptons[0].P4.Phi();
    (*meIntegrator)->MEMFix_TopLep.TopSign = (Leptons[0].Id>0)?1:-1;

    (*meIntegrator)->MEMFix_TopLep2.Lep_E = Leptons[1].P4.E();
    (*meIntegrator)->MEMFix_TopLep2.Lep_Theta = Leptons[1].P4.Theta();
    (*meIntegrator)->MEMFix_TopLep2.Lep_Phi = Leptons[1].P4.Phi();
    (*meIntegrator)->MEMFix_TopLep2.TopSign = (Leptons[1].Id>0)?1:-1;

    int pos = 0;
    AddIntegrationBound_TopLep(meIntegrator, &pos, 0, 0, (*meIntegrator)->MEMFix_TopLep.isBmissing);
    AddIntegrationBound_TopLep(meIntegrator, &pos, 1, 1, (*meIntegrator)->MEMFix_TopLep2.isBmissing);
  }

  return;
}

void MultiLepton::AddIntegrationBound_TopHad(MEPhaseSpace** meIntegrator, int* pos, int numTop, int* numJet, int isBmissing, int isJetMissing){

  if (verbosity>=1) cout << "TopHad numTop="<<numTop<< " numJet="<<*numJet<<" isBmissing="<<isBmissing<<" isJmissing="<<isJetMissing<<endl;

  if (isBmissing==kBjet_Present){ //had top is always first
    (*meIntegrator)->MEMFix_TopHad.Bjet_Theta = Bjets[0].P4.Theta();
    (*meIntegrator)->MEMFix_TopHad.Bjet_Phi = Bjets[0].P4.Phi();
    (*meIntegrator)->transferFunctions->MeasuredVarForTF.Bjet1_E =  Bjets[0].P4.E();
    (*meIntegrator)->transferFunctions->MeasuredVarForTF.Bjet1_Eta =  Bjets[0].P4.Eta();
    (*meIntegrator)->transferFunctions->MeasuredVarForTF.doBjet1TF = true;
  }
  if (isJetMissing==kJet_PresentBoth || isJetMissing==kJet_MissingSecond){ //fill first jet
    (*meIntegrator)->MEMFix_TopHad.Jet1_Theta = Jets[*numJet+0].P4.Theta();
    (*meIntegrator)->MEMFix_TopHad.Jet1_Phi = Jets[*numJet+0].P4.Phi();
    (*meIntegrator)->transferFunctions->MeasuredVarForTF.Jet1_E = Jets[*numJet+0].P4.E();
    (*meIntegrator)->transferFunctions->MeasuredVarForTF.Jet1_Eta = Jets[*numJet+0].P4.Eta();
    (*meIntegrator)->transferFunctions->MeasuredVarForTF.doJet1TF = true;
  }
  if (isJetMissing==kJet_PresentBoth){
    (*meIntegrator)->MEMFix_TopHad.Jet2_Theta = Jets[*numJet+1].P4.Theta();
    (*meIntegrator)->MEMFix_TopHad.Jet2_Phi = Jets[*numJet+1].P4.Phi();
    (*meIntegrator)->transferFunctions->MeasuredVarForTF.Jet2_E = Jets[*numJet+1].P4.E();
    (*meIntegrator)->transferFunctions->MeasuredVarForTF.Jet2_Eta = Jets[*numJet+1].P4.Eta();
    (*meIntegrator)->transferFunctions->MeasuredVarForTF.doJet2TF = true;
  }
  else if (isJetMissing==kJet_MissingFirst){
    (*meIntegrator)->MEMFix_TopHad.Jet2_Theta = Jets[*numJet+0].P4.Theta();
    (*meIntegrator)->MEMFix_TopHad.Jet2_Phi = Jets[*numJet+0].P4.Phi();
    (*meIntegrator)->transferFunctions->MeasuredVarForTF.Jet2_E = Jets[*numJet+0].P4.E();
    (*meIntegrator)->transferFunctions->MeasuredVarForTF.Jet2_Eta = Jets[*numJet+0].P4.Eta();
    (*meIntegrator)->transferFunctions->MeasuredVarForTF.doJet2TF = true;
  }

  if ((*meIntegrator)->iOptim == kOptimizeNone || (*meIntegrator)->iOptimTopHad == kOptimizeNone){
    if (isBmissing==kBjet_Present){
      xL[*pos+0] = (Bjets[numTop].P4.E()*JetTFfracmin<mB)?mB:Bjets[numTop].P4.E()*JetTFfracmin; //TopHad, Bjet_E
      xU[*pos+0] = JetTFfracmax*Bjets[numTop].P4.E();//meIntegrator->comEnergy; //TopHad, Bjet_E
      *pos += 1;
    }
    else if (isBmissing==kBjet_Missing){
      xL[*pos+0] = mB;
      xL[*pos+1] = 0; //TopHad, Neut_Theta
      xL[*pos+2] = 0; //TopHad, Neut_Phi
      xU[*pos+0] = MissingBMaxE;
      xU[*pos+1] = TMath::Pi(); //TopHad, MissingB_Theta
      xU[*pos+2] = 2.*TMath::Pi(); //TopHad, MissingB_Phi
      *pos += 3;
    }
    if (isJetMissing==kJet_PresentBoth || isJetMissing==kJet_MissingSecond){
      xL[*pos] = Jets[*numJet+0].P4.E()*JetTFfracmin; //TopHad, Jet1_E
      xU[*pos] = Jets[*numJet+0].P4.E()*JetTFfracmax; //TopHad, Jet1_E
      *pos += 1;
    }
    if (isJetMissing==kJet_MissingFirst || isJetMissing==kJet_MissingBoth){
      xL[*pos] = 0;
      xL[*pos+1] = 0;
      xL[*pos+2] = 0;
      xU[*pos] = MissingJetMaxE;
      xU[*pos+1] = TMath::Pi();
      xU[*pos+2] = 2.*TMath::Pi();
      *pos += 3;
    }
    if (isJetMissing==kJet_MissingSecond || isJetMissing==kJet_MissingBoth){
      xL[*pos] = 0;
      xL[*pos+1] = 0;
      xU[*pos] = TMath::Pi();
      xU[*pos+1] = 2.*TMath::Pi();
      *pos += 2;
    }
  }

  if ((*meIntegrator)->iOptim == kOptimizeMw || (*meIntegrator)->iOptimTopHad == kOptimizeTopHadTw){
    if (isBmissing==kBjet_Present){
      xL[*pos+0] = (Bjets[numTop].P4.E()*JetTFfracmin<mB)?mB:Bjets[numTop].P4.E()*JetTFfracmin; //TopHad, Bjet_E
      xU[*pos+0] = JetTFfracmax*Bjets[numTop].P4.E(); //TopHad, Bjet_E
      *pos += 1;
    }
    else if (isBmissing==kBjet_Missing){
      xL[*pos+0] = mB;
      xL[*pos+1] = 0; //TopHad, Neut_Theta
      xL[*pos+2] = 0; //TopHad, Neut_Phi

      xU[*pos+0] = MissingBMaxE;
      xU[*pos+1] = TMath::Pi(); //TopHad, MissingB_Theta
      xU[*pos+2] = 2.*TMath::Pi(); //TopHad, MissingB_Phi
      *pos += 3;
    }
    if (isJetMissing==kJet_MissingSecond || isJetMissing==kJet_MissingBoth){
      xL[*pos+0] = 0; //TopHad, MissingJet_Theta
      xL[*pos+1] = 0; //TopHad, MissingJet_Phi
      xU[*pos+0] = TMath::Pi(); //TopHad, MissingJet_Theta
      xU[*pos+1] = 2.*TMath::Pi();//TopHad, MissingJet_Phi
      *pos += 2;
    }
    if (isJetMissing==kJet_MissingFirst || isJetMissing==kJet_MissingBoth){
      xL[*pos+0] = 0; //TopHad, MissingJet_Theta
      xL[*pos+1] = 0; //TopHad, MissingJet_Phi
      xU[*pos+0] = TMath::Pi(); //TopHad, MissingJet_Theta
      xU[*pos+1] = 2.*TMath::Pi();//TopHad, MissingJet_Phi
      *pos += 2;
    }
    xL[*pos] = tWmin; //TopHad, tW
    xU[*pos] = tWmaxTop; //TopHad, tW
    *pos += 1;
  }

  if (isJetMissing==kJet_PresentBoth) *numJet += 2;
  if (isJetMissing==kJet_MissingFirst || isJetMissing==kJet_MissingSecond) *numJet += 1;
  if (isJetMissing==kJet_MissingBoth) *numJet += 0;

}

void MultiLepton::AddIntegrationBound_TopLep(MEPhaseSpace** meIntegrator, int *pos, int numTop, int numTopLep, int isBmissing){

  if (verbosity>=1) cout << "TopLep numTop="<<numTop<<" numTopLep="<<numTopLep<<" isBmissing="<<isBmissing<<endl;

  int iBjet = 0;
  //if ((*meIntegrator)->MEMFix_TopLep.isBmissing==kBjet_Present && numTopLep==0 && numTop==0) iBjet = 0;
  if ((*meIntegrator)->MEMFix_TopHad.isBmissing==kBjet_Present && numTopLep==0 && numTop==1) iBjet = 1;
  if ((*meIntegrator)->MEMFix_TopLep.isBmissing==kBjet_Present && numTopLep==1 && numTop==1) iBjet = 1;
  //if ((*meIntegrator)->MEMFix_TopLep.isBmissing==kBjet_Missing && numTopLep==1) iBjet = 0;

  if (isBmissing==kBjet_Present){
    if (numTopLep==0){
      (*meIntegrator)->MEMFix_TopLep.Bjet_Theta = Bjets[iBjet].P4.Theta();
      (*meIntegrator)->MEMFix_TopLep.Bjet_Phi = Bjets[iBjet].P4.Phi();
    }
    else if (numTopLep==1){
      (*meIntegrator)->MEMFix_TopLep2.Bjet_Theta = Bjets[iBjet].P4.Theta();
      (*meIntegrator)->MEMFix_TopLep2.Bjet_Phi = Bjets[iBjet].P4.Phi();
    }
    if (numTop==0){
      (*meIntegrator)->transferFunctions->MeasuredVarForTF.Bjet1_E =  Bjets[iBjet].P4.E();
      (*meIntegrator)->transferFunctions->MeasuredVarForTF.Bjet1_Eta =  Bjets[iBjet].P4.Eta();
      (*meIntegrator)->transferFunctions->MeasuredVarForTF.doBjet1TF = true;
    }
    else if (numTop==1){
      (*meIntegrator)->transferFunctions->MeasuredVarForTF.Bjet2_E =  Bjets[iBjet].P4.E();
      (*meIntegrator)->transferFunctions->MeasuredVarForTF.Bjet2_Eta =  Bjets[iBjet].P4.Eta();
      (*meIntegrator)->transferFunctions->MeasuredVarForTF.doBjet2TF = true;
    }
  }

  if ((*meIntegrator)->iOptim == kOptimizeNone || (*meIntegrator)->iOptimTopLep == kOptimizeNone){
    if (isBmissing==kBjet_Present){
      xL[*pos+0] = (Bjets[iBjet].P4.E()*JetTFfracmin<mB)?mB:Bjets[iBjet].P4.E()*JetTFfracmin; //TopLep, Bjet_E
      xL[*pos+1] = 0; //TopLep, Neut_Theta
      xL[*pos+2] = 0; //TopLep, Neut_Phi

      xU[*pos+0] = JetTFfracmax*Bjets[iBjet].P4.E();//meIntegrator->comEnergy; //TopLep, Bjet_E
      xU[*pos+1] = TMath::Pi(); //TopLep, Neut_Theta
      xU[*pos+2] = 2.*TMath::Pi(); //TopLep, Neut_Phi
      *pos += 3;
    }
    else if (isBmissing==kBjet_Missing){
      xL[*pos+0] = mB;
      xL[*pos+1] = 0; //TopLep MissingB_Theta
      xL[*pos+2] = 0; //TopLep MissingB_Phi
      xL[*pos+3] = 0; //TopLep, Neut_Theta
      xL[*pos+4] = 0; //TopLep, Neut_Phi

      xU[*pos+0] = MissingBMaxE;
      xU[*pos+1] = TMath::Pi(); //TopLep, MissingB_Theta
      xU[*pos+2] = 2.*TMath::Pi(); //TopLep, MissingB_Phi
      xU[*pos+3] = TMath::Pi(); //TopLep, Neut_Theta
      xU[*pos+4] = 2.*TMath::Pi(); //TopLep, Neut_Phi
      *pos += 5;
    }
  }

  if ((*meIntegrator)->iOptim == kOptimizeMw || (*meIntegrator)->iOptimTopLep == kOptimizeTopLepTw){
    if (isBmissing==kBjet_Present){
      xL[*pos+0] = (Bjets[iBjet].P4.E()*JetTFfracmin<mB)?mB:Bjets[iBjet].P4.E()*JetTFfracmin; //TopLep, Bjet_E
      xL[*pos+1] = 0; //TopLep, Neut_Phi
      xL[*pos+2] = tWmin; //TopLep, tW

      xU[*pos+0] = JetTFfracmax*Bjets[iBjet].P4.E(); //TopLep, Bjet_E
      xU[*pos+1] = 2.*TMath::Pi(); //TopLep, Neut_Phi
      xU[*pos+2] = tWmaxTop; //TopLep, tW
      *pos += 3;
    }
    else if (isBmissing==kBjet_Missing){
      xL[*pos+0] = mB;
      xL[*pos+1] = 0; //TopLep MissingB_Theta
      xL[*pos+2] = 0; //TopLep MissingB_Phi
      xL[*pos+3] = 0; //TopLep, Neut_Phi
      xL[*pos+4] = tWmin; //TopLep, tW

      xU[*pos+0] = MissingBMaxE;
      xU[*pos+1] = TMath::Pi(); //TopLep, MissingB_Theta
      xU[*pos+2] = 2.*TMath::Pi(); //TopLep, MissingB_Phi
      xU[*pos+3] = 2.*TMath::Pi(); //TopLep, Neut_Phi
      xU[*pos+4] = tWmaxTop; //TopLep, tW
      *pos += 5;
    }
  }

  return;
}

void MultiLepton::AddIntegrationBound_HiggsFullyLep(MEPhaseSpace** meIntegrator, int* pos){

  if (verbosity>=1) cout << "HiggsFullyLep"<<endl;

  if ((*meIntegrator)->iOptim == kOptimizeNone || (*meIntegrator)->iOptimHiggs==kOptimizeNone){
    xL[*pos+0] = 0; //HiggsFullLep, Neut1_E
    xL[*pos+1] = 0; //HiggsFullLep, Neut1_Theta
    xL[*pos+2] = 0; //HiggsFullLep, Neut1_Phi
    xL[*pos+3] = 0; //HiggsFullLep, Neut2_Theta
    xL[*pos+4] = 0; //HiggsFullLep, Neut2_Phi

    xU[*pos+0] = NeutMaxE;//meIntegrator->comEnergy; //HiggsFullLep, Neut1_E
    xU[*pos+1] = TMath::Pi(); //HiggsFullLep, Neut1_Theta
    xU[*pos+2] = 2*TMath::Pi(); //HiggsFullLep, Neut1_Phi
    xU[*pos+3] = TMath::Pi(); //HiggsFullLep, Neut2_Theta
    xU[*pos+4] = 2*TMath::Pi(); //HiggsFullLep, Neut2_Phi
  }
  if ((*meIntegrator)->iOptim == kOptimizeMw || (*meIntegrator)->iOptimHiggs ==kOptimizeHiggsMw || (*meIntegrator)->iOptimHiggs ==kOptimizeHiggsTw){

    xL[*pos+0] = 0; //HiggsFullLep, Neut1_E
    xL[*pos+1] = 0; //HiggsFullLep, Neut1_Theta
    xL[*pos+2] = 0; //HiggsFullLep, Neut1_Phi
    xL[*pos+3] = 0; //HiggsFullLep, Neut2_Phi
    if ((*meIntegrator)->iOptim == kOptimizeMw || (*meIntegrator)->iOptimHiggs ==kOptimizeHiggsTw) xL[*pos+4] = tWmin; //HiggsFullLep, tW2
    if ((*meIntegrator)->iOptimHiggs ==kOptimizeHiggsMw) xL[*pos+4] = 0;

    xU[*pos+0] = NeutMaxE; //HiggsFullLep, Neut1_E
    xU[*pos+1] = TMath::Pi(); //HiggsFullLep, Neut1_Theta
    xU[*pos+2] = 2*TMath::Pi(); //HiggsFullLep, Neut1_Phi
    xU[*pos+3] = 2*TMath::Pi(); //HiggsFullLep, Neut2_Phi
    if ((*meIntegrator)->iOptim == kOptimizeMw || (*meIntegrator)->iOptimHiggs ==kOptimizeHiggsTw) xU[*pos+4] = tWmaxHiggs; //HiggsFullLep, tW2
    if ((*meIntegrator)->iOptimHiggs ==kOptimizeHiggsMw) xU[*pos+4] = 125.;
  }

  *pos += 5;
}

void MultiLepton::AddIntegrationBound_HiggsSemiLep(MEPhaseSpace** meIntegrator, int* pos, int *numJets, int isJetMissing){

  if (verbosity>=1) cout << "HiggsSemiLep numJets=" << *numJets<<" isJmissing="<<isJetMissing<<endl;

  if ((*meIntegrator)->FinalStateTTV.Top1_Decay != kTopHadDecay){
    if (isJetMissing==kJet_PresentBoth || isJetMissing==kJet_MissingSecond){ //fill first jet
      (*meIntegrator)->MEMFix_HiggsSemiLep.Jet1_Theta = Jets[*numJets+0].P4.Theta();
      (*meIntegrator)->MEMFix_HiggsSemiLep.Jet1_Phi = Jets[*numJets+0].P4.Phi();
      (*meIntegrator)->transferFunctions->MeasuredVarForTF.Jet1_E = Jets[*numJets+0].P4.E();
      (*meIntegrator)->transferFunctions->MeasuredVarForTF.Jet1_Eta = Jets[*numJets+0].P4.Eta();
      (*meIntegrator)->transferFunctions->MeasuredVarForTF.doJet1TF = true;
    }
    if (isJetMissing==kJet_PresentBoth){
      (*meIntegrator)->MEMFix_HiggsSemiLep.Jet2_Theta = Jets[*numJets+1].P4.Theta();
      (*meIntegrator)->MEMFix_HiggsSemiLep.Jet2_Phi = Jets[*numJets+1].P4.Phi();
      (*meIntegrator)->transferFunctions->MeasuredVarForTF.Jet2_E = Jets[*numJets+1].P4.E();
      (*meIntegrator)->transferFunctions->MeasuredVarForTF.Jet2_Eta = Jets[*numJets+1].P4.Eta();
      (*meIntegrator)->transferFunctions->MeasuredVarForTF.doJet2TF = true;
    }
    else if (isJetMissing==kJet_MissingFirst){
      (*meIntegrator)->MEMFix_HiggsSemiLep.Jet2_Theta = Jets[*numJets+0].P4.Theta();
      (*meIntegrator)->MEMFix_HiggsSemiLep.Jet2_Phi = Jets[*numJets+0].P4.Phi();
      (*meIntegrator)->transferFunctions->MeasuredVarForTF.Jet2_E = Jets[*numJets+0].P4.E();
      (*meIntegrator)->transferFunctions->MeasuredVarForTF.Jet2_Eta = Jets[*numJets+0].P4.Eta();
      (*meIntegrator)->transferFunctions->MeasuredVarForTF.doJet2TF = true;
    }
  }
  else if ((*meIntegrator)->FinalStateTTV.Top1_Decay == kTopHadDecay){
    if (isJetMissing==kJet_PresentBoth || isJetMissing==kJet_MissingSecond){ //fill first jet
      (*meIntegrator)->MEMFix_HiggsSemiLep.Jet1_Theta = Jets[*numJets+0].P4.Theta();
      (*meIntegrator)->MEMFix_HiggsSemiLep.Jet1_Phi = Jets[*numJets+0].P4.Phi();
      (*meIntegrator)->transferFunctions->MeasuredVarForTF.Jet3_E = Jets[*numJets+0].P4.E();
      (*meIntegrator)->transferFunctions->MeasuredVarForTF.Jet3_Eta = Jets[*numJets+0].P4.Eta();
      (*meIntegrator)->transferFunctions->MeasuredVarForTF.doJet3TF = true;
    }
    if (isJetMissing==kJet_PresentBoth){
      (*meIntegrator)->MEMFix_HiggsSemiLep.Jet2_Theta = Jets[*numJets+1].P4.Theta();
      (*meIntegrator)->MEMFix_HiggsSemiLep.Jet2_Phi = Jets[*numJets+1].P4.Phi();
      (*meIntegrator)->transferFunctions->MeasuredVarForTF.Jet4_E = Jets[*numJets+1].P4.E();
      (*meIntegrator)->transferFunctions->MeasuredVarForTF.Jet4_Eta = Jets[*numJets+1].P4.Eta();
      (*meIntegrator)->transferFunctions->MeasuredVarForTF.doJet4TF = true;
    }
    else if (isJetMissing==kJet_MissingFirst){
      (*meIntegrator)->MEMFix_HiggsSemiLep.Jet2_Theta = Jets[*numJets+0].P4.Theta();
      (*meIntegrator)->MEMFix_HiggsSemiLep.Jet2_Phi = Jets[*numJets+0].P4.Phi();
      (*meIntegrator)->transferFunctions->MeasuredVarForTF.Jet4_E = Jets[*numJets+0].P4.E();
      (*meIntegrator)->transferFunctions->MeasuredVarForTF.Jet4_Eta = Jets[*numJets+0].P4.Eta();
      (*meIntegrator)->transferFunctions->MeasuredVarForTF.doJet4TF = true;
    }
  }


  if ((*meIntegrator)->iOptim == kOptimizeNone || (*meIntegrator)->iOptimHiggs==kOptimizeNone){
    xL[*pos+0] = 0; //HiggsSemiLep, Neut_Theta
    xL[*pos+1] = 0; //HiggsSemiLep, Neut_Phi
    xU[*pos+0] = TMath::Pi(); //HiggsSemiLep, Neut_Theta
    xU[*pos+1] = 2*TMath::Pi(); //HiggsSemiLep, Neut_Phi
    *pos += 2;
    if (isJetMissing==kJet_PresentBoth || isJetMissing==kJet_MissingSecond){
      xL[*pos] = Jets[*numJets+0].P4.E()*JetTFfracmin; //HiggsSemiLep, Jet1_E
      xU[*pos] = JetTFfracmax*Jets[*numJets+0].P4.E();//meIntegrator->comEnergy; //HiggsSemiLep, Jet1_E
      *pos += 1;
    }
    if (isJetMissing==kJet_MissingFirst || isJetMissing==kJet_MissingBoth){
      xL[*pos+0] = 0;
      xL[*pos+1] = 0;
      xL[*pos+2] = 0;
      xU[*pos+0] = MissingJetMaxE;
      xU[*pos+1] = TMath::Pi();
      xU[*pos+2] = 2*TMath::Pi();
      *pos += 3;
    }
    if (isJetMissing==kJet_PresentBoth || isJetMissing==kJet_MissingFirst){
      if (isJetMissing==kJet_PresentBoth){
        xL[*pos] = Jets[*numJets+1].P4.E()*JetTFfracmin; //HiggsSemiLep, Jet2_E
        xU[*pos] = JetTFfracmax*Jets[*numJets+1].P4.E();//meIntegrator->comEnergy //HiggsSemiLep, Jet2_E
        *pos += 1;
      }
      else if (isJetMissing==kJet_MissingFirst){
        xL[*pos] = Jets[*numJets+0].P4.E()*JetTFfracmin; //HiggsSemiLep, Jet2_E
        xU[*pos] = JetTFfracmax*Jets[*numJets+0].P4.E();//meIntegrator->comEnergy //HiggsSemiLep, Jet2_E
        *pos += 1;
      }
    }
    if (isJetMissing==kJet_MissingSecond || isJetMissing==kJet_MissingBoth){
      xL[*pos+0] = 0;
      xL[*pos+1] = 0;
      xL[*pos+2] = 0;
      xU[*pos+0] = MissingJetMaxE;
      xU[*pos+1] = TMath::Pi();
      xU[*pos+2] = 2*TMath::Pi();
      *pos += 3;
    }
  }

  if ((*meIntegrator)->iOptim == kOptimizeMw || (*meIntegrator)->iOptimHiggs ==kOptimizeHiggsMw || (*meIntegrator)->iOptimHiggs ==kOptimizeHiggsTw){

    xL[*pos+0] = 0; //HiggsSemiLep, Neut_Phi
    if ((*meIntegrator)->iOptim == kOptimizeMw || (*meIntegrator)->iOptimHiggs ==kOptimizeHiggsTw) xL[*pos+1] = tWmin; //HiggsSemiLep, tW2
    if ((*meIntegrator)->iOptimHiggs ==kOptimizeHiggsMw) xL[*pos+1] = 0;

    xU[*pos+0] = 2*TMath::Pi(); //HiggsSemiLep, Neut_Phi
    if ((*meIntegrator)->iOptim == kOptimizeMw || (*meIntegrator)->iOptimHiggs ==kOptimizeHiggsTw) xU[*pos+1] = tWmaxHiggs; //HiggsSemiLep, tW2
    if ((*meIntegrator)->iOptimHiggs ==kOptimizeHiggsMw) xU[*pos+1] = 125.;
    *pos += 2;

    if (isJetMissing==kJet_PresentBoth || isJetMissing==kJet_MissingSecond){
      xL[*pos] = Jets[*numJets+0].P4.E()*JetTFfracmin; //HiggsSemiLep, Jet1_E
      xU[*pos] = JetTFfracmax*Jets[*numJets+0].P4.E();//meIntegrator->comEnergy; //HiggsSemiLep, Jet1_E
      *pos += 1;
    }
    if (isJetMissing==kJet_MissingFirst || isJetMissing==kJet_MissingBoth){
      xL[*pos+0] = 0;
      xL[*pos+1] = 0;
      xL[*pos+2] = 0;
      xU[*pos+0] = MissingJetMaxE;
      xU[*pos+1] = TMath::Pi();
      xU[*pos+2] = 2*TMath::Pi();
      *pos += 3;
    }
    if (isJetMissing==kJet_PresentBoth || isJetMissing==kJet_MissingFirst){
      if (isJetMissing==kJet_PresentBoth){
        xL[*pos] = Jets[*numJets+1].P4.E()*JetTFfracmin; //HiggsSemiLep, Jet2_E
        xU[*pos] = JetTFfracmax*Jets[*numJets+1].P4.E();//meIntegrator->comEnergy //HiggsSemiLep, Jet2_E
        *pos += 1;
      }
      else if (isJetMissing==kJet_MissingFirst){
        xL[*pos] = Jets[*numJets+0].P4.E()*JetTFfracmin; //HiggsSemiLep, Jet2_E
        xU[*pos] = JetTFfracmax*Jets[*numJets+0].P4.E();//meIntegrator->comEnergy //HiggsSemiLep, Jet2_E
        *pos += 1;
      }
    }
    if (isJetMissing==kJet_MissingSecond || isJetMissing==kJet_MissingBoth){
      xL[*pos+0] = 0;
      xL[*pos+1] = 0;
      xL[*pos+2] = 0;
      xU[*pos+0] = MissingJetMaxE;
      xU[*pos+1] = TMath::Pi();
      xU[*pos+2] = 2*TMath::Pi();
      *pos += 3;
    }
  }

  if (isJetMissing==kJet_PresentBoth) *numJets += 2;
  if (isJetMissing==kJet_MissingFirst || isJetMissing==kJet_MissingSecond) *numJets += 1;
  if (isJetMissing==kJet_MissingBoth) *numJets += 0;

  return;
}

void MultiLepton::AddIntegrationBound_Woffshell(MEPhaseSpace** meIntegrator, int* pos, int numJets, int isJetMissing, bool doTTWJJ){

  if (verbosity>=1) cout << "Woffshell numJets="<<numJets<<" isJetMissing="<<isJetMissing<<" doTTWJJ="<<doTTWJJ<<endl;

  if (doTTWJJ && (*meIntegrator)->FinalStateTTV.Top1_Decay != kTopHadDecay){
    if (isJetMissing==kJet_PresentBoth || isJetMissing==kJet_MissingSecond){ //fill first jet
      (*meIntegrator)->MEMFix_HiggsSemiLep.Jet1_Theta = Jets[numJets+0].P4.Theta();
      (*meIntegrator)->MEMFix_HiggsSemiLep.Jet1_Phi = Jets[numJets+0].P4.Phi();
      (*meIntegrator)->transferFunctions->MeasuredVarForTF.Jet1_E = Jets[numJets+0].P4.E();
      (*meIntegrator)->transferFunctions->MeasuredVarForTF.Jet1_Eta = Jets[numJets+0].P4.Eta();
      (*meIntegrator)->transferFunctions->MeasuredVarForTF.doJet1TF = true;
    }
    if (isJetMissing==kJet_PresentBoth){
      (*meIntegrator)->MEMFix_HiggsSemiLep.Jet2_Theta = Jets[numJets+1].P4.Theta();
      (*meIntegrator)->MEMFix_HiggsSemiLep.Jet2_Phi = Jets[numJets+1].P4.Phi();
      (*meIntegrator)->transferFunctions->MeasuredVarForTF.Jet2_E = Jets[numJets+1].P4.E();
      (*meIntegrator)->transferFunctions->MeasuredVarForTF.Jet2_Eta = Jets[numJets+1].P4.Eta();
      (*meIntegrator)->transferFunctions->MeasuredVarForTF.doJet2TF = true;
    }
    else if (isJetMissing==kJet_MissingFirst){
      (*meIntegrator)->MEMFix_HiggsSemiLep.Jet2_Theta = Jets[numJets+0].P4.Theta();
      (*meIntegrator)->MEMFix_HiggsSemiLep.Jet2_Phi = Jets[numJets+0].P4.Phi();
      (*meIntegrator)->transferFunctions->MeasuredVarForTF.Jet2_E = Jets[numJets+0].P4.E();
      (*meIntegrator)->transferFunctions->MeasuredVarForTF.Jet2_Eta = Jets[numJets+0].P4.Eta();
      (*meIntegrator)->transferFunctions->MeasuredVarForTF.doJet2TF = true;
    }
  }
  else if (doTTWJJ && (*meIntegrator)->FinalStateTTV.Top1_Decay == kTopHadDecay) {
    if (isJetMissing==kJet_PresentBoth || isJetMissing==kJet_MissingSecond){ //fill first jet
      (*meIntegrator)->MEMFix_HiggsSemiLep.Jet1_Theta = Jets[numJets+0].P4.Theta();
      (*meIntegrator)->MEMFix_HiggsSemiLep.Jet1_Phi = Jets[numJets+0].P4.Phi();
      (*meIntegrator)->transferFunctions->MeasuredVarForTF.Jet3_E = Jets[numJets+0].P4.E();
      (*meIntegrator)->transferFunctions->MeasuredVarForTF.Jet3_Eta = Jets[numJets+0].P4.Eta();
      (*meIntegrator)->transferFunctions->MeasuredVarForTF.doJet3TF = true;
    }
    if (isJetMissing==kJet_PresentBoth){
      (*meIntegrator)->MEMFix_HiggsSemiLep.Jet2_Theta = Jets[numJets+1].P4.Theta();
      (*meIntegrator)->MEMFix_HiggsSemiLep.Jet2_Phi = Jets[numJets+1].P4.Phi();
      (*meIntegrator)->transferFunctions->MeasuredVarForTF.Jet4_E = Jets[numJets+1].P4.E();
      (*meIntegrator)->transferFunctions->MeasuredVarForTF.Jet4_Eta = Jets[numJets+1].P4.Eta();
      (*meIntegrator)->transferFunctions->MeasuredVarForTF.doJet4TF = true;
    }
    else if (isJetMissing==kJet_MissingFirst){
      (*meIntegrator)->MEMFix_HiggsSemiLep.Jet2_Theta = Jets[numJets+0].P4.Theta();
      (*meIntegrator)->MEMFix_HiggsSemiLep.Jet2_Phi = Jets[numJets+0].P4.Phi();
      (*meIntegrator)->transferFunctions->MeasuredVarForTF.Jet4_E = Jets[numJets+0].P4.E();
      (*meIntegrator)->transferFunctions->MeasuredVarForTF.Jet4_Eta = Jets[numJets+0].P4.Eta();
      (*meIntegrator)->transferFunctions->MeasuredVarForTF.doJet4TF = true;
    }
  }


  if ((*meIntegrator)->iOptim == kOptimizeNone || (*meIntegrator)->iOptimW==kOptimizeNone){
    xL[*pos+0] = 0;//(74.-Leptons[0].P4.E()>0)?(74.-Leptons[0].P4.E()):0; //HiggsSemiLep, Neut_E
    xL[*pos+1] = 0; //HiggsSemiLep, Neut_Theta
    xL[*pos+2] = 0; //HiggsSemiLep, Neut_Phi
    //xL[*pos+3] = Jets[numJets].P4.E()*JetTFfracmin; //Jet1_E
    //xL[*pos+4] = Jets[numJets].P4.E()*JetTFfracmin; //Jet2_E

    xU[*pos+0] = NeutMaxE; //HiggsSemiLep, Neut_E
    xU[*pos+1] = TMath::Pi(); //HiggsSemiLep, Neut_Theta
    xU[*pos+2] = 2*TMath::Pi();//HiggsSemiLep, Neut_Phi
    //xU[*pos+3] = JetTFfracmax*Jets[numJets].P4.E(); //Jet1_E
    //xU[*pos+4] = JetTFfracmax*Jets[numJets].P4.E(); //Jet2_E
    *pos += 3;
  }
  if ((*meIntegrator)->iOptim == kOptimizeMw || (*meIntegrator)->iOptimW==kOptimizeWTw){
    xL[*pos+0] = 0; //HiggsSemiLep, Neut_Theta
    xL[*pos+1] = 0; //HiggsSemiLep, Neut_Phi
    xL[*pos+2] = tWmin;//HiggsSemiLep, tW
    //xU[*pos+3] = JetTFfracmin*Jets[numJets].P4.E(); //Jet1_E
    //xU[*pos+4] = JetTFfracmin*Jets[numJets].P4.E(); //Jet2_E

    xU[*pos+0] = TMath::Pi(); //HiggsSemiLep, Neut_Theta
    xU[*pos+1] = 2*TMath::Pi(); //HiggsSemiLep, Neut_Phi
    xU[*pos+2] = tWmaxHiggs; //HiggsSemiLep, tW2
    //xU[*pos+3] = JetTFfracmax*Jets[numJets].P4.E();//meIntegrator->comEnergy; //HiggsSemiLep, Jet1_E
    //xU[*pos+4] = JetTFfracmax*Jets[numJets].P4.E();//meIntegrator->comEnergy //HiggsSemiLep, Jet2_E
    *pos += 3;
  }
  if (doTTWJJ) {
    if (isJetMissing==kJet_PresentBoth || isJetMissing==kJet_MissingSecond){
      xL[*pos] = Jets[numJets+0].P4.E()*JetTFfracmin; //HiggsSemiLep, Jet1_E
      xU[*pos] = JetTFfracmax*Jets[numJets+0].P4.E();//meIntegrator->comEnergy; //HiggsSemiLep, Jet1_E
      *pos += 1;
    }
    if (isJetMissing==kJet_MissingFirst || isJetMissing==kJet_MissingBoth){
      xL[*pos+0] = 0;
      xL[*pos+1] = 0;
      xL[*pos+2] = 0;
      xU[*pos+0] = MissingJetMaxE;
      xU[*pos+1] = TMath::Pi();
      xU[*pos+2] = 2*TMath::Pi();
      *pos += 3;
    }
    if (isJetMissing==kJet_PresentBoth || isJetMissing==kJet_MissingFirst){
      if (isJetMissing==kJet_PresentBoth){
        xL[*pos] = Jets[numJets+1].P4.E()*JetTFfracmin; //HiggsSemiLep, Jet2_E
        xU[*pos] = JetTFfracmax*Jets[numJets+1].P4.E();//meIntegrator->comEnergy //HiggsSemiLep, Jet2_E
        *pos += 1;
      }
      else if (isJetMissing==kJet_MissingFirst){
        xL[*pos] = Jets[numJets+0].P4.E()*JetTFfracmin; //HiggsSemiLep, Jet2_E
        xU[*pos] = JetTFfracmax*Jets[numJets+0].P4.E();//meIntegrator->comEnergy //HiggsSemiLep, Jet2_E
	*pos += 1;
      }
    }
    if (isJetMissing==kJet_MissingSecond || isJetMissing==kJet_MissingBoth){
      xL[*pos+0] = 0;
      xL[*pos+1] = 0;
      xL[*pos+2] = 0;
      xU[*pos+0] = MissingJetMaxE;
      xU[*pos+1] = TMath::Pi();
      xU[*pos+2] = 2*TMath::Pi();
      *pos += 3;
    }
  }

  return;
}

void MultiLepton::AddIntegrationBound_OneJet(MEPhaseSpace** meIntegrator, int* pos, int numJets, int isJetMissing){

  if (verbosity>=1) cout << "AddIntegrationBound_OneJet" << " numJets="<<numJets<<" isJetMissing="<<isJetMissing << endl;//" E="<< Jets[numJets+0].P4.E()<< " Theta="<<Jets[numJets+0].P4.Theta()<<" Phi="<<Jets[numJets+0].P4.Phi()<<endl;

  if (isJetMissing==kJet_Present){
      (*meIntegrator)->MEMFix_OtherJets.Jet1_Theta = Jets[numJets+0].P4.Theta();
      (*meIntegrator)->MEMFix_OtherJets.Jet1_Phi = Jets[numJets+0].P4.Phi();
    if (numJets==0){
      (*meIntegrator)->transferFunctions->MeasuredVarForTF.Jet1_E = Jets[numJets+0].P4.E();
      (*meIntegrator)->transferFunctions->MeasuredVarForTF.Jet1_Eta = Jets[numJets+0].P4.Eta();
      (*meIntegrator)->transferFunctions->MeasuredVarForTF.doJet1TF = true;
    }
    else if (numJets==2){
      (*meIntegrator)->transferFunctions->MeasuredVarForTF.Jet3_E = Jets[numJets+0].P4.E();
      (*meIntegrator)->transferFunctions->MeasuredVarForTF.Jet3_Eta = Jets[numJets+0].P4.Eta();
      (*meIntegrator)->transferFunctions->MeasuredVarForTF.doJet3TF = true;
    }
  }
  //else if (numJets==0) (*meIntegrator)->transferFunctions->MeasuredVarForTF.doJet1TF = false;
  //else if (numJets==2) (*meIntegrator)->transferFunctions->MeasuredVarForTF.doJet3TF = false;

  if (isJetMissing==kJet_Present){
      xL[*pos] = Jets[numJets+0].P4.E()*JetTFfracmin; //HiggsSemiLep, Jet1_E
      xU[*pos] = JetTFfracmax*Jets[numJets+0].P4.E();//meIntegrator->comEnergy; //HiggsSemiLep, Jet1_E
      *pos += 1;
  }
  else {
      xL[*pos+0] = 0;
      xL[*pos+1] = 0;
      xL[*pos+2] = 0;
      xU[*pos+0] = MissingJetMaxE;
      xU[*pos+1] = TMath::Pi();
      xU[*pos+2] = 2*TMath::Pi();
      *pos += 3;
  }
}

void MultiLepton::SetPresenceBandJets(MEPhaseSpace** meIntegrator, int KindTwoTops, int KindBoson) {

 //max permutations with missing jet/b-jet (default)
  iperm_bmiss_max = 2;
  iperm_jmiss_max = 2;

 //Initialize bjets/jets TF
 (*meIntegrator)->transferFunctions->MeasuredVarForTF.doBjet1TF = false;
 (*meIntegrator)->transferFunctions->MeasuredVarForTF.doBjet2TF = false;
 (*meIntegrator)->transferFunctions->MeasuredVarForTF.doJet1TF = false;
 (*meIntegrator)->transferFunctions->MeasuredVarForTF.doJet2TF = false;
 (*meIntegrator)->transferFunctions->MeasuredVarForTF.doJet3TF = false;
 (*meIntegrator)->transferFunctions->MeasuredVarForTF.doJet4TF = false;

 //Bjets presence
 if (KindTwoTops==0){ //Top had, top lep
   if (Bjets.size()==2){
     (*meIntegrator)->MEMFix_TopHad.isBmissing = kBjet_Present;
     (*meIntegrator)->MEMFix_TopLep.isBmissing = kBjet_Present;
   }
   if (Bjets.size()==1){
     if (iperm_bmiss == 0) {
       (*meIntegrator)->MEMFix_TopHad.isBmissing = kBjet_Present;
       (*meIntegrator)->MEMFix_TopLep.isBmissing = kBjet_Missing;
     }
     else if (iperm_bmiss == 1){
       (*meIntegrator)->MEMFix_TopHad.isBmissing = kBjet_Missing;
       (*meIntegrator)->MEMFix_TopLep.isBmissing = kBjet_Present;
     }
   }
 }
 if (KindTwoTops==1){ //Top lep, top lep
   if (Bjets.size()==2){
     (*meIntegrator)->MEMFix_TopLep.isBmissing = kBjet_Present;
     (*meIntegrator)->MEMFix_TopLep2.isBmissing = kBjet_Present;
   }
   if (Bjets.size()==1){
     if (iperm_bmiss == 0) {
       (*meIntegrator)->MEMFix_TopLep.isBmissing = kBjet_Present;
       (*meIntegrator)->MEMFix_TopLep2.isBmissing = kBjet_Missing;
     }
     else if (iperm_bmiss == 1){
       (*meIntegrator)->MEMFix_TopLep.isBmissing = kBjet_Missing;
       (*meIntegrator)->MEMFix_TopLep2.isBmissing = kBjet_Present;
     }
   }
 }
 if (KindTwoTops==-1){ //top lep, no 2nd top
   if (Bjets.size()>=1) (*meIntegrator)->MEMFix_TopLep.isBmissing = kBjet_Present;
   if (Bjets.size()==0) (*meIntegrator)->MEMFix_TopLep.isBmissing = kBjet_Missing;
 }
 if (KindTwoTops==-2){ //no top ! WZJJ, assume 2 jets (no b-jet)
   (*meIntegrator)->MEMFix_TopLep.isBmissing = kBjet_Missing;
 }

  //Jets presence
  if (KindTwoTops==-1){ //one top only: tzq, thq
    if (KindBoson==0){ //boson with no jet
      if (Jets.size()>=1) (*meIntegrator)->MEMFix_OtherJets.isJmissing = kJet_Present;
      if (Jets.size()==0) (*meIntegrator)->MEMFix_OtherJets.isJmissing = kJet_Missing;
    }
    if (KindBoson==1){ //boson with jets (thq 2lss+3j)
      if (Jets.size()==0) {
	(*meIntegrator)->MEMFix_OtherJets.isJmissing = kJet_Missing;
	(*meIntegrator)->MEMFix_HiggsSemiLep.isJmissing = kJet_MissingBoth;
      }
      if (Jets.size()==1) {
	iperm_jmiss_max = 1;
	(*meIntegrator)->MEMFix_OtherJets.isJmissing = kJet_Present;
        (*meIntegrator)->MEMFix_HiggsSemiLep.isJmissing = kJet_MissingBoth;
      }
      if (Jets.size()==2) {
	(*meIntegrator)->MEMFix_OtherJets.isJmissing = kJet_Present;
	if (iperm_jmiss==0) (*meIntegrator)->MEMFix_HiggsSemiLep.isJmissing = kJet_MissingFirst;
        if (iperm_jmiss==1) (*meIntegrator)->MEMFix_HiggsSemiLep.isJmissing = kJet_MissingSecond;
      }
      if (Jets.size()==3) {
        (*meIntegrator)->MEMFix_OtherJets.isJmissing = kJet_Present;
        (*meIntegrator)->MEMFix_HiggsSemiLep.isJmissing = kJet_PresentBoth;
      }
    }
  }
  if (KindTwoTops==0 && KindBoson==0){ //has top had
    if (Jets.size()==2) (*meIntegrator)->MEMFix_TopHad.isJmissing = kJet_PresentBoth;
    if (Jets.size()==1 && iperm_jmiss==0) (*meIntegrator)->MEMFix_TopHad.isJmissing = kJet_MissingFirst;
    if (Jets.size()==1 && iperm_jmiss==1) (*meIntegrator)->MEMFix_TopHad.isJmissing = kJet_MissingSecond;
    if (Jets.size()==0) (*meIntegrator)->MEMFix_TopHad.isJmissing = kJet_MissingBoth;
  }
  if ((KindTwoTops==1 && KindBoson==1) || (KindTwoTops==-2)){ //has HiggsSemiLep or ttwjj
    if (Jets.size()==2) (*meIntegrator)->MEMFix_HiggsSemiLep.isJmissing = kJet_PresentBoth;
    if (Jets.size()==1 && iperm_jmiss==0) (*meIntegrator)->MEMFix_HiggsSemiLep.isJmissing = kJet_MissingFirst;
    if (Jets.size()==1 && iperm_jmiss==1) (*meIntegrator)->MEMFix_HiggsSemiLep.isJmissing = kJet_MissingSecond;
    if (Jets.size()==0) (*meIntegrator)->MEMFix_HiggsSemiLep.isJmissing = kJet_MissingBoth;
  }
  if (KindBoson==2){
    if (Jets.size()==4) {
      (*meIntegrator)->MEMFix_TopHad.isJmissing = kJet_PresentBoth;
      (*meIntegrator)->MEMFix_HiggsSemiLep.isJmissing = kJet_PresentBoth;
    }
    if (Jets.size()==3) {
      iperm_jmiss_max = 2;
      //if (iperm_jmiss==0) {
      //  (*meIntegrator)->MEMFix_TopHad.isJmissing = kJet_MissingFirst;
      //  (*meIntegrator)->MEMFix_HiggsSemiLep.isJmissing = kJet_PresentBoth;
      //}
      //if (iperm_jmiss==1) {
      //  (*meIntegrator)->MEMFix_TopHad.isJmissing = kJet_MissingSecond;
      //  (*meIntegrator)->MEMFix_HiggsSemiLep.isJmissing = kJet_PresentBoth;
      //}
      if (iperm_jmiss==0) {
        (*meIntegrator)->MEMFix_TopHad.isJmissing = kJet_PresentBoth;
        (*meIntegrator)->MEMFix_HiggsSemiLep.isJmissing = kJet_MissingFirst;
      }
      if (iperm_jmiss==1) {
        (*meIntegrator)->MEMFix_TopHad.isJmissing = kJet_PresentBoth;
        (*meIntegrator)->MEMFix_HiggsSemiLep.isJmissing = kJet_MissingSecond;
      }
    }
    if (Jets.size()==2){
      iperm_jmiss_max = 1;
      //if (iperm_jmiss==0) {
      //  (*meIntegrator)->MEMFix_TopHad.isJmissing = kJet_MissingBoth;
      //  (*meIntegrator)->MEMFix_HiggsSemiLep.isJmissing = kJet_PresentBoth;
      //}
      if (iperm_jmiss==0) {
        (*meIntegrator)->MEMFix_TopHad.isJmissing = kJet_PresentBoth;
        (*meIntegrator)->MEMFix_HiggsSemiLep.isJmissing = kJet_MissingBoth;
      }
      //if (iperm_jmiss==1) {
      //  (*meIntegrator)->MEMFix_TopHad.isJmissing = kJet_MissingFirst;
      //  (*meIntegrator)->MEMFix_HiggsSemiLep.isJmissing = kJet_MissingFirst;
      //}
      //if (iperm_jmiss==2) {
      //  (*meIntegrator)->MEMFix_TopHad.isJmissing = kJet_MissingSecond;
      //  (*meIntegrator)->MEMFix_HiggsSemiLep.isJmissing = kJet_MissingSecond;
      //}
      //if (iperm_jmiss==3) {
      //  (*meIntegrator)->MEMFix_TopHad.isJmissing = kJet_MissingFirst;
      //  (*meIntegrator)->MEMFix_HiggsSemiLep.isJmissing = kJet_MissingSecond;
      //}
      //if (iperm_jmiss==4) {
      //  (*meIntegrator)->MEMFix_TopHad.isJmissing = kJet_MissingSecond;
      //  (*meIntegrator)->MEMFix_HiggsSemiLep.isJmissing = kJet_MissingFirst;
      //}
    }
  }

  return;
}

void MultiLepton::SetVerbosity(int v=1){
  verbosity = v;
  return;
}


#endif
