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
		unsigned long long p0;
		unsigned long long m0;
		unsigned long long m1;
	};
}

#endif
