#include "QuadraticResidue.h"

namespace Elements {

	QuadraticResidue::QuadraticResidue(){
		mpz_inits(this->prime, this->solution0, this->solution1, NULL);
		mpz_set_ui(this->prime, 0);
		mpz_set_ui(this->solution0, 0);
		mpz_set_ui(this->solution1, 0);
		this->p0 = 0;
		this->s0 = 0;
		this->s1 = 0;
	}

	QuadraticResidue::QuadraticResidue(short p0, short solution0, short solution1){
		mpz_inits(this->prime, this->solution0, this->solution1, NULL);
		mpz_set_ui(this->prime, p0);
		mpz_set_ui(this->solution0, solution0);
		mpz_set_ui(this->solution1, solution1);
		this->p0 = p0;
		this->s0 = solution0;
		this->s1 = solution1;
	}

	QuadraticResidue::~QuadraticResidue(){
		mpz_clears(this->prime, this->solution0, this->solution1, NULL);
	}
}
