#include "ElementOfQuadraticSieve.h"

namespace Elements {

	ElementOfQuadraticSieve::ElementOfQuadraticSieve(long long ident, mpz_t m0, mpz_t m3, long long sizeOfDivisors) {
		mpz_inits(this->oryginal, this->divisible, this->element, NULL);
		mpz_set_str(this->oryginal, to_string(ident).c_str(), 10);
		mpz_add(this->oryginal, this->oryginal, m3);
		this->overMinusSqrt = mpz_cmp_ui(this->oryginal, 0) < 0;
		mpz_pow_ui(this->oryginal, this->oryginal, 2);
		mpz_set(this->element, this->oryginal);
		mpz_sub(this->oryginal, this->oryginal, m0);
		mpz_set(this->divisible, this->oryginal);
		this->divisors = vector<bool>(sizeOfDivisors);
	}

	ElementOfQuadraticSieve::~ElementOfQuadraticSieve() {
		mpz_clears(this->oryginal, this->divisible, this->element, NULL);
	}
}
