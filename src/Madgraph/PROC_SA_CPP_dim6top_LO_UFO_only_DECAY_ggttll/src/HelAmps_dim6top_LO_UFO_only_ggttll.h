//==========================================================================
// This file has been automatically generated for C++ Standalone
// MadGraph5_aMC@NLO v. 3.4.0, 2022-05-06
// By the MadGraph5_aMC@NLO Development Team
// Visit launchpad.net/madgraph5 and amcatnlo.web.cern.ch
//==========================================================================

#ifndef HelAmps_dim6top_LO_UFO_only_ggttll_H
#define HelAmps_dim6top_LO_UFO_only_ggttll_H

#include <cmath> 
#include <complex> 

using namespace std; 

namespace MG5_dim6top_LO_UFO_only_ggttll 
{
double Sgn(double e, double f); 

void oxxxxx(double p[4], double fmass, int nhel, int nsf, std::complex<double>
    fo[6]);

void sxxxxx(double p[4], int nss, std::complex<double> sc[3]); 

void ixxxxx(double p[4], double fmass, int nhel, int nsf, std::complex<double>
    fi[6]);

void txxxxx(double p[4], double tmass, int nhel, int nst, std::complex<double>
    fi[18]);

void vxxxxx(double p[4], double vmass, int nhel, int nsv, std::complex<double>
    v[6]);

void FFV6_0(std::complex<double> F1[], std::complex<double> F2[],
    std::complex<double> V3[], std::complex<double> COUP, std::complex<double>
    & vertex);

void FFV6_1(std::complex<double> F2[], std::complex<double> V3[],
    std::complex<double> COUP, double M1, double W1, std::complex<double> F1[]);

void FFV6_2(std::complex<double> F1[], std::complex<double> V3[],
    std::complex<double> COUP, double M2, double W2, std::complex<double> F2[]);

void VVV1P0_1(std::complex<double> V2[], std::complex<double> V3[],
    std::complex<double> COUP, double M1, double W1, std::complex<double> V1[]);

void FFFF18_0(std::complex<double> F1[], std::complex<double> F2[],
    std::complex<double> F3[], std::complex<double> F4[], std::complex<double>
    COUP, std::complex<double> & vertex);

void FFFF18_3(std::complex<double> F1[], std::complex<double> F2[],
    std::complex<double> F4[], std::complex<double> COUP, double M3, double W3,
    std::complex<double> F3[]);

void FFFF18_4(std::complex<double> F1[], std::complex<double> F2[],
    std::complex<double> F3[], std::complex<double> COUP, double M4, double W4,
    std::complex<double> F4[]);

void FFV1P0_3(std::complex<double> F1[], std::complex<double> F2[],
    std::complex<double> COUP, double M3, double W3, std::complex<double> V3[]);

}  // end namespace MG5_dim6top_LO_UFO_only_ggttll

#endif  // HelAmps_dim6top_LO_UFO_only_ggttll_H
