#include "../../Main.h"

#ifndef ALGORITHMS_FACTORIZATION_FERMAT_H_
#define ALGORITHMS_FACTORIZATION_FERMAT_H_

namespace AlgorithmsFactorization {
	class Fermat : public AlgorithmsAbstracts::IFactorization {
	public:
		Fermat();
		virtual ~Fermat();
		void Factor(string input);
	};
}

#endif
