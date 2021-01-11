#include "../../Main.h"

#ifndef ALGORITHMS_PRIMALITY_TRIALDIVISION_H_
#define ALGORITHMS_PRIMALITY_TRIALDIVISION_H_

namespace AlgorithmsPrimality {
	class TrialDivision : public AlgorithmsAbstracts::IPrimality {
	public:
		TrialDivision();
		virtual ~TrialDivision();
		bool IsPrime(string input);
	};
}

#endif
