#include "TrialDivision.h"

namespace Factorization {
	void TrialDivision::Factor(string input){

		//declare
		mpz_t n0, n1, n2, n3, n4, i;

		//init
		mpz_inits(n0, n1, n2, n3, n4, i, NULL);

		//set
		mpz_set_str(n0, input.c_str(), 10);

		//algorithm
		mpz_mod_ui(n4, n0, 2);
		if(mpz_cmp_ui(n4, 0) == 0){
			mpz_set_ui(n1, 2);
			mpz_div_ui(n2, n0, 2);
		}else{
			mpz_mod_ui(n4, n0, 3);
			if(mpz_cmp_ui(n4, 0) == 0){
				mpz_set_ui(n1, 3);
				mpz_div_ui(n2, n0, 3);
			}else{
				mpz_sqrt(n3, n0);
				short k = 4;
				bool isPrime = true;
				for(mpz_set_ui(i, 5); mpz_cmp(i, n3) <= 0; mpz_add_ui(i, i, k)){
					mpz_mod(n4, n0, i);
					if(mpz_cmp_ui(n4, 0) == 0){
						mpz_set(n1, i);
						mpz_div(n2, n0, i);
						isPrime = false;
						break;
					}
					k = 6 - k;
				}
				if(isPrime == true){
					mpz_set_ui(n1, 1);
					mpz_set(n2, n0);
				}
			}
		}

		//check
		Other::MyHelper::CheckResult(n0, n1, n2);

		//clear
		mpz_clears(n0, n1, n2, n3, n4, i, NULL);
	}
}
