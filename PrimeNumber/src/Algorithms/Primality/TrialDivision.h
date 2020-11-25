#include "../../MyHeader.h"

#ifndef ALGORITHMS_PRIMALITY_TRIALDIVISION_H_
#define ALGORITHMS_PRIMALITY_TRIALDIVISION_H_

namespace Primality {
	class TrialDivision : public Abstracts::Primality {
	public:
		TrialDivision();
		virtual ~TrialDivision();
		bool IsPrime(string input);
	};
}

#endif
