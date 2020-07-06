#include "Fermat.h"

namespace Factorization {
	void Fermat::Factor(string input){

		//declare
		mpz_t n, q, p, nmod, x, xrem, xmul, z, y, yrem;

		//init
		mpz_inits(n, q, p, nmod, x, xrem, xmul, z, y, yrem, NULL);

		//set
		mpz_set_str(n, input.c_str(), 10);

		//start algorithm
		mpz_mod_ui(nmod, n, 2);
		if(mpz_cmp_ui(nmod, 0) == 0){
			mpz_div_ui(q, n, 2);
			mpz_set_ui(p, 2);
		}else{
			mpz_sqrtrem(x, xrem, n);
			if(mpz_cmp_ui(xrem, 0) != 0){
				mpz_add_ui(x, x, 1);
			}
			mpz_pow_ui(z, x, 2);
			mpz_sub(z, z, n);
			mpz_sqrtrem(y, yrem, z);
			while(mpz_cmp_ui(yrem, 0) != 0){
				mpz_mul_ui(xmul, x, 2);
				mpz_add_ui(xmul, xmul, 1);
				mpz_add(z, z, xmul);
				mpz_sqrtrem(y, yrem, z);
				mpz_add_ui(x, x, 1);
			}
			mpz_add(q, x, y);
			mpz_sub(p, x, y);
		}

		//check
		MyHelper::CheckResult(n, q, p);

		//clear
		mpz_clears(n, q, p, nmod, x, xrem, xmul, z, y, yrem, NULL);
	}
}
