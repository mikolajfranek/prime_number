#include "../../Main.h"

#ifndef ALGORITHMS_FACTORIZATION_QUADRATICSIEVE_H_
#define ALGORITHMS_FACTORIZATION_QUADRATICSIEVE_H_

namespace AlgorithmsFactorization {
	class QuadraticSieve : public AlgorithmsAbstracts::IFactorization {
	public:
		QuadraticSieve();
		virtual ~QuadraticSieve();
		void Factor(string input);
	private:
		unsigned long GetUpperBound(string input);
		vector<Elements::PrimeOfQuadraticResidue*> *AdaptSolutionsToFunction(vector<Elements::PrimeOfQuadraticResidue*> *VF, mpz_t m6);
	};
}

#endif
