#include "../../../../../_old/PrimeNumber/src/Main.h"

#ifndef ALGORITHMS_FACTORIZATION_TRIALDIVISTION_H
#define ALGORITHMS_FACTORIZATION_TRIALDIVISTION_H

namespace AlgorithmsFactorization {
	class TrialDivision : public AlgorithmsAbstracts::IFactorization {
	public:
		TrialDivision();
		virtual ~TrialDivision();
		void Factor(string input);
	};
}

#endif
