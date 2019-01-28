#ifndef TRANSFERFUNCTIONS_CPP
#define TRANSFERFUNCTIONS_CPP

#include <iostream>

#include "TH1F.h"
#include "TFile.h"
#include "TDirectory.h"
#include "TMath.h"
#include "TMatrix.h"
#include "TVector3.h"

#include "../interface/TransferFunctions.h"

using namespace std;

TransferFunctions::TransferFunctions(){

  //Initialize transfert function
  TF_nonB = new TH1F**[3];
  TF_B = new TH1F**[3];
  TFratio_nonB = new TH1F**[3];
  TFratio_B = new TH1F**[3];
  for (int iEta=0; iEta<3; iEta++) {
    TF_nonB[iEta] = new TH1F*[6];
    TF_B[iEta] = new TH1F*[6];
    TFratio_nonB[iEta] = new TH1F*[6];
    TFratio_B[iEta] = new TH1F*[6];
  }

  TF_MetPx = new TH1F*[6];
  TF_MetPy = new TH1F*[6];
  TF_MetPt = new TH1F*[6];
  TF_MetPhi = new TH1F*[6];

}

TransferFunctions::~TransferFunctions(){

}

void TransferFunctions::SetTFChoice(int iChoice){

  iTF = iChoice;
  return;
}

void TransferFunctions::SetTFOption(int iOption){

  iTFOption = iOption;
  return;
}

void TransferFunctions::LoadTFfromHisto(string FileName) const {

  TFile* fTF = new TFile(FileName.c_str(),"READ");

  if (verbosity_>=1) gDirectory->pwd();

  TH1F* Histo_tmp;
  string histoname;

  //Loading histos
  for (int iEta=0; iEta<3; iEta++){
    for (int iEnergy=0; iEnergy<6; iEnergy++){

      histoname = "TF_nonB_" + EtaRangeLabel[iEta] + "_" + EnergyRangeLabel[iEnergy];
      if (verbosity_>=1) cout << histoname << endl;
      fTF->GetObject(histoname.c_str(), Histo_tmp);
      TF_nonB[iEta][iEnergy] = (TH1F*) Histo_tmp->Clone();

      histoname = "TF_B_" + EtaRangeLabel[iEta] + "_" + EnergyRangeLabel[iEnergy];
      Histo_tmp = (TH1F*) fTF->Get(histoname.c_str());
      TF_B[iEta][iEnergy] = (TH1F*) Histo_tmp->Clone();

      histoname = "TFratio_nonB_" + EtaRangeLabel[iEta] + "_" + EnergyRangeLabel[iEnergy];
      Histo_tmp = (TH1F*) fTF->Get(histoname.c_str());
      TFratio_nonB[iEta][iEnergy] = (TH1F*) Histo_tmp->Clone();

      histoname = "TFratio_B_" + EtaRangeLabel[iEta] + "_" + EnergyRangeLabel[iEnergy];
      Histo_tmp = (TH1F*) fTF->Get(histoname.c_str());
      TFratio_B[iEta][iEnergy] = (TH1F*) Histo_tmp->Clone();
    }
  }

  for (int iMet=0; iMet<6; iMet++){
    histoname = "TF_mET_Px_" + MetRangeLabel[iMet];
    Histo_tmp = (TH1F*) fTF->Get(histoname.c_str());
    TF_MetPx[iMet] = (TH1F*) Histo_tmp->Clone();

    histoname = "TF_mET_Py_" + MetRangeLabel[iMet];
    Histo_tmp = (TH1F*) fTF->Get(histoname.c_str());
    TF_MetPy[iMet] = (TH1F*) Histo_tmp->Clone();

    histoname = "TF_mET_Pt_" + MetRangeLabel[iMet];
    Histo_tmp = (TH1F*) fTF->Get(histoname.c_str());
    TF_MetPt[iMet] = (TH1F*) Histo_tmp->Clone();

    histoname = "TF_mET_Phi_" + MetRangeLabel[iMet];
    Histo_tmp = (TH1F*) fTF->Get(histoname.c_str());
    TF_MetPhi[iMet] = (TH1F*) Histo_tmp->Clone();
  }

  return;
}

double TransferFunctions::ComputeSingleTF_Gaus(double Gen_E, double Reco_E, double Res) const {

  double weightTF = TMath::Gaus(Gen_E-Reco_E, 0, TMath::Abs(Res*Gen_E), kTRUE);
  if (verbosity_>=2) cout << "TF Gaus Gen="<<Gen_E<<" Reco="<<Reco_E<<" weightTF="<<weightTF<<endl;

  return weightTF;
}

double TransferFunctions::ComputeDoubleTF_MetCov(double Gen_MetPx, double Reco_MetPx, double Gen_MetPy, double Reco_MetPy, double Reco_MetCov00, double Reco_MetCov01, double Reco_MetCov10, double Reco_MetCov11) const{

  double weightTF = 1;

  double sigmaPx = sqrt(Reco_MetCov00);
  double sigmaPy = sqrt(Reco_MetCov11);
  double rho = Reco_MetCov01 / sigmaPx / sigmaPy;

  double norm = 1./(2*TMath::Pi()*sqrt(1-rho*rho)*sigmaPx*sigmaPy);
  
  TMatrix CovMatrix(2,2); 
  CovMatrix[0][0] = Reco_MetCov00;
  CovMatrix[0][1] = Reco_MetCov01;
  CovMatrix[1][0] = Reco_MetCov10;
  CovMatrix[1][1] = Reco_MetCov11;
  CovMatrix.Invert();

  TMatrix mETcol(2,1);
  mETcol[0][0] = Reco_MetPx-Gen_MetPx;
  mETcol[1][0] = Reco_MetPy-Gen_MetPy;

  TMatrix mETrow(1,2);
  mETrow[0][0] = Reco_MetPx-Gen_MetPx;
  mETrow[0][1] = Reco_MetPy-Gen_MetPy;

  TMatrix ResultMatrix = CovMatrix * mETcol;
  double arg = mETrow[0][0] * ResultMatrix[0][0] + mETrow[0][1] * ResultMatrix[1][0];

  weightTF = norm * TMath::Exp(-0.5 * arg);

  return weightTF;
}

double TransferFunctions::ComputeSingleTF_Histo(string Part, double Gen_E, double Reco_E, double Reco_Eta) const {

  double weightTF = 1;

  float Jet_Pt = Reco_E / TMath::CosH(Reco_Eta);
  if ((Part=="Bjet" || Part=="Jet") && Jet_Pt<25) {
    if (verbosity_>=2) cout << "TF Histo JetPt="<<Jet_Pt<<"<25, set weightTF=1"<<endl;
    return 1;
  }

  int iEta = -1;
  for (int iBin=0; iBin<3; iBin++){
    if (fabs(Reco_Eta) > EtaRange[iBin] && fabs(Reco_Eta) < EtaRange[iBin+1]) iEta=iBin;
  }
  int iEnergy = -1;
  for (int iBin=0; iBin<6; iBin++){
    if (Reco_E > EnergyRange[iBin] && Reco_E < EnergyRange[iBin+1]) iEnergy=iBin;
  }
  if ((Part=="Bjet" || Part=="Jet") && (iEta==-1 || iEnergy==-1)) {
    if (verbosity_>=2) cout << "TF Histo Jet Energy="<<Reco_E<<" |Eta|="<<fabs(Reco_Eta)<<" out of range, set weightTF=1"<<endl;
    return 1;
  }

  int iMet = -1;
  //Reco_E=MET, Reco_Eta=MHT
  for (int iBin=0; iBin<2; iBin++){ //MET
    if (fabs(Reco_E) > MetRange[iBin] && fabs(Reco_E)<MetRange[iBin+1]) iMet = iBin;
  }
  for (int iBin=0; iBin<3; iBin++){ //MHT
    if (Reco_Eta > MetSumRange[iBin] && Reco_Eta<MetSumRange[iBin+1]) iMet = iMet*3 + iBin;
  }
  if ((Part=="mET_Px" || Part=="mET_Py" || Part=="mET_Pt" || Part=="mET_Phi") && (iMet<0 || iMet>5)){
    if (verbosity_>=2) cout << "TF Histo mET component = "<<Reco_E<<" out of range, set weightTF=1"<<endl;
    return 1;
  }

  int iTFbin = -1;

  if (Part=="Bjet") {
    if (iTF == kTFHistoBnonBmET) {
      iTFbin = TF_B[iEta][iEnergy]->FindBin(Gen_E-Reco_E);
      if (iTFbin >= TF_B[iEta][iEnergy]->GetNbinsX() || iTFbin==0) weightTF = 0;
      else weightTF = TF_B[iEta][iEnergy]->GetBinContent(iTFbin);
    }
    else if (iTF == kTFHistoBnonBratiomET) {
      iTFbin = TFratio_B[iEta][iEnergy]->FindBin(Reco_E/Gen_E);
      if (iTFbin >= TFratio_B[iEta][iEnergy]->GetNbinsX() || iTFbin==0) weightTF = 0;
      else weightTF = TFratio_B[iEta][iEnergy]->GetBinContent(iTFbin);
    }
  }

  if (Part=="Jet") {
    if (iTF == kTFHistoBnonBmET) {
      iTFbin = TF_nonB[iEta][iEnergy]->FindBin(Gen_E-Reco_E);
      if (iTFbin >= TF_nonB[iEta][iEnergy]->GetNbinsX() || iTFbin==0) weightTF = 0;
      else weightTF = TF_nonB[iEta][iEnergy]->GetBinContent(iTFbin);
    }
    else if (iTF == kTFHistoBnonBratiomET) {
      iTFbin = TFratio_nonB[iEta][iEnergy]->FindBin(Reco_E/Gen_E);
      if (iTFbin >= TFratio_nonB[iEta][iEnergy]->GetNbinsX() || iTFbin==0) weightTF = 0;
      else weightTF = TFratio_nonB[iEta][iEnergy]->GetBinContent(iTFbin);
    }
  }

  if (Part=="mET_Px") {
    iTFbin = TF_MetPx[iMet]->FindBin(Gen_E-Reco_E);
    if (iTFbin >= TF_MetPx[iMet]->GetNbinsX() || iTFbin==0) weightTF = 0;
    else weightTF = TF_MetPx[iMet]->GetBinContent(iTFbin);
  }
  if (Part=="mET_Py") {
    iTFbin = TF_MetPy[iMet]->FindBin(Gen_E-Reco_E);
    if (iTFbin >= TF_MetPy[iMet]->GetNbinsX() || iTFbin==0) weightTF = 0;
    else weightTF = TF_MetPy[iMet]->GetBinContent(iTFbin);
  }
  if (Part=="mET_Pt") {
    iTFbin = TF_MetPt[iMet]->FindBin(Gen_E-Reco_E);
    if (iTFbin >= TF_MetPt[iMet]->GetNbinsX() || iTFbin==0) weightTF = 0;
    else weightTF = TF_MetPt[iMet]->GetBinContent(iTFbin);
  }
  if (Part=="mET_Phi") {
    iTFbin = TF_MetPhi[iMet]->FindBin(Gen_E-Reco_E);
    if (iTFbin >= TF_MetPhi[iMet]->GetNbinsX() || iTFbin==0) weightTF = 0;
    else weightTF = TF_MetPhi[iMet]->GetBinContent(iTFbin);
  }

  if (verbosity_>=2) cout << "TF Histo "<<Part<< " Gen="<<Gen_E<<" Reco="<<Reco_E<<" weightTF="<<weightTF<<endl;

  return weightTF;
}

double TransferFunctions::ComputeTFProductJetBjetMet(int jetTFmode) const {

  double weightTF_Bjet1 = 1;
  double weightTF_Bjet2 = 1;
  double weightTF_Jet1 = 1;
  double weightTF_Jet2 = 1;
  double weightTF_Jet3 = 1;
  double weightTF_Jet4 = 1;
  double weightTF_Recoil_Px = 1;
  double weightTF_Recoil_Py = 1;

  //B-jets
  if (iTF == kTFGaussian) {
    if (MeasuredVarForTF.doBjet1TF) weightTF_Bjet1 = ComputeSingleTF_Gaus(ComputedVarForTF.Bjet1_E, MeasuredVarForTF.Bjet1_E, 0.2);
    if (MeasuredVarForTF.doBjet2TF) weightTF_Bjet2 = ComputeSingleTF_Gaus(ComputedVarForTF.Bjet2_E, MeasuredVarForTF.Bjet2_E, 0.2);
  }
  else if (iTF == kTFHistoBnonB_GausRecoil || iTF == kTFHistoBnonBmET || iTF == kTFHistoBnonBratiomET){
    if (MeasuredVarForTF.doBjet1TF) weightTF_Bjet1 = ComputeSingleTF_Histo("Bjet", ComputedVarForTF.Bjet1_E, MeasuredVarForTF.Bjet1_E, MeasuredVarForTF.Bjet1_Eta);
    if (MeasuredVarForTF.doBjet2TF) weightTF_Bjet2 = ComputeSingleTF_Histo("Bjet", ComputedVarForTF.Bjet2_E, MeasuredVarForTF.Bjet2_E, MeasuredVarForTF.Bjet2_Eta);
  }

  //Jets
  if (iTF == kTFGaussian){
    if (MeasuredVarForTF.doJet1TF) weightTF_Jet1 = ComputeSingleTF_Gaus(ComputedVarForTF.Jet1_E, MeasuredVarForTF.Jet1_E, 0.2);
    else if (TMath::Abs(ComputedVarForTF.Jet1_Eta)<2.4 && (ComputedVarForTF.Jet1_E / TMath::CosH(ComputedVarForTF.Jet1_Eta))>25) weightTF_Jet1 = 0;
    if (MeasuredVarForTF.doJet2TF) weightTF_Jet2 = ComputeSingleTF_Gaus(ComputedVarForTF.Jet2_E, MeasuredVarForTF.Jet2_E, 0.2);
    else if (TMath::Abs(ComputedVarForTF.Jet2_Eta)<2.4 && (ComputedVarForTF.Jet2_E / TMath::CosH(ComputedVarForTF.Jet2_Eta))>25) weightTF_Jet2 = 0;
    if (jetTFmode==2) {
      if (MeasuredVarForTF.doJet3TF) weightTF_Jet3 = ComputeSingleTF_Gaus(ComputedVarForTF.Jet3_E, MeasuredVarForTF.Jet3_E, 0.2);
      else if (TMath::Abs(ComputedVarForTF.Jet3_Eta)<2.4 && (ComputedVarForTF.Jet3_E / TMath::CosH(ComputedVarForTF.Jet3_Eta))>25) weightTF_Jet3 = 0;
      if (MeasuredVarForTF.doJet4TF) weightTF_Jet4 = ComputeSingleTF_Gaus(ComputedVarForTF.Jet4_E, MeasuredVarForTF.Jet4_E, 0.2);
      else if (TMath::Abs(ComputedVarForTF.Jet4_Eta)<2.4 && (ComputedVarForTF.Jet4_E / TMath::CosH(ComputedVarForTF.Jet4_Eta))>25) weightTF_Jet4 = 0;
    }
  }
  else if (iTF == kTFHistoBnonB_GausRecoil || iTF == kTFHistoBnonBmET || iTF == kTFHistoBnonBratiomET){
    if (jetTFmode>=1){ //bug fix : previously was not computed in Hlnujj 2lss case... (jetTFmode==1 only was checked)
      if (MeasuredVarForTF.doJet1TF) weightTF_Jet1 = ComputeSingleTF_Histo("Jet", ComputedVarForTF.Jet1_E, MeasuredVarForTF.Jet1_E, MeasuredVarForTF.Jet1_Eta);
      else if (TMath::Abs(ComputedVarForTF.Jet1_Eta)<2.4 && (ComputedVarForTF.Jet1_E / TMath::CosH(ComputedVarForTF.Jet1_Eta))>25) weightTF_Jet1 = 0;
    }
    if (jetTFmode>=2) {
      if (MeasuredVarForTF.doJet2TF) weightTF_Jet2 = ComputeSingleTF_Histo("Jet", ComputedVarForTF.Jet2_E, MeasuredVarForTF.Jet2_E, MeasuredVarForTF.Jet2_Eta);
      else if (TMath::Abs(ComputedVarForTF.Jet2_Eta)<2.4 && (ComputedVarForTF.Jet2_E / TMath::CosH(ComputedVarForTF.Jet2_Eta))>25) weightTF_Jet2 = 0;
    }
    if (jetTFmode>=3) {
      if (MeasuredVarForTF.doJet3TF) weightTF_Jet3 = ComputeSingleTF_Histo("Jet", ComputedVarForTF.Jet3_E, MeasuredVarForTF.Jet3_E, MeasuredVarForTF.Jet3_Eta);
      else if (TMath::Abs(ComputedVarForTF.Jet3_Eta)<2.4 && (ComputedVarForTF.Jet3_E / TMath::CosH(ComputedVarForTF.Jet3_Eta))>25) weightTF_Jet3 = 0;
    }
    if (jetTFmode>=4) {
      if (MeasuredVarForTF.doJet4TF) weightTF_Jet4 = ComputeSingleTF_Histo("Jet", ComputedVarForTF.Jet4_E, MeasuredVarForTF.Jet4_E, MeasuredVarForTF.Jet4_Eta);
      else if (TMath::Abs(ComputedVarForTF.Jet4_Eta)<2.4 && (ComputedVarForTF.Jet4_E / TMath::CosH(ComputedVarForTF.Jet4_Eta))>25) weightTF_Jet4 = 0;
    }
  }

  //Recoil
  if (iTF == kTFGaussian || iTF==kTFHistoBnonB_GausRecoil){
    if (iTFOption==kTFRecoilPtot){
      weightTF_Recoil_Px = ComputeSingleTF_Gaus(ComputedVarForTF.Recoil_Px, MeasuredVarForTF.Recoil_Px, 0.2);
      weightTF_Recoil_Py = ComputeSingleTF_Gaus(ComputedVarForTF.Recoil_Py, MeasuredVarForTF.Recoil_Py, 0.2);
    }
    else if (iTFOption==kTFRecoilmET){
      weightTF_Recoil_Px = ComputeSingleTF_Gaus(ComputedVarForTF.mET_Px, MeasuredVarForTF.mET_Px, 0.2);
      weightTF_Recoil_Py = ComputeSingleTF_Gaus(ComputedVarForTF.mET_Py, MeasuredVarForTF.mET_Py, 0.2);
    }
  }
  else if (iTF == kTFHistoBnonBmET || iTF==kTFHistoBnonBratiomET){
    if (iTFOption==kTFRecoilmET){
      weightTF_Recoil_Px = ComputeSingleTF_Histo("mET_Px", ComputedVarForTF.mET_Px, MeasuredVarForTF.mET_Px, MeasuredVarForTF.sumET);
      weightTF_Recoil_Py = ComputeSingleTF_Histo("mET_Py", ComputedVarForTF.mET_Py, MeasuredVarForTF.mET_Py, MeasuredVarForTF.sumET);
    }
    else if (iTFOption==kTFRecoilmETphi){
      double Computed_mET_Pt = sqrt(ComputedVarForTF.mET_Px*ComputedVarForTF.mET_Px+ComputedVarForTF.mET_Py*ComputedVarForTF.mET_Py);
      double Measured_mET_Pt = sqrt(MeasuredVarForTF.mET_Px*MeasuredVarForTF.mET_Px+MeasuredVarForTF.mET_Py*MeasuredVarForTF.mET_Py);
      TVector3 met_tmp; met_tmp.SetXYZ(ComputedVarForTF.mET_Px, ComputedVarForTF.mET_Py, 0);
      double Computed_mET_Phi = met_tmp.Phi();
      met_tmp.SetXYZ(MeasuredVarForTF.mET_Px, MeasuredVarForTF.mET_Py, 0);
      double Measured_mET_Phi = met_tmp.Phi();
      weightTF_Recoil_Px = ComputeSingleTF_Histo("mET_Pt", Computed_mET_Pt, Measured_mET_Pt, MeasuredVarForTF.sumET);
      weightTF_Recoil_Py = ComputeSingleTF_Histo("mET_Phi", Computed_mET_Phi, Measured_mET_Phi, MeasuredVarForTF.sumET);
    }
    else if (iTFOption==kTFRecoilmETcov){
      weightTF_Recoil_Px = ComputeDoubleTF_MetCov(ComputedVarForTF.mET_Px, MeasuredVarForTF.mET_Px, ComputedVarForTF.mET_Py, MeasuredVarForTF.mET_Py, MeasuredVarForTF.mET_cov00, MeasuredVarForTF.mET_cov01, MeasuredVarForTF.mET_cov10, MeasuredVarForTF.mET_cov11);
      weightTF_Recoil_Py = 1;
    }
  }

  double weightTF = weightTF_Bjet1*weightTF_Bjet2*weightTF_Jet1*weightTF_Jet2*weightTF_Jet3*weightTF_Jet4*weightTF_Recoil_Px*weightTF_Recoil_Py;

  if (verbosity_>=2) {
    cout << "weightTF_Bjet1="<<weightTF_Bjet1<<endl;
    cout << "weightTF_Bjet2="<<weightTF_Bjet2<<endl;
    cout << "weightTF_Jet1="<<weightTF_Jet1<<endl;
    cout << "weightTF_Jet2="<<weightTF_Jet2<<endl;
    cout << "weightTF_Jet3="<<weightTF_Jet3<<endl;
    cout << "weightTF_Jet4="<<weightTF_Jet4<<endl;
    cout << "weightTF_mET1="<<weightTF_Recoil_Px<<endl;
    cout << "weightTF_mET2="<<weightTF_Recoil_Py<<endl;
    cout << "weightTF="<<weightTF<<endl;
  }

  return weightTF;
}

void TransferFunctions::SetVerbosity(int v=1){
  verbosity_ = v;
  if (verbosity_>=1) cout << "TransferFunctions verbosity="<<verbosity_<<endl;
  return;
}

#endif
