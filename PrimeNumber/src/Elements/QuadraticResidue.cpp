#include "QuadraticResidue.h"

namespace Elements {

	QuadraticResidue::QuadraticResidue(){
		mpz_inits(this->Prime, this->ModPrime, this->Solution1, this->Solution2, NULL);
		this->ULLPrime = 0;
		this->ULLIndexOfSolution1 = 0;
		this->ULLIndexOfSolution2 = 0;
	}

	QuadraticResidue::QuadraticResidue(short n, short solution1, short solution2){
		mpz_inits(this->Prime, this->ModPrime, this->Solution1, this->Solution2, NULL);
		mpz_set_ui(this->Prime, n);
		mpz_set_ui(this->Solution1, solution1);
		mpz_set_ui(this->Solution2, solution2);
		this->ULLPrime = n;
		this->ULLIndexOfSolution1 = solution1;
		this->ULLIndexOfSolution2 = solution2;
	}

	QuadraticResidue::~QuadraticResidue(){
		mpz_clears(this->Prime, this->ModPrime, this->Solution1, this->Solution2, NULL);
	}
}
