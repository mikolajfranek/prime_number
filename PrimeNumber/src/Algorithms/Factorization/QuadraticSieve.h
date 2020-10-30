#include "../../MyHeader.h"

#ifndef ALGORITHMS_QUADRATICSIEVE_H_
#define ALGORITHMS_QUADRATICSIEVE_H_

namespace Factorization {
	class QuadraticSieve {
	public:
		QuadraticSieve();
		virtual ~QuadraticSieve();
		void Factor(string n);
	};
}

#endif
