//==========================================================================
// This file has been automatically generated for C++ Standalone by
// MadGraph5_aMC@NLO v. 3.4.0, 2022-05-06
// By the MadGraph5_aMC@NLO Development Team
// Visit launchpad.net/madgraph5 and amcatnlo.web.cern.ch
//==========================================================================

#ifndef MG5_Sigma_dim6top_LO_UFO_ctl2_17_uux_bepvebxemvexepem_H
#define MG5_Sigma_dim6top_LO_UFO_ctl2_17_uux_bepvebxemvexepem_H

#include <complex> 
#include <vector> 

#include "Parameters_dim6top_LO_UFO_ctl2_17.h"

using namespace std; 

//==========================================================================
// A class for calculating the matrix elements for
// Process: u u~ > t t~ e+ e- DIM6<=1 QCD<=2 QED<=2 @1
// *   Decay: t > b e+ ve DIM6=0 QED<=2
// *   Decay: t~ > b~ e- ve~ DIM6=0 QED<=2
// Process: c c~ > t t~ e+ e- DIM6<=1 QCD<=2 QED<=2 @1
// *   Decay: t > b e+ ve DIM6=0 QED<=2
// *   Decay: t~ > b~ e- ve~ DIM6=0 QED<=2
//--------------------------------------------------------------------------

class CPPProcess_P1_Sigma_dim6top_LO_UFO_ctl2_17_uux_bepvebxemvexepem
{
  public:

    // Constructor.
    CPPProcess_P1_Sigma_dim6top_LO_UFO_ctl2_17_uux_bepvebxemvexepem() {}

    // Initialize process.
    virtual void initProc(string param_card_name); 

    // Calculate flavour-independent parts of cross section.
    virtual void sigmaKin(); 

    // Evaluate sigmaHat(sHat).
    virtual double sigmaHat(); 

    // Info on the subprocess.
    virtual string name() const {return "u u~ > b e+ ve b~ e- ve~ e+ e- (dim6top_LO_UFO_ctl2_17)";}

    virtual int code() const {return 1;}

    const vector<double> & getMasses() const {return mME;}

    // Get and set momenta for matrix element evaluation
    vector < double * > getMomenta(){return p;}
    void setMomenta(vector < double * > & momenta){p = momenta;}
    void setInitial(int inid1, int inid2){id1 = inid1; id2 = inid2;}

    // Get matrix element vector
    const double * getMatrixElements() const {return matrix_element;}

    // Constants for array limits
    static const int ninitial = 2; 
    static const int nexternal = 10; 
    static const int nprocesses = 2; 

  private:

    // Private functions to calculate the matrix element for all subprocesses
    // Calculate wavefunctions
    void calculate_wavefunctions(const int perm[], const int hel[]); 
    static const int nwavefuncs = 23; 
    std::complex<double> w[nwavefuncs][18]; 
    static const int namplitudes = 8; 
    std::complex<double> amp[namplitudes]; 
    double matrix_1_uux_ttxepem_t_bepve_tx_bxemvex(); 

    // Store the matrix element value from sigmaKin
    double matrix_element[nprocesses]; 

    // Color flows, used when selecting color
    double * jamp2[nprocesses]; 

    // Pointer to the model parameters
    Parameters_dim6top_LO_UFO_ctl2_17 * pars; 

    // vector with external particle masses
    vector<double> mME; 

    // vector with momenta (to be changed each event)
    vector < double * > p; 
    // Initial particle ids
    int id1, id2; 

}; 


#endif  // MG5_Sigma_dim6top_LO_UFO_ctl2_17_uux_bepvebxemvexepem_H
