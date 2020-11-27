#include "../Main.h"

#ifndef ELEMENTS_ELEMENTOFSIEVE_H_
#define ELEMENTS_ELEMENTOFSIEVE_H_

namespace Elements {
	class ElementOfQuadraticSieve {
	public:
		ElementOfQuadraticSieve(long long d, mpz_t m0, mpz_t m3);
		virtual ~ElementOfQuadraticSieve();
		bool IsSmooth(vector<Elements::QuadraticResidue*> *quadraticResidues);
		mpz_t oryginal;
		mpz_t divisible;
		vector<bool> divisors;
	};
}

#endif
