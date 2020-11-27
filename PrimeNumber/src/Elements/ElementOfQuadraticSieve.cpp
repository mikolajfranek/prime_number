#include "ElementOfQuadraticSieve.h"

namespace Elements {

	ElementOfQuadraticSieve::ElementOfQuadraticSieve(long long d, mpz_t m0, mpz_t m3) {
		mpz_inits(this->oryginal, this->divisible, NULL);
		mpz_set_str(this->oryginal, to_string(d).c_str(), 10);
		mpz_add(this->oryginal, this->oryginal, m3);
		mpz_pow_ui(this->oryginal, this->oryginal, 2);
		mpz_sub(this->oryginal, this->oryginal, m0);
		mpz_set(this->divisible, this->oryginal);
		this->divisors = {};
	}

	ElementOfQuadraticSieve::~ElementOfQuadraticSieve() {
		mpz_clears(this->oryginal, this->divisible, NULL);
	}

	bool ElementOfQuadraticSieve::IsSmooth(vector<Elements::QuadraticResidue*> *quadraticResidues){


		return true;
	}
}
