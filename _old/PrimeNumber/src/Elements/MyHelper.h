#include "../../../../_old/PrimeNumber/src/Main.h"

#ifndef ELEMENTS_MYHELPER_H_
#define ELEMENTS_MYHELPER_H_

namespace Elements {
	class MyHelper {
	public:
		static void PrintMatrix(vector<vector<bool>> matrix);
		static vector<vector<bool>> GetIdentityMatrix(long long size);
		static void FitIdentityMatrix(vector<vector<bool>> &MU, long long size);
		static void PowCExpD(mpz_t r, mpz_t c, mpz_t d);
	};
}

#endif
