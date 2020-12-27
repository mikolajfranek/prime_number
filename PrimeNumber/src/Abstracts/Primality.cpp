#include "Primality.h"

namespace Abstracts {

	Primality::Primality() {
		mpz_inits(this->m0, NULL);
	}

	Primality::~Primality() {
		mpz_clears(this->m0, NULL);
	}

	void Primality::CheckResult(bool isPrime, bool prediction){
		if(isPrime == prediction){
			if(isPrime){
				gmp_printf("%Zd IS PRIME\n", this->m0);
			}else{
				gmp_printf("%Zd IS NOT PRIME\n", this->m0);
			}
		}else{
			printf("Error: Abstracts::Primality::CheckResult\n");
			throw;
		}
	}
}
