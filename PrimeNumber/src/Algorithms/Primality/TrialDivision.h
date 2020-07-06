#include "../../Configurations/MyHeader.h"

#ifndef ALGORITHMS_PRIMALITY_TRIALDIVISION_H_
#define ALGORITHMS_PRIMALITY_TRIALDIVISION_H_

namespace Primality {
	class TrialDivision {
	public:
		static void IsPrime(string n, bool prediction);
		static bool IsPrime(mpz_t n);
	};
}

#endif
