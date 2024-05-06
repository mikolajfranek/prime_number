#include "../../../../_old/PrimeNumber/src/Elements/PrimeOfQuadraticResidue.h"

namespace Elements {

	PrimeOfQuadraticResidue::PrimeOfQuadraticResidue(){
		mpz_inits(this->vp, this->m7, this->m8, NULL);
		mpz_set_ui(this->vp, 0);
		mpz_set_ui(this->m7, 0);
		mpz_set_ui(this->m8, 0);
		this->p0 = 0;
		this->c0 = 0;
		this->c2 = 0;
		this->c1 = 0;
		this->c3 = 0;
	}

	PrimeOfQuadraticResidue::PrimeOfQuadraticResidue(short p0, short c0, short c1){
		mpz_inits(this->vp, this->m7, this->m8, NULL);
		mpz_set_ui(this->vp, p0);
		mpz_set_ui(this->m7, c0);
		mpz_set_ui(this->m8, c1);
		this->p0 = p0;
		this->c0 = c0;
		this->c2 = c0 - p0;
		this->c1 = c1;
		this->c3 = c1 - p0;
	}

	PrimeOfQuadraticResidue::~PrimeOfQuadraticResidue(){
		mpz_clears(this->vp, this->m7, this->m8, NULL);
	}
}
