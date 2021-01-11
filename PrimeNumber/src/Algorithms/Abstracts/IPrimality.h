#include "../../Main.h"

#ifndef ALGORITHMS_ABSTRACTS_IPRIMALITY_H_
#define ALGORITHMS_ABSTRACTS_IPRIMALITY_H_

namespace AlgorithmsAbstracts {
	class IPrimality {
	public:
		IPrimality();
		virtual ~IPrimality();
		virtual bool IsPrime(string input) = 0;
		void CheckResult(bool isPrime, bool prediction);
	protected:
		mpz_t m0;
	};
}

#endif
