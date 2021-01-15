#include "TrialDivision.h"

namespace AlgorithmsFactorization {

	TrialDivision::TrialDivision() {}

	TrialDivision::~TrialDivision() {}

	void TrialDivision::Factor(string input) {

		//parent
		AlgorithmsAbstracts::IFactorization::Factor(input);

		//declare
		mpz_t m3;

		//init
		mpz_inits(m3, NULL);

		//algorithm
		mpz_sqrt(m3, this->m0);
		this->Factor(input, m3);

		//clear
		mpz_clears(m3, NULL);
	}

	void TrialDivision::Factor(string input, mpz_t m3) {

		//parent
		AlgorithmsAbstracts::IFactorization::Factor(input);

		//declare
		mpz_t m5, n0;

		//init
		mpz_inits(m5, n0, NULL);

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
				short m4 = 4;
				bool isPrime = true;
				for(mpz_set_ui(m5, 5); mpz_cmp(m5, m3) <= 0; mpz_add_ui(m5, m5, m4)){
					mpz_mod(n0, this->m0, m5);
					if(mpz_cmp_ui(n0, 0) == 0){
						mpz_set(this->m1, m5);
						mpz_div(this->m2, this->m0, m5);
						isPrime = false;
						break;
					}
					m4 = 6 - m4;
				}
				if(isPrime == true){
					mpz_set_ui(this->m1, 1);
					mpz_set(this->m2, this->m0);
				}
			}
		}

		//clear
		mpz_clears(m5, n0, NULL);
	}
}
