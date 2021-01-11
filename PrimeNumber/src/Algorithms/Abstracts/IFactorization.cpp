#include "IFactorization.h"

namespace AlgorithmsAbstracts {

	IFactorization::IFactorization() {
		mpz_inits(this->m0, this->m1, this->m2, NULL);
	}

	IFactorization::~IFactorization() {
		mpz_clears(this->m0, this->m1, this->m2, NULL);
	}

	void IFactorization::CheckResult(){
		mpz_t aim;
		mpz_inits(aim, NULL);
		mpz_mul(aim, this->m1, this->m2);
		gmp_printf("%Zd = %Zd * %Zd\n", this->m0, this->m1, this->m2);
		if(mpz_cmp(aim, this->m0) != 0){
			printf("Error: Abstracts::Factorization::CheckResult\n");
			throw;
		}
		mpz_clears(aim, NULL);
	}
}
