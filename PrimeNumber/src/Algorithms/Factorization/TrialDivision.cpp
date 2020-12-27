#include "TrialDivision.h"

namespace Factorization {

	TrialDivision::TrialDivision() {}

	TrialDivision::~TrialDivision() {}

	void TrialDivision::Factor(string input) {

		//declare
		mpz_t m3, m5, m7;

		//init
		mpz_set_str(this->m0, input.c_str(), 10);
		mpz_inits(m3, m5, m7, NULL);

		//algorithm
		mpz_mod_ui(m7, this->m0, 2);
		if(mpz_cmp_ui(m7, 0) == 0){
			mpz_set_ui(this->m1, 2);
			mpz_div_ui(this->m2, this->m0, 2);
		}else{
			mpz_mod_ui(m7, this->m0, 3);
			if(mpz_cmp_ui(m7, 0) == 0){
				mpz_set_ui(this->m1, 3);
				mpz_div_ui(this->m2, this->m0, 3);
			}else{
				mpz_sqrt(m3, this->m0);
				short m4 = 4;
				bool isPrime = true;
				for(mpz_set_ui(m5, 5); mpz_cmp(m5, m3) <= 0; mpz_add_ui(m5, m5, m4)){
					mpz_mod(m7, this->m0, m5);
					if(mpz_cmp_ui(m7, 0) == 0){
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
		mpz_clears(m3, m5, m7, NULL);
	}
}
