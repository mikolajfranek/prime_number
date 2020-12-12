#include "../Main.h"

#ifndef ELEMENTS_PRIMEOFQUADRATICRESIDUE_H_
#define ELEMENTS_PRIMEOFQUADRATICRESIDUE_H_

namespace Elements {
	class PrimeOfQuadraticResidue {
	public:
		PrimeOfQuadraticResidue();
		PrimeOfQuadraticResidue(short p0, short solution0, short solution1);
		virtual ~PrimeOfQuadraticResidue();
		mpz_t prime;
		mpz_t solution0;
		mpz_t solution1;
		long long p0;
		long long s0;
		long long s0Plus;
		long long s0Minus;
		long long s1;
		long long s1Plus;
		long long s1Minus;
	};
}

#endif
