#include "ElementOfSieve.h"

namespace Elements {

	ElementOfSieve ElementOfSieve::DeepCopy(){
		ElementOfSieve r;
		mpz_set(r.Number, Number);
		return r;
	}

	ElementOfSieve::ElementOfSieve() {
		mpz_inits(Number, NULL);
		mpz_set_ui(Number, 0);
	}

	ElementOfSieve::~ElementOfSieve() {
		;
	}
}
