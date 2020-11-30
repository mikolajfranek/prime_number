#include "../../Main.h"

#ifndef ALGORITHMS_PRIMESBELOWLIMIT_SIEVEOFERATOSTHENES_H_
#define ALGORITHMS_PRIMESBELOWLIMIT_SIEVEOFERATOSTHENES_H_

namespace PrimesBelowUpperBound {
	class SieveOfEratosthenes : public Abstracts::PrimesBelowUpperBound {
	public:
		SieveOfEratosthenes();
		virtual ~SieveOfEratosthenes();
		void SearchPrimes(long long upperBound);
	};
}

#endif
