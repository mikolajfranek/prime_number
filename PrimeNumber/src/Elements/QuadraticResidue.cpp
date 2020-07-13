#include "QuadraticResidue.h"

namespace Elements {

	QuadraticResidue::QuadraticResidue(){
		mpz_inits(Prime, Solution1, Solution2, NULL);
	}

	QuadraticResidue::~QuadraticResidue(){
		mpz_clears(Prime, Solution1, Solution2, NULL);
	}
}
