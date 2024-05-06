#include "../../../../_old/PrimeNumber/src/Main.h"

#ifndef ELEMENTS_PRIMEOFQUADRATICRESIDUE_H_
#define ELEMENTS_PRIMEOFQUADRATICRESIDUE_H_

namespace Elements {
	class PrimeOfQuadraticResidue {
	public:
		PrimeOfQuadraticResidue();
		PrimeOfQuadraticResidue(short p0, short c0, short c1);
		virtual ~PrimeOfQuadraticResidue();
		mpz_t vp;
		mpz_t m7;
		mpz_t m8;
		long long p0;
		long long c0;
		long long c2;
		long long c1;
		long long c3;
	};
}

#endif
