#include "Primality.h"

namespace Abstracts {

	Primality::Primality() {
		mpz_inits(m0, NULL);
	}

	Primality::~Primality() {
		mpz_clears(m0, NULL);
	}

	void Primality::CheckResult(bool isPrime, bool prediction){
		if(isPrime == prediction){
			if(isPrime){
				gmp_printf("%Zd IS PRIME\n", m0);
			}else{
				gmp_printf("%Zd IS NOT PRIME\n", m0);
			}
		}else{
			printf("Error: Abstracts::Primality::CheckResult\n");
		}
	}
}
