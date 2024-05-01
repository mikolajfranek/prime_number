#include "../../Main.h"

#ifndef ALGORITHMS_ABSTRACTS_IPRIMESBELOWUPPERBOUND_H_
#define ALGORITHMS_ABSTRACTS_IPRIMESBELOWUPPERBOUND_H_

namespace AlgorithmsAbstracts {
	class IPrimesBelowUpperBound {
	public:
		IPrimesBelowUpperBound();
		virtual ~IPrimesBelowUpperBound();
		virtual vector<unsigned long long>* GetPrimes(unsigned long long upperBound) = 0;
		vector<Elements::PrimeOfQuadraticResidue*>* GetPrimesOfQuadraticResidue(mpz_t m0, vector<unsigned long long>* VP);
	};
}

#endif
