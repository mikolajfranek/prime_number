#include "Algorithm.h"

void Algorithm::CheckResult(mpz_t z_n, mpz_t z_p, mpz_t z_q){
	mpz_t p_mul_q;
	mpz_init(p_mul_q);

	mpz_mul(p_mul_q, z_p, z_q);
	if(mpz_cmp(z_n, p_mul_q) == 0){
		gmp_printf("OK => %Zd = %Zd * %Zd\n", z_n, z_p, z_q);
	}else{
		gmp_printf("ERROR => %Zd = %Zd * %Zd\n", z_n, z_p, z_q);
	}
	mpz_clear(p_mul_q);
}
