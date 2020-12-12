#include "../../Main.h"

#ifndef ALGORITHMS_FACTORIZATION_QUADRATICSIEVE_H_
#define ALGORITHMS_FACTORIZATION_QUADRATICSIEVE_H_

namespace Factorization {
	class QuadraticSieve : public Abstracts::Factorization  {
	public:
		QuadraticSieve();
		virtual ~QuadraticSieve();
		void Factor(string input);
	private:
		unsigned long GetUpperBound(string input);
		vector<Elements::PrimeOfQuadraticResidue*> *AdaptSolutionsToFunction(vector<Elements::PrimeOfQuadraticResidue*> *primesOfQuadraticResidue, mpz_t m3);
	};
}

#endif
