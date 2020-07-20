#include "../MyHeader.h"

#ifndef ELEMENTS_QUADRATICRESIDUE_H_
#define ELEMENTS_QUADRATICRESIDUE_H_

namespace Elements {
	class QuadraticResidue {
	public:
		mpz_t Prime;
		mpz_t ModPrime;
		mpz_t Solution1;
		mpz_t Solution2;
		unsigned long long ULLPrime;
		unsigned long long ULLIndexOfSolution1;
		unsigned long long ULLIndexOfSolution2;
		QuadraticResidue();
		QuadraticResidue(short n, short solution1, short solution2);
		~QuadraticResidue();
	};
}

#endif
