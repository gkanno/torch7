#ifndef TH_AVX2_H
#define TH_AVX2_H

#include <stddef.h>
#include "THGeneral.h"

TH_API void THDoubleVector_cadd_AVX2(double *z, const double *x, const double *y, const double c, const ptrdiff_t n);
TH_API void THFloatVector_cadd_AVX2(float *z, const float *x, const float *y, const float c, const ptrdiff_t n);

#endif