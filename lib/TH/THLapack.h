#ifndef TH_LAPACK_INC
#define TH_LAPACK_INC

#include "THGeneral.h"

#define THLapack_(NAME) TH_CONCAT_4(TH,Real,Lapack_,NAME)

#define THLapackCheck(fmt, func, info , ...)						\
if (info < 0) {														\
  THError("Lapack Error in %s : Illegal Argument %d", func, -info); \
} else if(info > 0) {												\
  THError(fmt, func, info, ##__VA_ARGS__);							\
}																	\

#define THLapackCheckWithCleanup(fmt, cleanup, func, info , ...)    \
if (info < 0) {                                                     \
  cleanup                                                           \
  THError("Lapack Error in %s : Illegal Argument %d", func, -info); \
} else if(info > 0) {                                               \
  cleanup                                                           \
  THError(fmt, func, info, ##__VA_ARGS__);                          \
}

#ifdef MKL_ILP64
// set  64 bit MKL integer type
#if (!defined(__INTEL_COMPILER)) & defined(_MSC_VER) 
#define LAPACK_INT __int64 
#else
#define LAPACK_INT long long int
#endif
#else
#define LAPACK_INT int
#endif

#include "generic/THLapack.h"
#include "THGenerateAllTypes.h"

#endif
