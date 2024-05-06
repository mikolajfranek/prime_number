#include "../../../../../_old/PrimeNumber/src/Algorithms/Factorization/TrialDivision.h"

namespace AlgorithmsFactorization {

	TrialDivision::TrialDivision() {}

	TrialDivision::~TrialDivision() {}

	void TrialDivision::Factor(string input) {

		//parent
		AlgorithmsAbstracts::IFactorization::SetInput(input);

		//declare
		mpz_t m3, m4, n0;

		//init
		mpz_inits(m3, m4, n0, NULL);

		//algorithm
		mpz_mod_ui(n0, this->m0, 2);
		if(mpz_cmp_ui(n0, 0) == 0){
			mpz_set_ui(this->m1, 2);
			mpz_div_ui(this->m2, this->m0, 2);
		}else{
			mpz_mod_ui(n0, this->m0, 3);
			if(mpz_cmp_ui(n0, 0) == 0){
				mpz_set_ui(this->m1, 3);
				mpz_div_ui(this->m2, this->m0, 3);
			}else{
				mpz_sqrt(m3, this->m0);
				bool isPrime = true;
				for(mpz_set_ui(m4, 5); mpz_cmp(m4, m3) <= 0; mpz_add_ui(m4, m4, 4)){
					mpz_mod(n0, this->m0, m4);
					if(mpz_cmp_ui(n0, 0) == 0){
						mpz_set(this->m1, m4);
						mpz_div(this->m2, this->m0, m4);
						isPrime = false;
						break;
					}
					mpz_add_ui(m4, m4, 2);
					mpz_mod(n0, this->m0, m4);
					if(mpz_cmp_ui(n0, 0) == 0){
						mpz_set(this->m1, m4);
						mpz_div(this->m2, this->m0, m4);
						isPrime = false;
						break;
					}
				}
				if(isPrime == true){
					mpz_set_ui(this->m1, 1);
					mpz_set(this->m2, this->m0);
				}
			}
		}

		//clear
		mpz_clears(m3, m4, n0, NULL);
	}
}
