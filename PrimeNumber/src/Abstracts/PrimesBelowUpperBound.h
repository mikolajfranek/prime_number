#include "../Main.h"

#ifndef ABSTRACTS_PRIMESBELOWUPPERBOUND_H_
#define ABSTRACTS_PRIMESBELOWUPPERBOUND_H_

namespace Abstracts {
	class PrimesBelowUpperBound {
	public:
		PrimesBelowUpperBound();
		virtual ~PrimesBelowUpperBound();
		virtual vector<unsigned long long> GetPrimes(unsigned long long upperBound) = 0;
		vector<Elements::PrimeOfQuadraticResidue*> *GetPrimesOfQuadraticResidue(unsigned long upperBound, mpz_t m0);
	};
}

#endif
