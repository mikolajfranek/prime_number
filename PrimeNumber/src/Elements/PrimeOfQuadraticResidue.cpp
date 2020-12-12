#include "PrimeOfQuadraticResidue.h"

namespace Elements {

	PrimeOfQuadraticResidue::PrimeOfQuadraticResidue(){
		mpz_inits(this->prime, this->solution0, this->solution1, NULL);
		mpz_set_ui(this->prime, 0);
		mpz_set_ui(this->solution0, 0);
		mpz_set_ui(this->solution1, 0);
		this->p0 = 0;
		this->s0 = 0;
		this->s0Plus = 0;
		this->s0Minus = 0;
		this->s1 = 0;
		this->s1Plus = 0;
		this->s1Minus = 0;
	}

	PrimeOfQuadraticResidue::PrimeOfQuadraticResidue(short p0, short solution0, short solution1){
		mpz_inits(this->prime, this->solution0, this->solution1, NULL);
		mpz_set_ui(this->prime, p0);
		mpz_set_ui(this->solution0, solution0);
		mpz_set_ui(this->solution1, solution1);
		this->p0 = p0;
		this->s0 = solution0;
		this->s0Plus = solution0;
		this->s0Minus = solution0 - p0;
		this->s1 = solution1;
		this->s1Plus = solution1;
		this->s1Minus = solution1 - p0;
	}

	PrimeOfQuadraticResidue::~PrimeOfQuadraticResidue(){
		mpz_clears(this->prime, this->solution0, this->solution1, NULL);
	}
}
