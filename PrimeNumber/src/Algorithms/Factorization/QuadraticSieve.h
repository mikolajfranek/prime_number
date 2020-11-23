#include "../../MyHeader.h"

#ifndef ALGORITHMS_QUADRATICSIEVE_H_
#define ALGORITHMS_QUADRATICSIEVE_H_

namespace Factorization {
	class QuadraticSieve : public Abstracts::Factorization  {
	public:
		QuadraticSieve();
		virtual ~QuadraticSieve();
		void Factor(string input);
	};
}

#endif
