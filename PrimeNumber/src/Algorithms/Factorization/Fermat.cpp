#include "Fermat.h"

namespace AlgorithmsFactorization {

	Fermat::Fermat() {}

	Fermat::~Fermat() {}

	void Fermat::Factor(string input){

		//parent
		AlgorithmsAbstracts::IFactorization::Factor(input);

		//declare
		mpz_t m3, m4, n0, r0;

		//init
		mpz_inits(m3, m4, n0, r0, NULL);


		unordered_set<int> setTwoDigit( {
			0, 1, 4, 9
		} );


		int isIn = 0;
		int notIn = 0;

		//algorithm
		mpz_mod_ui(n0, this->m0, 2);
		if(mpz_cmp_ui(n0, 0) == 0){
			mpz_set_ui(this->m1, 2);
			mpz_div_ui(this->m2, this->m0, 2);
		}else{
			mpz_sqrtrem(m3, n0, this->m0);
			if(mpz_cmp_ui(n0, 0) != 0){
				mpz_add_ui(m3, m3, 1);
			}
			mpz_pow_ui(m4, m3, 2);
			mpz_sub(m4, m4, this->m0);
			mpz_sqrtrem(r0, n0, m4);
			while(mpz_cmp_ui(n0, 0) != 0){
				mpz_mul_ui(n0, m3, 2);
				mpz_add_ui(n0, n0, 1);
				mpz_add(m4, m4, n0);


/*
				char m4String[mpz_sizeinbase(m4, 10) + 2];
				mpz_get_str(m4String, 10, m4);
				string lastTwoDigits(m4String);
				lastTwoDigits = lastTwoDigits.substr(sizeof(m4String) - 4, 2);
				if(setTwoDigit.find (lastTwoDigits) != setTwoDigit.end()){
					mpz_sqrtrem(r0, n0, m4);
					//isIn ++;
			    }else{
			    	//notIn++;
			    }
*/

				mpz_mod_ui(n0, m4, 16);
				if(setTwoDigit.find (mpz_get_ui(n0)) != setTwoDigit.end()){
					mpz_sqrtrem(r0, n0, m4);
					//isIn ++;
				}else{
					//notIn++;
				}



				//mpz_sqrtrem(r0, n0, m4);
				mpz_add_ui(m3, m3, 1);
			}
			mpz_sub(this->m1, m3, r0);
			mpz_add(this->m2, m3, r0);
		}

		printf("%d/%d \n", isIn, notIn);

		//clear
		mpz_clears(m3, m4, n0, r0, NULL);
	}
}
