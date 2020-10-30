#include "Factorization.h"

namespace Abstracts {

	Factorization::Factorization() {
		mpz_inits(n0, n1, n2, NULL);
	}

	Factorization::~Factorization() {
		mpz_clears(n0, n1, n2, NULL);
	}

	void Factorization::CheckResult(){
		mpz_t prediction;
		mpz_inits(prediction, NULL);
		mpz_mul(prediction, n1, n2);
		if(mpz_cmp(prediction, n0) == 0){
			gmp_printf("%Zd = %Zd * %Zd\n", n0, n1, n2);
		}else{
			printf("Error: Abstracts::Factorization::CheckResult\n");
		}
		mpz_clears(prediction, NULL);
	}
}
