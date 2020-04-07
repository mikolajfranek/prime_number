#include "Algorithm.h"

void Algorithm::CheckResult(mpz_t n, mpz_t q, mpz_t p){
	mpz_t q_mul_p;
	mpz_init(q_mul_p);
	mpz_mul(q_mul_p, q, p);
	if(mpz_cmp(n, q_mul_p) == 0){
		gmp_printf("OK => %Zd = %Zd * %Zd\n", n, q, p);
	}else{
		gmp_printf("ERROR => %Zd = %Zd * %Zd\n", n, q, p);
	}
	mpz_clear(q_mul_p);
}
