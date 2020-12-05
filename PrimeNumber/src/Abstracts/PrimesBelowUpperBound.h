#include "../Main.h"

#ifndef ABSTRACTS_PRIMESBELOWUPPERBOUND_H_
#define ABSTRACTS_PRIMESBELOWUPPERBOUND_H_

namespace Abstracts {
	class PrimesBelowUpperBound {
	public:
		PrimesBelowUpperBound();
		virtual ~PrimesBelowUpperBound();
		virtual vector<long long> SearchPrimes(long long upperBound) = 0;
		vector<Elements::QuadraticResidue*> *GetQuadraticResidues(long long upperBound, mpz_t m0);
	};
}

#endif
