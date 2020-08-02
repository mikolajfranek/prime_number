#include "QuadraticResidue.h"

namespace Elements {

	QuadraticResidue::QuadraticResidue(){
		mpz_inits(Prime, ModPrime, Solution1, Solution2, NULL);
		mpz_set_ui(Prime, 0);
		mpz_set_ui(ModPrime, 0);
		mpz_set_ui(Solution1, 0);
		mpz_set_ui(Solution2, 0);
		ULLPrime = 0;
		ULLIndexOfSolution1 = 0;
		ULLIndexOfSolution2 = 0;
	}

	QuadraticResidue::QuadraticResidue(short n, short solution1, short solution2){
		mpz_inits(Prime, ModPrime, Solution1, Solution2, NULL);
		mpz_set_ui(Prime, n);
		mpz_set_ui(ModPrime, 0);
		mpz_set_ui(Solution1, solution1);
		mpz_set_ui(Solution2, solution2);
		ULLPrime = n;
		ULLIndexOfSolution1 = solution1;
		ULLIndexOfSolution2 = solution2;
	}

	QuadraticResidue::~QuadraticResidue(){
		;
	}
}
