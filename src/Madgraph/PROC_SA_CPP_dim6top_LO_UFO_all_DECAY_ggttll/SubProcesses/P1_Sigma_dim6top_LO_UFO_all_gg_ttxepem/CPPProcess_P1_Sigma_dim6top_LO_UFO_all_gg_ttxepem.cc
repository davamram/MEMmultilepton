//==========================================================================
// This file has been automatically generated for C++ Standalone by
// MadGraph5_aMC@NLO v. 3.4.0, 2022-05-06
// By the MadGraph5_aMC@NLO Development Team
// Visit launchpad.net/madgraph5 and amcatnlo.web.cern.ch
//==========================================================================

#include "CPPProcess_P1_Sigma_dim6top_LO_UFO_all_gg_ttxepem.h"
#include "HelAmps_dim6top_LO_UFO_all_ggttll.h"

using namespace MG5_dim6top_LO_UFO_all_ggttll;

//==========================================================================
// Class member functions for calculating the matrix elements for
// Process: g g > t t~ e+ e- DIM6<=1 QCD<=2 QED<=2 @1

//--------------------------------------------------------------------------
// Initialize process.

void CPPProcess_P1_Sigma_dim6top_LO_UFO_all_gg_ttxepem::initProc(string param_card_name)
{
  // Instantiate the model class and set parameters that stay fixed during run
  pars = Parameters_dim6top_LO_UFO_all_ggttll::getInstance();
  SLHAReader slha(param_card_name);
  pars->setIndependentParameters(slha);
  pars->setIndependentCouplings();
  //pars->printIndependentParameters();
  //pars->printIndependentCouplings();
  // Set external particle masses for this matrix element
  mME.push_back(pars->ZERO);
  mME.push_back(pars->ZERO);
  mME.push_back(pars->mdl_MT);
  mME.push_back(pars->mdl_MT);
  mME.push_back(pars->ZERO);
  mME.push_back(pars->ZERO);
  jamp2[0] = new double[2];
}

//--------------------------------------------------------------------------
// Evaluate |M|^2, part independent of incoming flavour.

void CPPProcess_P1_Sigma_dim6top_LO_UFO_all_gg_ttxepem::sigmaKin()
{
  // Set the parameters which change event by event
  pars->setDependentParameters();
  pars->setDependentCouplings();
  static bool firsttime = true;
  if (firsttime)
  {
    //pars->printDependentParameters();
    //pars->printDependentCouplings();
    firsttime = false;
  }

  // Reset color flows
  for(int i = 0; i < 2; i++ )
    jamp2[0][i] = 0.;

  // Local variables and constants
  const int ncomb = 64;
  static bool goodhel[ncomb] = {ncomb * false};
  static int ntry = 0, sum_hel = 0, ngood = 0;
  static int igood[ncomb];
  static int jhel;
  std::complex<double> * * wfs;
  double t[nprocesses];
  // Helicities for the process
  static const int helicities[ncomb][nexternal] = {{-1, -1, -1, -1, -1, -1},
      {-1, -1, -1, -1, -1, 1}, {-1, -1, -1, -1, 1, -1}, {-1, -1, -1, -1, 1, 1},
      {-1, -1, -1, 1, -1, -1}, {-1, -1, -1, 1, -1, 1}, {-1, -1, -1, 1, 1, -1},
      {-1, -1, -1, 1, 1, 1}, {-1, -1, 1, -1, -1, -1}, {-1, -1, 1, -1, -1, 1},
      {-1, -1, 1, -1, 1, -1}, {-1, -1, 1, -1, 1, 1}, {-1, -1, 1, 1, -1, -1},
      {-1, -1, 1, 1, -1, 1}, {-1, -1, 1, 1, 1, -1}, {-1, -1, 1, 1, 1, 1}, {-1,
      1, -1, -1, -1, -1}, {-1, 1, -1, -1, -1, 1}, {-1, 1, -1, -1, 1, -1}, {-1,
      1, -1, -1, 1, 1}, {-1, 1, -1, 1, -1, -1}, {-1, 1, -1, 1, -1, 1}, {-1, 1,
      -1, 1, 1, -1}, {-1, 1, -1, 1, 1, 1}, {-1, 1, 1, -1, -1, -1}, {-1, 1, 1,
      -1, -1, 1}, {-1, 1, 1, -1, 1, -1}, {-1, 1, 1, -1, 1, 1}, {-1, 1, 1, 1,
      -1, -1}, {-1, 1, 1, 1, -1, 1}, {-1, 1, 1, 1, 1, -1}, {-1, 1, 1, 1, 1, 1},
      {1, -1, -1, -1, -1, -1}, {1, -1, -1, -1, -1, 1}, {1, -1, -1, -1, 1, -1},
      {1, -1, -1, -1, 1, 1}, {1, -1, -1, 1, -1, -1}, {1, -1, -1, 1, -1, 1}, {1,
      -1, -1, 1, 1, -1}, {1, -1, -1, 1, 1, 1}, {1, -1, 1, -1, -1, -1}, {1, -1,
      1, -1, -1, 1}, {1, -1, 1, -1, 1, -1}, {1, -1, 1, -1, 1, 1}, {1, -1, 1, 1,
      -1, -1}, {1, -1, 1, 1, -1, 1}, {1, -1, 1, 1, 1, -1}, {1, -1, 1, 1, 1, 1},
      {1, 1, -1, -1, -1, -1}, {1, 1, -1, -1, -1, 1}, {1, 1, -1, -1, 1, -1}, {1,
      1, -1, -1, 1, 1}, {1, 1, -1, 1, -1, -1}, {1, 1, -1, 1, -1, 1}, {1, 1, -1,
      1, 1, -1}, {1, 1, -1, 1, 1, 1}, {1, 1, 1, -1, -1, -1}, {1, 1, 1, -1, -1,
      1}, {1, 1, 1, -1, 1, -1}, {1, 1, 1, -1, 1, 1}, {1, 1, 1, 1, -1, -1}, {1,
      1, 1, 1, -1, 1}, {1, 1, 1, 1, 1, -1}, {1, 1, 1, 1, 1, 1}};
  // Denominators: spins, colors and identical particles
  const int denominators[nprocesses] = {256};

  ntry = ntry + 1;

  // Reset the matrix elements
  for(int i = 0; i < nprocesses; i++ )
  {
    matrix_element[i] = 0.;
  }
  // Define permutation
  int perm[nexternal];
  for(int i = 0; i < nexternal; i++ )
  {
    perm[i] = i;
  }

  if (sum_hel == 0 || ntry < 10)
  {
    // Calculate the matrix element for all helicities
    for(int ihel = 0; ihel < ncomb; ihel++ )
    {
      if (goodhel[ihel] || ntry < 2)
      {
        calculate_wavefunctions(perm, helicities[ihel]);
        t[0] = matrix_1_gg_ttxepem();

        double tsum = 0;
        for(int iproc = 0; iproc < nprocesses; iproc++ )
        {
          matrix_element[iproc] += t[iproc];
          tsum += t[iproc];
        }
        // Store which helicities give non-zero result
        if (tsum != 0. && !goodhel[ihel])
        {
          goodhel[ihel] = true;
          ngood++;
          igood[ngood] = ihel;
        }
      }
    }
    jhel = 0;
    sum_hel = min(sum_hel, ngood);
  }
  else
  {
    // Only use the "good" helicities
    for(int j = 0; j < sum_hel; j++ )
    {
      jhel++;
      if (jhel >= ngood)
        jhel = 0;
      double hwgt = double(ngood)/double(sum_hel);
      int ihel = igood[jhel];
      calculate_wavefunctions(perm, helicities[ihel]);
      t[0] = matrix_1_gg_ttxepem();

      for(int iproc = 0; iproc < nprocesses; iproc++ )
      {
        matrix_element[iproc] += t[iproc] * hwgt;
      }
    }
  }

  for (int i = 0; i < nprocesses; i++ )
    matrix_element[i] /= denominators[i];



}

//--------------------------------------------------------------------------
// Evaluate |M|^2, including incoming flavour dependence.

double CPPProcess_P1_Sigma_dim6top_LO_UFO_all_gg_ttxepem::sigmaHat()
{
  // Select between the different processes
  if(id1 == 21 && id2 == 21)
  {
    // Add matrix elements for processes with beams (21, 21)
    return matrix_element[0];
  }
  else
  {
    // Return 0 if not correct initial state assignment
    return 0.;
  }
}

//==========================================================================
// Private class member functions

//--------------------------------------------------------------------------
// Evaluate |M|^2 for each subprocess

void CPPProcess_P1_Sigma_dim6top_LO_UFO_all_gg_ttxepem::calculate_wavefunctions(const int perm[], const int hel[])
{
  // Calculate wavefunctions for all processes
  int i, j;

  // Calculate all wavefunctions
  vxxxxx(p[perm[0]], mME[0], hel[0], -1, w[0]);
  vxxxxx(p[perm[1]], mME[1], hel[1], -1, w[1]);
  oxxxxx(p[perm[2]], mME[2], hel[2], +1, w[2]);
  ixxxxx(p[perm[3]], mME[3], hel[3], -1, w[3]);
  ixxxxx(p[perm[4]], mME[4], hel[4], -1, w[4]);
  oxxxxx(p[perm[5]], mME[5], hel[5], +1, w[5]);
  VVV1P0_1(w[0], w[1], pars->GC_6, pars->ZERO, pars->ZERO, w[6]);
  FFV1P0_3(w[4], w[5], pars->GC_3, pars->ZERO, pars->ZERO, w[7]);
  FFV6_1(w[2], w[6], pars->GC_7, pars->mdl_MT, pars->mdl_WT, w[8]);
  FFV6_2(w[3], w[6], pars->GC_7, pars->mdl_MT, pars->mdl_WT, w[9]);
  FFV2_7_3(w[4], w[5], pars->GC_650, pars->GC_661, pars->mdl_MZ, pars->mdl_WZ,
      w[10]);
  FFV6_1(w[2], w[0], pars->GC_7, pars->mdl_MT, pars->mdl_WT, w[11]);
  FFV6_2(w[3], w[1], pars->GC_7, pars->mdl_MT, pars->mdl_WT, w[12]);
  FFV6_1(w[11], w[1], pars->GC_7, pars->mdl_MT, pars->mdl_WT, w[13]);
  FFV6_2(w[3], w[0], pars->GC_7, pars->mdl_MT, pars->mdl_WT, w[14]);
  FFV6_1(w[2], w[1], pars->GC_7, pars->mdl_MT, pars->mdl_WT, w[15]);
  FFV6_2(w[14], w[1], pars->GC_7, pars->mdl_MT, pars->mdl_WT, w[16]);
  FFV6_1(w[15], w[0], pars->GC_7, pars->mdl_MT, pars->mdl_WT, w[17]);
  FFV6_2(w[12], w[0], pars->GC_7, pars->mdl_MT, pars->mdl_WT, w[18]);

  // Calculate all amplitudes
  // Amplitude(s) for diagram number 0
  FFV6_0(w[3], w[8], w[7], pars->GC_2, amp[0]);
  FFV6_0(w[9], w[2], w[7], pars->GC_2, amp[1]);
  FFV2_8_0(w[3], w[8], w[10], -pars->GC_650, pars->GC_660, amp[2]);
  FFV2_8_0(w[9], w[2], w[10], -pars->GC_650, pars->GC_660, amp[3]);
  FFV6_0(w[12], w[11], w[7], pars->GC_2, amp[4]);
  FFV2_8_0(w[12], w[11], w[10], -pars->GC_650, pars->GC_660, amp[5]);
  FFV6_0(w[3], w[13], w[7], pars->GC_2, amp[6]);
  FFV2_8_0(w[3], w[13], w[10], -pars->GC_650, pars->GC_660, amp[7]);
  FFV6_0(w[14], w[15], w[7], pars->GC_2, amp[8]);
  FFV2_8_0(w[14], w[15], w[10], -pars->GC_650, pars->GC_660, amp[9]);
  FFV6_0(w[16], w[2], w[7], pars->GC_2, amp[10]);
  FFV2_8_0(w[16], w[2], w[10], -pars->GC_650, pars->GC_660, amp[11]);
  FFV6_0(w[3], w[17], w[7], pars->GC_2, amp[12]);
  FFV2_8_0(w[3], w[17], w[10], -pars->GC_650, pars->GC_660, amp[13]);
  FFV6_0(w[18], w[2], w[7], pars->GC_2, amp[14]);
  FFV2_8_0(w[18], w[2], w[10], -pars->GC_650, pars->GC_660, amp[15]);

}
double CPPProcess_P1_Sigma_dim6top_LO_UFO_all_gg_ttxepem::matrix_1_gg_ttxepem()
{
  int i, j;
  // Local variables
  const int ngraphs = 16;
  const int ncolor = 2;
  std::complex<double> ztemp;
  std::complex<double> jamp[ncolor];
  // The color matrix;
  static const double denom[ncolor] = {3, 3};
  static const double cf[ncolor][ncolor] = {{16, -2}, {-2, 16}};

  // Calculate color flows
  jamp[0] = +std::complex<double> (0, 1) * amp[0] + std::complex<double> (0, 1)
      * amp[1] + std::complex<double> (0, 1) * amp[2] + std::complex<double>
      (0, 1) * amp[3] - amp[4] - amp[5] - amp[6] - amp[7] - amp[14] - amp[15];
  jamp[1] = -std::complex<double> (0, 1) * amp[0] - std::complex<double> (0, 1)
      * amp[1] - std::complex<double> (0, 1) * amp[2] - std::complex<double>
      (0, 1) * amp[3] - amp[8] - amp[9] - amp[10] - amp[11] - amp[12] - amp[13];

  // Sum and square the color flows to get the matrix element
  double matrix = 0;
  for(i = 0; i < ncolor; i++ )
  {
    ztemp = 0.;
    for(j = 0; j < ncolor; j++ )
      ztemp = ztemp + cf[i][j] * jamp[j];
    matrix = matrix + real(ztemp * conj(jamp[i]))/denom[i];
  }

  // Store the leading color flows for choice of color
  for(i = 0; i < ncolor; i++ )
    jamp2[0][i] += real(jamp[i] * conj(jamp[i]));

  return matrix;
}
