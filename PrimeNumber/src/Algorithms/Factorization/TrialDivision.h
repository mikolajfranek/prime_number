#include "../../Main.h"

#ifndef ALGORITHMS_FACTORIZATION_TRIALDIVISTION_H
#define ALGORITHMS_FACTORIZATION_TRIALDIVISTION_H

namespace Factorization {
	class TrialDivision : public Abstracts::Factorization {
	public:
		TrialDivision();
		virtual ~TrialDivision();
		void Factor(string input);
	};
}

#endif
