#include "../../MyHeader.h"

#ifndef ALGORITHMS_SIEVEOFERATOSTHENES_H_
#define ALGORITHMS_SIEVEOFERATOSTHENES_H_

namespace Factorization {
	class TrialDivision : public Abstracts::Factorization {
	public:
		TrialDivision();
		virtual ~TrialDivision();
		void Factor(string input);
	};
}

#endif
