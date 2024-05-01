#include "IPrimality.h"

namespace AlgorithmsAbstracts {

	IPrimality::IPrimality() {
		mpz_inits(this->m0, NULL);
	}

	IPrimality::~IPrimality() {
		mpz_clears(this->m0, NULL);
	}

	void IPrimality::CheckResult(bool isPrime, bool prediction){
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
