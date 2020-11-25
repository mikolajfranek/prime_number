#include "Factorization.h"

namespace Abstracts {

	Factorization::Factorization() {
		mpz_inits(m0, m1, m2, NULL);
	}

	Factorization::~Factorization() {
		mpz_clears(m0, m1, m2, NULL);
	}

	void Factorization::CheckResult(){
		mpz_t aim;
		mpz_inits(aim, NULL);
		mpz_mul(aim, m1, m2);
		if(mpz_cmp(aim, m0) == 0){
			gmp_printf("%Zd = %Zd * %Zd\n", m0, m1, m2);
		}else{
			printf("Error: Abstracts::Factorization::CheckResult\n");
		}
		mpz_clears(aim, NULL);
	}
}
