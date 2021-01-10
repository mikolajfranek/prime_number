#include "ElementOfQuadraticSieve.h"

namespace Elements {

	ElementOfQuadraticSieve::ElementOfQuadraticSieve(long long x0, mpz_t m0, mpz_t m6, long long sizeOfDivisors) {
		mpz_inits(this->c4, this->c5, this->c6, this->c7, NULL);
		mpz_set_str(this->c7, to_string(x0).c_str(), 10);
		mpz_add(this->c7, this->c7, m6);
		mpz_set(this->c5, this->c7);
		mpz_pow_ui(this->c5, this->c5, 2);
		mpz_set(this->c6, this->c5);
		mpz_sub(this->c5, this->c5, m0);
		mpz_set(this->c4, this->c5);
		this->VD = vector<bool>(sizeOfDivisors);
	}

	ElementOfQuadraticSieve::~ElementOfQuadraticSieve() {
		mpz_clears(this->c4, this->c5, this->c6, this->c7, NULL);
	}
}
