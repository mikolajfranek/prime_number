#include "Factorization.h"

namespace Abstracts {

	Factorization::Factorization() {
		mpz_inits(this->m0, this->m1, this->m2, NULL);
	}

	Factorization::~Factorization() {
		mpz_clears(this->m0, this->m1, this->m2, NULL);
	}

	void Factorization::CheckResult(){
		mpz_t aim;
		mpz_inits(aim, NULL);
		mpz_mul(aim, this->m1, this->m2);
		if(mpz_cmp(aim, this->m0) == 0){
			gmp_printf("%Zd = %Zd * %Zd\n", this->m0, this->m1, this->m2);
		}else{
			printf("Error: Abstracts::Factorization::CheckResult\n");
		}
		mpz_clears(aim, NULL);
	}
}
