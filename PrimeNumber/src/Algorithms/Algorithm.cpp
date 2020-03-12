#include "Algorithm.h"

Algorithm::Algorithm() {}

void Algorithm::CheckResult(mpz_t n, mpz_t p, mpz_t q){
	mpz_t p_mul_q;
	mpz_init(p_mul_q);

	mpz_mul(p_mul_q, p, q);
	if(mpz_cmp(n, p_mul_q) == 0){
		gmp_printf("OK => %Zd = %Zd * %Zd\n", n, p, q);
	}else{
		gmp_printf("ERROR => %Zd = %Zd * %Zd\n", n, p, q);
	}
	mpz_clear(p_mul_q);
}

Algorithm::~Algorithm() {}
