#include "../Main.h"

#ifndef ELEMENTS_ELEMENTOFSIEVE_H_
#define ELEMENTS_ELEMENTOFSIEVE_H_

namespace Elements {
	class ElementOfQuadraticSieve {
	public:
		ElementOfQuadraticSieve(long long ident, mpz_t m0, mpz_t m3, long long sizeOfDivisors);
		virtual ~ElementOfQuadraticSieve();
		mpz_t oryginal;
		mpz_t divisible;
		mpz_t element;
		bool overMinusSqrt;
		vector<bool> divisors;
	};
}

#endif
