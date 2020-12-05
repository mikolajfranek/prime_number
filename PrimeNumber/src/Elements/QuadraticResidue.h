#include "../Main.h"

#ifndef ELEMENTS_QUADRATICRESIDUE_H_
#define ELEMENTS_QUADRATICRESIDUE_H_

namespace Elements {
	class QuadraticResidue {
	public:
		QuadraticResidue();
		QuadraticResidue(short p0, short solution0, short solution1);
		virtual ~QuadraticResidue();
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
