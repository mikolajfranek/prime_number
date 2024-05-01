#include "IFactorization.h"

namespace AlgorithmsAbstracts {

	IFactorization::IFactorization() {
		mpz_inits(this->m0, this->m1, this->m2, NULL);
	}

	IFactorization::~IFactorization() {
		mpz_clears(this->m0, this->m1, this->m2, NULL);
	}

	void IFactorization::SetInput(string input){
		mpz_set_str(this->m0, input.c_str(), 10);
	}

	void IFactorization::CheckResult(bool printResult){
		mpz_t guess;
		mpz_inits(guess, NULL);
		mpz_mul(guess, this->m1, this->m2);
		if(printResult == true){
			gmp_printf("%Zd = %Zd * %Zd\n", this->m0, this->m1, this->m2);
		}
		if(mpz_cmp(guess, this->m0) != 0){
			printf("Error: AlgorithmsAbstracts::IFactorization::CheckResult\n");
			throw;
		}
		mpz_clears(guess, NULL);
	}

	bool IFactorization::AreFactorsSet(){
		return (mpz_cmp_ui(this->m1, 0) == 0 && mpz_cmp_ui(this->m2, 0) == 0) == false;
	}

	bool IFactorization::AreFactorsTrivial(){
		return
		(
			(mpz_cmp_ui(this->m1, 1) == 0 && mpz_cmp(this->m2, this->m0) == 0)
			||
			(mpz_cmp_ui(this->m2, 1) == 0 && mpz_cmp(this->m1, this->m0) == 0)
		);
	}
}
