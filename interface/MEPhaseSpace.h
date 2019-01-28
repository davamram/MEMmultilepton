#ifndef MEPHASESPACE_H
#define MEPHASESPACE_H

#include <iostream>
#include <iomanip>

#include "TLorentzVector.h"
#include "TMath.h"
#include "TMatrixDSym.h"
#include "TMatrix.h"

#include "TransferFunctions.h"

#include "LHAPDF/LHAPDF.h"
//#include "rambo.h"
#include "../data/Madgraph/PROC_SA_CPP_sm_4/SubProcesses/P0_Sigma_sm_gg_ttxh/CPPProcess.h"
#include "../data/Madgraph/PROC_SA_CPP_sm_DECAY_tbwjj/SubProcesses/P0_Sigma_sm_t_budx/CPPProcess_tbwjj.h"
#include "../data/Madgraph/PROC_SA_CPP_sm_DECAY_tbwlnu/SubProcesses/P0_Sigma_sm_t_bepve/CPPProcess_tbwlnu.h"
#include "../data/Madgraph/PROC_SA_CPP_sm_DECAY_hw2l2nu/SubProcesses/P0_Sigma_sm_h_epveemvex/CPPProcess_hw2l2nu.h"
#include "../data/Madgraph/PROC_SA_CPP_sm_DECAY_antitbwjj/SubProcesses/P0_Sigma_sm_tx_bxdux/CPPProcess_antitbwjj.h"
#include "../data/Madgraph/PROC_SA_CPP_sm_DECAY_ggttll/SubProcesses/P0_Sigma_sm_gg_ttxepem/CPPProcess_ggttll.h"
//#include "../data/Madgraph/PROC_SA_CPP_sm_DECAY_qqttlpvl/SubProcesses/P0_Sigma_sm_udx_ttxepve/CPPProcess_qqttlpvl.h"
//#include "../data/Madgraph/PROC_SA_CPP_sm_DECAY_qqttlmvl/SubProcesses/P0_Sigma_sm_dux_ttxemvex/CPPProcess_qqttlmvl.h"
#include "../data/Madgraph/PROC_SA_CPP_sm_ckm_DECAY_qqttlpvl/SubProcesses/P0_Sigma_sm_ckm_cdx_ttxepve/CPPProcess_P0_Sigma_sm_ckm_cdx_ttxepve.h"
#include "../data/Madgraph/PROC_SA_CPP_sm_ckm_DECAY_qqttlpvl/SubProcesses/P0_Sigma_sm_ckm_udx_ttxepve/CPPProcess_P0_Sigma_sm_ckm_udx_ttxepve.h"
#include "../data/Madgraph/PROC_SA_CPP_sm_ckm_DECAY_qqttlpvl/SubProcesses/P0_Sigma_sm_ckm_usx_ttxepve/CPPProcess_P0_Sigma_sm_ckm_usx_ttxepve.h"
#include "../data/Madgraph/PROC_SA_CPP_sm_ckm_DECAY_qqttlmvl/SubProcesses/P0_Sigma_sm_ckm_dcx_ttxemvex/CPPProcess_P0_Sigma_sm_ckm_dcx_ttxemvex.h"
#include "../data/Madgraph/PROC_SA_CPP_sm_ckm_DECAY_qqttlmvl/SubProcesses/P0_Sigma_sm_ckm_dux_ttxemvex/CPPProcess_P0_Sigma_sm_ckm_dux_ttxemvex.h"
#include "../data/Madgraph/PROC_SA_CPP_sm_ckm_DECAY_qqttlmvl/SubProcesses/P0_Sigma_sm_ckm_sux_ttxemvex/CPPProcess_P0_Sigma_sm_ckm_sux_ttxemvex.h"
#include "../data/Madgraph/PROC_SA_CPP_sm_ckm_DECAY_ppttlpvljj/SubProcesses/P0_Sigma_sm_ckm_gc_ttxepvegd/CPPProcess_P0_Sigma_sm_ckm_gc_ttxepvegd.h"
#include "../data/Madgraph/PROC_SA_CPP_sm_ckm_DECAY_ppttlpvljj/SubProcesses/P0_Sigma_sm_ckm_gdx_ttxepvegcx/CPPProcess_P0_Sigma_sm_ckm_gdx_ttxepvegcx.h"
#include "../data/Madgraph/PROC_SA_CPP_sm_ckm_DECAY_ppttlpvljj/SubProcesses/P0_Sigma_sm_ckm_gdx_ttxepvegux/CPPProcess_P0_Sigma_sm_ckm_gdx_ttxepvegux.h"
#include "../data/Madgraph/PROC_SA_CPP_sm_ckm_DECAY_ppttlpvljj/SubProcesses/P0_Sigma_sm_ckm_gsx_ttxepvegux/CPPProcess_P0_Sigma_sm_ckm_gsx_ttxepvegux.h"
#include "../data/Madgraph/PROC_SA_CPP_sm_ckm_DECAY_ppttlpvljj/SubProcesses/P0_Sigma_sm_ckm_gu_ttxepvegd/CPPProcess_P0_Sigma_sm_ckm_gu_ttxepvegd.h"
#include "../data/Madgraph/PROC_SA_CPP_sm_ckm_DECAY_ppttlpvljj/SubProcesses/P0_Sigma_sm_ckm_gu_ttxepvegs/CPPProcess_P0_Sigma_sm_ckm_gu_ttxepvegs.h"
#include "../data/Madgraph/PROC_SA_CPP_sm_ckm_DECAY_ppttlmvljj/SubProcesses/P0_Sigma_sm_ckm_gcx_ttxemvexgdx/CPPProcess_P0_Sigma_sm_ckm_gcx_ttxemvexgdx.h"
#include "../data/Madgraph/PROC_SA_CPP_sm_ckm_DECAY_ppttlmvljj/SubProcesses/P0_Sigma_sm_ckm_gd_ttxemvexgc/CPPProcess_P0_Sigma_sm_ckm_gd_ttxemvexgc.h"
#include "../data/Madgraph/PROC_SA_CPP_sm_ckm_DECAY_ppttlmvljj/SubProcesses/P0_Sigma_sm_ckm_gd_ttxemvexgu/CPPProcess_P0_Sigma_sm_ckm_gd_ttxemvexgu.h"
#include "../data/Madgraph/PROC_SA_CPP_sm_ckm_DECAY_ppttlmvljj/SubProcesses/P0_Sigma_sm_ckm_gs_ttxemvexgu/CPPProcess_P0_Sigma_sm_ckm_gs_ttxemvexgu.h"
#include "../data/Madgraph/PROC_SA_CPP_sm_ckm_DECAY_ppttlmvljj/SubProcesses/P0_Sigma_sm_ckm_gux_ttxemvexgdx/CPPProcess_P0_Sigma_sm_ckm_gux_ttxemvexgdx.h"
#include "../data/Madgraph/PROC_SA_CPP_sm_ckm_DECAY_ppttlmvljj/SubProcesses/P0_Sigma_sm_ckm_gux_ttxemvexgsx/CPPProcess_P0_Sigma_sm_ckm_gux_ttxemvexgsx.h"
#include "../data/Madgraph/PROC_SA_CPP_sm_DECAY_ggtt/SubProcesses/P0_Sigma_sm_gg_ttx/CPPProcess_P0_Sigma_sm_gg_ttx.h"
#include "../data/Madgraph/PROC_SA_CPP_sm_no_b_mass_DECAY_pptllq/SubProcesses/P0_Sigma_sm_no_b_mass_dbx_txepemu/CPPProcess_P0_Sigma_sm_no_b_mass_dbx_txepemu.h"
#include "../data/Madgraph/PROC_SA_CPP_sm_no_b_mass_DECAY_pptllq/SubProcesses/P0_Sigma_sm_no_b_mass_dxb_tepemux/CPPProcess_P0_Sigma_sm_no_b_mass_dxb_tepemux.h"
#include "../data/Madgraph/PROC_SA_CPP_sm_no_b_mass_DECAY_pptllq/SubProcesses/P0_Sigma_sm_no_b_mass_ub_tepemd/CPPProcess_P0_Sigma_sm_no_b_mass_ub_tepemd.h"
#include "../data/Madgraph/PROC_SA_CPP_sm_no_b_mass_DECAY_pptllq/SubProcesses/P0_Sigma_sm_no_b_mass_uxbx_txepemdx/CPPProcess_P0_Sigma_sm_no_b_mass_uxbx_txepemdx.h"
#include "../data/Madgraph/PROC_SA_CPP_sm_DECAY_gqlnullgq/SubProcesses/P0_Sigma_sm_gdx_epvemupmumgux/CPPProcess_P0_Sigma_sm_gdx_epvemupmumgux.h"
#include "../data/Madgraph/PROC_SA_CPP_sm_DECAY_gqlnullgq/SubProcesses/P0_Sigma_sm_gu_epvemupmumgd/CPPProcess_P0_Sigma_sm_gu_epvemupmumgd.h"
#include "../data/Madgraph/PROC_SA_CPP_sm_no_b_mass_DECAY_ppthq/SubProcesses/P0_Sigma_sm_no_b_mass_dbx_txhu/CPPProcess_P0_Sigma_sm_no_b_mass_dbx_txhu.h"
#include "../data/Madgraph/PROC_SA_CPP_sm_no_b_mass_DECAY_ppthq/SubProcesses/P0_Sigma_sm_no_b_mass_dxb_thux/CPPProcess_P0_Sigma_sm_no_b_mass_dxb_thux.h"
#include "../data/Madgraph/PROC_SA_CPP_sm_no_b_mass_DECAY_ppthq/SubProcesses/P0_Sigma_sm_no_b_mass_ub_thd/CPPProcess_P0_Sigma_sm_no_b_mass_ub_thd.h"
#include "../data/Madgraph/PROC_SA_CPP_sm_no_b_mass_DECAY_ppthq/SubProcesses/P0_Sigma_sm_no_b_mass_uxbx_txhdx/CPPProcess_P0_Sigma_sm_no_b_mass_uxbx_txhdx.h"


#define kNoPhaseSpace -1 //No Integration, just evaluation
#define kInitialPartons 0 //Integration over bjorken x, given the final states
#define kAllPartonsTTH 1 //Integration over everything (total cross-section)
//#define kAllPartonsTTH_FSonly 2 //Integration over final state phase space only
#define kAllPartonsTopHad 3
#define kAllPartonsTopHad_FiniteWidth 4
#define kAllPartonsTopLep 5
#define kAllPartonsTopLep_FixedTopM_FiniteWwidth 6
#define kAllPartonsTopHad_FixedTopM_FiniteWwidth 7
#define kAllPartonsHiggsWWLep_FixedHiggsM_FiniteWwidth 8
#define kAllPartonsAntiTopHad_FixedTopM_FiniteWwidth 9
#define kAllPartonsTTH_TopDecay 10
#define kAllPartonsTTH_TopLepDecayMwInt 11
#define kAllPartonsTTH_TopHadDecayMwInt 12
#define kAllPartonsTTLL 13

#define kMEM_TTH_TopAntitopHiggsDecay 14
#define kMEM_TTLL_TopAntitopDecay 15
#define kMEM_TTH_TopAntitopHiggsSemiLepDecay 16
#define kMEM_TTW_TopAntitopDecay 17
#define kMEM_TTWJJ_TopAntitopDecay 18
#define kMEM_TTbar_TopAntitopFullyLepDecay 19
#define kMEM_TTbar_TopAntitopSemiLepDecay 20
#define kMEM_TLLJ_TopLepDecay 21
#define kMEM_WZJJ_LepDecay 22
#define kMEM_THJ_TopLepDecay 23

#define kFixMw 1
#define kFixBenergy 2
#define kTwoBjorken 3
#define kOneBjorken 4
#define kTwoBjorkenSubMasses 5
#define kTwoBjorken1to3 6
#define kNoBjorken 7
#define kNoBjorkenMomentum 8

#define kMadgraph 0
#define kGosam 1

#define kTTH 0
#define kTTLL 1
#define kTTW 2
#define kTTWJJ 3
#define kTTbar 4
#define kTop 5
#define kAntitop 6
#define kTLLJ 7
#define kWZJJ 8
#define kTHJ 9

#define kHfullylep 0
#define kHsemilep 1
#define kLL 2
#define kLNu 3
#define kLNuJJ 4
#define kNoBoson -1
#define kLLJ 5
#define kLNuLLJJ 6
#define kHfullylepJ 7
#define kHsemilepJ 8

#define kNoTop -1
#define kTopLepDecay 0
#define kTopHadDecay 1

#define kErr_PS_Product 0
//#define kErr_TF_OutOfRange 3
#define kErr_TF_Product 1
#define kErr_ME 2
#define kErr_PDF 3
#define kErr_Weight_Product 4

#define kOptimizeNone 0
#define kOptimizeMw 1

#define kOptimizeTopLepTw 1
#define kOptimizeTopHadTw 1
#define kOptimizeHiggsTw 1
#define kOptimizeHiggsMw 2
#define kOptimizeWTw 1

#define kCat_3l_2b_2j 0
#define kCat_3l_1b_2j 1
#define kCat_3l_2b_1j 2
#define kCat_3l_1b_1j 3
#define kCat_3l_2b_0j 4
#define kCat_4l_2b 5
#define kCat_4l_1b 6
#define kCat_2lss_2b_4j 7
#define kCat_2lss_1b_4j 8
#define kCat_2lss_2b_3j 9
#define kCat_2lss_1b_3j 10
#define kCat_2lss_2b_2j 11

#define kCat_3l_1b_0j 12
#define kCat_3l_0b_1j 13
#define kCat_3l_0b_0j 14

#define kCat_2lss_2b_1j 15
#define kCat_2lss_1b_2j 16
#define kCat_2lss_1b_1j 17

using namespace std;
using namespace LHAPDF;

//GoSam
//extern "C" void OLP_Start(const char * filename, int* success);
//extern "C" void OLP_EvalSubProcess(int,double*,double,double*,double*);

class MEPhaseSpace 
{

  public:
    MEPhaseSpace();
    ~MEPhaseSpace();

    double Eval(const double* ) const;

    void InitializeLHAPDF(string); 
    void InitializeMadgraphProcesses(string);
    CPPProcess* process;
    CPPProcess_tbwjj* process_tbwjj;
    CPPProcess_tbwlnu* process_tbwlnu;
    CPPProcess_hw2l2nu* process_hw2l2nu;
    CPPProcess_antitbwjj* process_antitbwjj;
    CPPProcess_ggttll* process_ggttll;
    //CPPProcess_qqttlpvl* process_qqttlpvl;
    //CPPProcess_qqttlmvl* process_qqttlmvl;
    CPPProcess_P0_Sigma_sm_ckm_cdx_ttxepve* process_qqttlpvl_cdx;
    CPPProcess_P0_Sigma_sm_ckm_udx_ttxepve* process_qqttlpvl_udx;
    CPPProcess_P0_Sigma_sm_ckm_usx_ttxepve* process_qqttlpvl_usx;
    CPPProcess_P0_Sigma_sm_ckm_dcx_ttxemvex* process_qqttlmvl_dcx;
    CPPProcess_P0_Sigma_sm_ckm_dux_ttxemvex* process_qqttlmvl_dux;
    CPPProcess_P0_Sigma_sm_ckm_sux_ttxemvex* process_qqttlmvl_sux;
    CPPProcess_P0_Sigma_sm_ckm_gc_ttxepvegd* process_P0_Sigma_sm_ckm_gc_ttxepvegd;
    CPPProcess_P0_Sigma_sm_ckm_gdx_ttxepvegcx* process_P0_Sigma_sm_ckm_gdx_ttxepvegcx;
    CPPProcess_P0_Sigma_sm_ckm_gdx_ttxepvegux* process_P0_Sigma_sm_ckm_gdx_ttxepvegux;
    CPPProcess_P0_Sigma_sm_ckm_gsx_ttxepvegux* process_P0_Sigma_sm_ckm_gsx_ttxepvegux;
    CPPProcess_P0_Sigma_sm_ckm_gu_ttxepvegd* process_P0_Sigma_sm_ckm_gu_ttxepvegd;
    CPPProcess_P0_Sigma_sm_ckm_gu_ttxepvegs* process_P0_Sigma_sm_ckm_gu_ttxepvegs;
    CPPProcess_P0_Sigma_sm_ckm_gcx_ttxemvexgdx* process_P0_Sigma_sm_ckm_gcx_ttxemvexgdx;
    CPPProcess_P0_Sigma_sm_ckm_gd_ttxemvexgc* process_P0_Sigma_sm_ckm_gd_ttxemvexgc;
    CPPProcess_P0_Sigma_sm_ckm_gd_ttxemvexgu* process_P0_Sigma_sm_ckm_gd_ttxemvexgu;
    CPPProcess_P0_Sigma_sm_ckm_gs_ttxemvexgu* process_P0_Sigma_sm_ckm_gs_ttxemvexgu;
    CPPProcess_P0_Sigma_sm_ckm_gux_ttxemvexgdx* process_P0_Sigma_sm_ckm_gux_ttxemvexgdx;
    CPPProcess_P0_Sigma_sm_ckm_gux_ttxemvexgsx* process_P0_Sigma_sm_ckm_gux_ttxemvexgsx;
    CPPProcess_P0_Sigma_sm_gg_ttx* process_P0_Sigma_sm_gg_ttx;
    CPPProcess_P0_Sigma_sm_no_b_mass_dbx_txepemu* process_P0_Sigma_sm_no_b_mass_dbx_txepemu;
    CPPProcess_P0_Sigma_sm_no_b_mass_dxb_tepemux* process_P0_Sigma_sm_no_b_mass_dxb_tepemux;
    CPPProcess_P0_Sigma_sm_no_b_mass_ub_tepemd* process_P0_Sigma_sm_no_b_mass_ub_tepemd;
    CPPProcess_P0_Sigma_sm_no_b_mass_uxbx_txepemdx* process_P0_Sigma_sm_no_b_mass_uxbx_txepemdx;
    CPPProcess_P0_Sigma_sm_gdx_epvemupmumgux* process_P0_Sigma_sm_gdx_epvemupmumgux;
    CPPProcess_P0_Sigma_sm_gu_epvemupmumgd* process_P0_Sigma_sm_gu_epvemupmumgd;
    CPPProcess_P0_Sigma_sm_no_b_mass_dbx_txhu* process_P0_Sigma_sm_no_b_mass_dbx_txhu;
    CPPProcess_P0_Sigma_sm_no_b_mass_dxb_thux* process_P0_Sigma_sm_no_b_mass_dxb_thux;
    CPPProcess_P0_Sigma_sm_no_b_mass_ub_thd* process_P0_Sigma_sm_no_b_mass_ub_thd;
    CPPProcess_P0_Sigma_sm_no_b_mass_uxbx_txhdx* process_P0_Sigma_sm_no_b_mass_uxbx_txhdx;


    const LHAPDF::PDF* pdf;

    double GeV2barn;              // Conversion factor 1/GeV^2 ->pb

    int iMode;
    int iNleptons;
    int iOption;
    int iGen;
    int iCore;
    int nExternals, nCoreExternals;
    mutable int iCall;
    mutable int iIteration;
    int nparam;
    int iOptim, iOptimTopLep, iOptimTopHad, iOptimHiggs, iOptimW;
    int iMinimize;
    double JetTFfracmin, JetTFfracmax, NeutMaxE;

    double MEMZEROWEIGHT;
    mutable double weight_max;
    mutable std::vector<double> weight_max_intvar;

    mutable int isTopAntitop;

    double comEnergy;
    mutable double muF;
    double mTop;
    double mHiggs;
    double mW;
    double mZ;
    double mB;
    double gammaTop;
    double gammaHiggs;
    double gammaW;

    double xsTTH;
    double xsTTLL;
    double xsTTW;
    double xsTTbar;
    double xsTLLJ;
    double xsWZJJ;
    double xsTHJ;
    double brTopLep;
    double brTopHad;
    double brHiggsFullLep;

    mutable int errorCounter[20];

    int CheckMomentum(TLorentzVector&, double) const;

    mutable vector<double*> * pCore; //phase-space point
    mutable vector<double*> * pTop; //phase-space point
    mutable vector<double*> * pAntitop; //phase-space point
    mutable vector<double*> * pHiggs; //phase-space point

    void InitializePhaseSpacePoint(vector<double*> **, int);
    void FillTTHPhaseSpacePoint(TLorentzVector&, TLorentzVector&, TLorentzVector&) const;
    void FillTTLLPhaseSpacePoint(TLorentzVector&, TLorentzVector&, TLorentzVector&, TLorentzVector&) const;
    void FillTTLNuJJPhaseSpacePoint(TLorentzVector&, TLorentzVector&, TLorentzVector&, TLorentzVector&, TLorentzVector&, TLorentzVector&) const;
    void FillTopDecayPhaseSpacePoint(TLorentzVector&, TLorentzVector&, TLorentzVector&, TLorentzVector&, int) const;
    void FillHiggsDecayPhaseSpacePoint(TLorentzVector&, TLorentzVector&, TLorentzVector&, TLorentzVector&, TLorentzVector&) const;
    void FillTTbarPhaseSpacePoint(TLorentzVector&, TLorentzVector&) const;

    double Wenergy;
    double Benergy;

    void SetComEnergy(double);
    void SetInitialPartonMomenta(const double, const double) const;
    void SetFinalStatePartonMomenta(double**, int) const;
    void SetAllPartonMomenta(vector<double*> *, vector<double*>);
    void ReadPartonMomenta(vector<double*> *, int ) const;
    vector<double*> GetPhaseSpacePoint();

    void SetNleptonMode(int );
    void SetIntegrationMode(int );
    void SetOption(int );
    void SetGenerator(int);
    void SetOptimization(int);
    void SetOptimization(int,int,int,int);
    void SetMinimization(int);

    int GetNumberIntegrationVar(int, int);

    void AddIntegVar_TopHad(int, const double *, int*) const;
    void AddIntegVar_TopLep(int, const double *, int*, int) const;
    void AddIntegVar_HiggsFullyLep(int, const double *, int*) const;
    void AddIntegVar_HiggsSemiLep(int, const double *, int*) const;
    void AddIntegVar_Woffshell(int, const double *, int*) const;
    void AddIntegVar_Zoffshell(int, const double *, int*) const;
    void AddIntegVar_TwoJets(int, const double *, int*) const;
    void AddIntegVar_OneJet(int, const double *, int*) const;

    double SetupKinematicsTTH(const double *) const;
    double SetupKinematicsTopHad(const double *) const;
    double SetupKinematicsTopHad_FiniteWidths(const double *) const;
    double SetupKinematicsTopLep(const double *) const; 
    double SetupKinematicsTopLep_FixedTopM_FiniteWwidth(const double *) const; 
    double SetupKinematicsTopHad_FixedTopM_FiniteWwidth(const double *) const;
    double SetupKinematicsHiggsWWLep_FixedHiggsM_FiniteWwidth(const double *) const;
    double SetupKinematics1to3_LabFrame(const double *) const;
    double SetupKinematics2to3_LabFrame_OneBjorken(const double *) const;
    double SetupKinematics2to3_LabFrame_NoBjorken(const double *) const;

    double SetupKinematicsTTH_NoBjorken_TopHadDecay(const double*) const;
    double SetupKinematicsTTH_NoBjorken_TopLepDecayMwInt(const double*) const;
    double SetupKinematicsTTH_NoBjorken_TopHadDecayMwInt(const double*) const;

    double SetupKinematics_TopHadDecay_WithTopPhaseSpace(const double*, TLorentzVector*, int, int) const;
    double SetupKinematics_TopLepDecay_WithTopPhaseSpace_MwInt(const double*, TLorentzVector*, int, int) const;
    double SetupKinematics_TopHadDecay_WithTopPhaseSpace_MwInt(const double*, TLorentzVector*, int, int) const;
    double SetupKinematics_Higgs2l2nuDecay_WithHiggsPhaseSpace(const double*, TLorentzVector*) const;
    double SetupKinematics_HiggsDecay_WithHiggsPhaseSpace_MwInt(const double*, TLorentzVector*) const;
    double SetupKinematics_TopDecay_WithTopPhaseSpace_Generic(const double*, TLorentzVector*, int, int) const;
    double SetupKinematics_HiggsDecay_WithHiggsPhaseSpace_Generic(const double*, TLorentzVector*) const;
    double SetupKinematics_Wlnu_WithBreitWigner_Generic(const double*, TLorentzVector*, TLorentzVector*) const;

    double SetupKinematics2to4_LabFrame_NoBjorken(const double *) const;
    double SetupKinematicsTTH_NoBjorken_TopAntitopHiggsDecay(const double*) const;
    double SetupKinematicsTTLL_NoBjorken_TopAntitopDecay(const double*) const;
    double SetupKinematicsTTW_NoBjorken_TopAntitopDecay(const double*) const;
    double SetupKinematicsTTWJJ_NoBjorken_TopAntitopDecay(const double*) const;
    double SetupKinematicsTTbar_NoBjorken_TopAntitopDecay(const double*) const;
    double SetupKinematicsTLLJ_NoBjorken_TopDecay(const double*) const;
    double SetupKinematicsWZJJ_NoBjorken(const double*) const;
    double SetupKinematicsTHJ_NoBjorken_TopDecay(const double*) const;

    void ApplyTotalTransverseBoost() const;

    void CheckMatrixElement();
    double ComputeMatrixElement() const;
    double ComputeSubMatrixElement(int , int , int ) const;	
    double BreitWigner(double, double, double) const;
    double KallenFunction(double , double , double ) const;
    double ComputeDecayMomenta(TLorentzVector& , double, double, double , double , TLorentzVector* , TLorentzVector* ) const;
    int SetMomentumFromEThetaPhi(double, double, double, double, TLorentzVector*) const;
    double TransformTwToMw(double) const;

    double ComputePDF(double, double, double) const;
    double ConvolvePdfCrossSection(double, double, double) const;

    TransferFunctions* transferFunctions;

    void UpdateKinVar() const;
    double KinComputeWmass(double* , double* ) const;

    double ComputeTFProduct() const;
    void UpdateComputedVarForTF() const;
    void FillComputedJetForTF(double*, double*, double*) const;

    struct FinalStateTTV {
      int Boson_Type;
      int Top1_Decay;
      int Top1_Sign;
      int Top2_Decay;
      int Top2_Sign; 
    } FinalStateTTV;

    mutable TLorentzVector Computed_mETvect;
 
    double* y;
    mutable double* xMEM;

    struct MEMFix_TopHad {
      double Bjet_Theta;
      double Bjet_Phi;
      double Jet1_Theta;
      double Jet1_Phi;
      double Jet2_Theta;
      double Jet2_Phi;
      int TopSign;
      int isBmissing;
      int isJmissing;
    } MEMFix_TopHad;

    struct MEMFix_TopLep {
      double Bjet_Theta;
      double Bjet_Phi;
      double Lep_E;
      double Lep_Theta;
      double Lep_Phi;
      int TopSign;
      int isBmissing;
    } MEMFix_TopLep, MEMFix_TopLep2;

    struct MEMFix_HiggsFullLep {
      double Lep1_E;
      double Lep1_Theta;
      double Lep1_Phi;
      double Lep2_E;
      double Lep2_Theta;
      double Lep2_Phi;
    } MEMFix_HiggsFullLep;

    struct MEMFix_HiggsSemiLep {
      double Lep1_E;
      double Lep1_Theta;
      double Lep1_Phi;
      double Jet1_Theta;
      double Jet1_Phi;
      double Jet2_Theta;
      double Jet2_Phi;
      int LepSign;
      int isJmissing;
    } MEMFix_HiggsSemiLep;

    struct MEMFix_OtherJets {
      double Jet1_Theta;
      double Jet1_Phi;
      double Jet2_Theta;
      double Jet2_Phi;
      int isJmissing;
    } MEMFix_OtherJets;

    mutable struct MEMKin_TopHad {
      TLorentzVector Top_P4;
      TLorentzVector W_P4;
      TLorentzVector Bjet_P4;
      TLorentzVector Jet1_P4;
      TLorentzVector Jet2_P4;
      double Top_Pt;
      double W_Mass;
      double B_E;
      double Jet1_E;
      double Jet2_E;
    } MEMKin_TopHad;
   
    mutable struct MEMKin_TopLep {
      TLorentzVector Top_P4;
      TLorentzVector W_P4;
      TLorentzVector Bjet_P4;
      TLorentzVector Lep_P4;
      TLorentzVector Neut_P4;
      double Top_Pt;
      double W_Mass;
      double B_E;
      double Neut_E;
    } MEMKin_TopLep1, MEMKin_TopLep2;

    mutable struct MEMKin_Wlnu {
      TLorentzVector W_P4;
      TLorentzVector Lep_P4;
      TLorentzVector Neut_P4;
      double W_Pt;
      double W_Mass;
      double Neut_E;
    } MEMKin_Wlnu, MEMKin_Wlnu_tmp;

    mutable struct MEMKin_Zll {
      TLorentzVector Z_P4;
      TLorentzVector Lep1_P4;
      TLorentzVector Lep2_P4;
      double Z_Mass;
      double Z_Pt;
    } MEMKin_Zll, MEMKin_Zll_tmp;

    mutable struct MEMKin_H2l2nu {
      TLorentzVector Higgs_P4;
      TLorentzVector W1_P4;
      TLorentzVector W2_P4;
      TLorentzVector Lep1_P4;
      TLorentzVector Lep2_P4;
      TLorentzVector Neut1_P4;
      TLorentzVector Neut2_P4;
      double Higgs_Pt;
      double W1_Mass;
      double Neut1_E;
      double W2_Mass;
      double Neut2_E;
    } MEMKin_H2l2nu;

    mutable struct MEMKin_Hlnujj {
      TLorentzVector Higgs_P4;
      TLorentzVector W1_P4;
      TLorentzVector W2_P4;
      TLorentzVector Lep_P4;
      TLorentzVector Neut_P4;
      TLorentzVector Jet1_P4;
      TLorentzVector Jet2_P4;
      double Higgs_Pt;
      double Wlnu_Mass;
      double Neut_E;
      double Wjj_Mass;
      double Jet1_E;
      double Jet2_E;
    } MEMKin_Hlnujj;

    int verbosity;
    void SetVerbosity(int);
};

#endif
