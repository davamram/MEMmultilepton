//==========================================================================
// This file has been automatically generated for C++
// MadGraph5_aMC@NLO v. 3.4.0, 2022-05-06
// By the MadGraph5_aMC@NLO Development Team
// Visit launchpad.net/madgraph5 and amcatnlo.web.cern.ch
//==========================================================================

#ifndef Parameters_dim6top_LO_UFO_only_ggttll_H
#define Parameters_dim6top_LO_UFO_only_ggttll_H

#include <complex> 

#include "../../PROC_SA_CPP_sm_4/src/read_slha.h"
using namespace std; 

class Parameters_dim6top_LO_UFO_only_ggttll
{
  public:

    static Parameters_dim6top_LO_UFO_only_ggttll * getInstance(); 

    // Define "zero"
    double zero, ZERO; 
    // Model parameters independent of aS
    double mdl_WH, mdl_WW, mdl_WZ, mdl_WT, mdl_ymtau, mdl_ymt, mdl_ymb, aS,
        mdl_Gf, aEWM1, mdl_MH, mdl_MZ, mdl_MTA, mdl_MT, mdl_MB, mdl_cte2,
        mdl_cte1, mdl_ctl2, mdl_ctl1, mdl_Lambda, mdl_sqrt__2, mdl_sq2,
        mdl_vev, mdl_MZ__exp__2, mdl_MZ__exp__4, mdl_MH__exp__2,
        mdl_vev__exp__2, mdl_lam, mdl_yb, mdl_yt, mdl_ytau, mdl_muH,
        mdl_Lambda__exp__2, mdl_aEW, mdl_MW, mdl_MW__exp__2, mdl_sw2, mdl_cw,
        mdl_sqrt__sw2, mdl_sw, mdl_sqrt__aEW, mdl_ee, mdl_g1, mdl_gw,
        mdl_ee__exp__2, mdl_sw__exp__2, mdl_cw__exp__2;
    std::complex<double> mdl_complexi; 
    // Model parameters dependent on aS
    double mdl_sqrt__aS, G, mdl_G__exp__2; 
    // Model couplings independent of aS
    std::complex<double> GC_585; 
    // Model couplings dependent on aS
    std::complex<double> GC_6, GC_7; 

    // Set parameters that are unchanged during the run
    void setIndependentParameters(SLHAReader& slha); 
    // Set couplings that are unchanged during the run
    void setIndependentCouplings(); 
    // Set parameters that are changed event by event
    void setDependentParameters(); 
    // Set couplings that are changed event by event
    void setDependentCouplings(); 

    // Print parameters that are unchanged during the run
    void printIndependentParameters(); 
    // Print couplings that are unchanged during the run
    void printIndependentCouplings(); 
    // Print parameters that are changed event by event
    void printDependentParameters(); 
    // Print couplings that are changed event by event
    void printDependentCouplings(); 


  private:
    static Parameters_dim6top_LO_UFO_only_ggttll * instance; 
}; 

#endif  // Parameters_dim6top_LO_UFO_only_ggttll_H

