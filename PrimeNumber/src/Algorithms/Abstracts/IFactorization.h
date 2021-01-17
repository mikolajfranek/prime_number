#include "../../Main.h"

#ifndef ALGORITHMS_ABSTRACTS_IFACTORIZATION_H_
#define ALGORITHMS_ABSTRACTS_IFACTORIZATION_H_

namespace AlgorithmsAbstracts {
	class IFactorization {
	public:
		IFactorization();
		virtual ~IFactorization();
		virtual void Factor(string input) = 0;
		void CheckResult();
		bool AreFactorsSet();
		bool AreFactorsTrivial();
		mpz_t m0, m1, m2;
	};
}

#endif
