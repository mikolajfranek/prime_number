#include "../Main.h"

#ifndef ABSTRACTS_PRIMESBELOWUPPERBOUND_H_
#define ABSTRACTS_PRIMESBELOWUPPERBOUND_H_

namespace Abstracts {
	class PrimesBelowUpperBound {
	public:
		PrimesBelowUpperBound();
		virtual ~PrimesBelowUpperBound();
		virtual void SearchPrimes(long long upperBound) = 0;
		vector<Elements::QuadraticResidue*> *GetQuadraticResidues(unsigned long long upperBound, mpz_t m0);
		vector<unsigned long long> primes;
	};
}

#endif
