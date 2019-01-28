#ifndef TRANSFERFUNCTIONS_H
#define TRANSFERFUNCTIONS_H

#include "TH1F.h"
#include "TFile.h"
#include "TDirectory.h"
#include "TMath.h"
#include "TMatrix.h"
#include "TVector3.h"

using namespace std;

const string EtaRangeLabel[] = {"00eta08", "08eta16", "16eta24"};
const string EnergyRangeLabel[] = {"25E50", "50E80", "80E120", "120E200", "200E300", "EGT300"};
const float EtaRange[] = {0.0, 0.8, 1.6, 2.4};
const float EnergyRange[] = {25, 50, 80, 120, 200, 300, 7000};
const string MetRangeLabel[] = {"mET0E100Sum0E1200", "mET0E100Sum1200E1600", "mET0E100SumEGT1600", "mETGT100Sum0E1200", "mETGT100Sum1200E1600", "mETGT100SumEGT1600"};
const float MetRange[] = {0, 100, 7000};
const float MetSumRange[] = {0, 1200, 1600, 7000};

#define kTFNone 0
#define kTFGaussian 1
#define kTFHistoBnonB_GausRecoil 2
#define kTFHistoBnonBmET 3
#define kTFHistoBnonBratiomET 4

#define kTFRecoilNone -1
#define kTFRecoilPtot 0
#define kTFRecoilmET 1
#define kTFRecoilmETphi 2
#define kTFRecoilmETcov 3

class TransferFunctions
{

  public:
    TransferFunctions();
    ~TransferFunctions();

    int verbosity_;
    void SetVerbosity(int);

    int iTF;
    int iTFOption;
    void SetTFChoice(int);
    void SetTFOption(int);

    double ComputeTFProductJetBjetMet(int) const;
    double ComputeSingleTF_Gaus(double, double, double) const;
    double ComputeDoubleTF_MetCov(double, double, double, double, double, double, double, double) const;
    double ComputeSingleTF_Histo(string, double, double, double) const;
    void LoadTFfromHisto(string) const;

    TH1F*** TF_nonB;
    TH1F*** TF_B;
    TH1F*** TFratio_nonB;
    TH1F*** TFratio_B;
    TH1F** TF_MetPx;
    TH1F** TF_MetPy;
    TH1F** TF_MetPt;
    TH1F** TF_MetPhi;

    struct MeasuredVarForTF {
      double Bjet1_E;
      double Bjet1_Eta;
      double Bjet2_E;
      double Bjet2_Eta;
      double Jet1_E;
      double Jet1_Eta;
      double Jet2_E;
      double Jet2_Eta;
      double Jet3_E;
      double Jet3_Eta;
      double Jet4_E;
      double Jet4_Eta;
      double Recoil_Px;
      double Recoil_Py;
      double mET_Px;
      double mET_Py;
      double mET_cov00;
      double mET_cov01;
      double mET_cov10;
      double mET_cov11;
      double sumET;
      bool doBjet1TF;
      bool doBjet2TF;
      bool doJet1TF;
      bool doJet2TF;
      bool doJet3TF;
      bool doJet4TF;
    } MeasuredVarForTF;

    mutable struct ComputedVarForTF {
      double Bjet1_E;
      double Bjet2_E;
      double Jet1_E;
      double Jet1_Eta;
      double Jet2_E;
      double Jet2_Eta;
      double Jet3_E;
      double Jet3_Eta;
      double Jet4_E;
      double Jet4_Eta;
      double Recoil_Px;
      double Recoil_Py;
      double mET_Px;
      double mET_Py;
    } ComputedVarForTF;

  private:
} ;

#endif
