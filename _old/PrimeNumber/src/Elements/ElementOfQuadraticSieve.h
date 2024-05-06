#include "../../../../_old/PrimeNumber/src/Main.h"

#ifndef ELEMENTS_ELEMENTOFSIEVE_H_
#define ELEMENTS_ELEMENTOFSIEVE_H_

namespace Elements {
	class ElementOfQuadraticSieve {
	public:
		ElementOfQuadraticSieve(long long x0, mpz_t m0, mpz_t m6, long long sizeOfDivisors);
		virtual ~ElementOfQuadraticSieve();
		mpz_t c4;
		mpz_t c5;
		mpz_t c6;
		mpz_t c7;
		vector<bool> VD;
	};
}

#endif
