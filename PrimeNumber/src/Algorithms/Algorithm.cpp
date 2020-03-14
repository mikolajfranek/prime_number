#include "Algorithm.h"

Algorithm::Algorithm() {}

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

void Algorithm::CheckResult(mpf_t f_n, mpf_t f_p, mpf_t f_q){
	if(mpf_integer_p(f_n) == 0 || mpf_integer_p(f_p) == 0 || mpf_integer_p(f_q) == 0){
		gmp_printf("NOT-INT ERROR => %.6Ff = %.6Ff * %.6Ff\n", f_n, f_p, f_q);
		return;
	}
	mpz_t z_n;
	mpz_t z_p;
	mpz_t z_q;
	mpz_init(z_n);
	mpz_init(z_p);
	mpz_init(z_q);
	mpz_set_f(z_n, f_n);
	mpz_set_f(z_p, f_p);
	mpz_set_f(z_q, f_q);
	CheckResult(z_n, z_p, z_q);
	mpz_clear(z_n);
	mpz_clear(z_p);
	mpz_clear(z_q);
}

Algorithm::~Algorithm() {}
