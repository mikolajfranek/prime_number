#include "QuadraticResidue.h"

namespace Elements {

	QuadraticResidue::QuadraticResidue(){
		mpz_inits(Prime, ModPrime, Solution1, Solution2, NULL);
	}

	QuadraticResidue::QuadraticResidue(short n, short solution1, short solution2){
		mpz_inits(Prime, ModPrime, Solution1, Solution2, NULL);
		mpz_set_ui(Prime, n);
		mpz_set_ui(Solution1, solution1);
		mpz_set_ui(Solution2, solution2);
		this->ULLPrime = n;
		this->ULLIndexOfSolution1 = solution1;
		this->ULLIndexOfSolution2 = solution2;
	}

	QuadraticResidue::~QuadraticResidue(){
		mpz_clears(Prime, ModPrime, Solution1, Solution2, NULL);
	}
}
