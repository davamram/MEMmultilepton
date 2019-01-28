#ifndef TOOLS_H
#define TOOLS_H

#include "Permutations.h"

void CombineHypotheses(Permutations Perm1, Permutations Perm2, double *weight_mean, double* weight_log, double *weight_err, double* weight_chi2, double* weight_time, double *weight_avg, double* weight_max, double* weight_logmean, double* weight_kin_log, double* weight_kin_logint, double* weight_kinmax, double* weight_kinmaxint, double* weight_JEC_up, double* weight_JEC_down, double* weight_JER_up, double* weight_JER_down);

void CombineTwoHypotheses(Permutations* Perm1, int iPerm1, Permutations* Perm2, int iPerm2, Permutations* PermMean);

void FillWeightVectors(Permutations Perm, std::vector<double>* MEAllWeights, std::vector<float>* MEAllWeights_log);

#endif
