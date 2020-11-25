#include "../../MyHeader.h"

#ifndef ALGORITHMS_FACTORIZATION_QUADRATICSIEVE_H_
#define ALGORITHMS_FACTORIZATION_QUADRATICSIEVE_H_

namespace Factorization {
	class QuadraticSieve : public Abstracts::Factorization  {
	public:
		QuadraticSieve();
		virtual ~QuadraticSieve();
		void Factor(string input);
	};
}

#endif
