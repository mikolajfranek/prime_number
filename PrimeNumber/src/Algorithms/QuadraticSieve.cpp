#include "QuadraticSieve.h"

void QuadraticSieve::Factor(string input){

	//declare
	mpz_t z_n;
	mpz_t z_nmod2;
	mpz_t z_nsqrt;
	mpz_t z_p;
	mpz_t z_q;

	//init
	mpz_init_set_str(z_n, input.c_str(), 10);
	mpz_init(z_nmod2);
	mpz_init(z_nsqrt);
	mpz_init(z_p);
	mpz_init(z_q);

	//start algorithm
	mpz_mod_ui(z_nmod2, z_n, 2);
	if(mpz_cmp_ui(z_nmod2, 0) == 0){
		mpz_div_ui(z_q, z_n, 2);
		mpz_set_ui(z_p, 2);
	}else{
		mpz_sqrt(z_nsqrt, z_n);

	}

	Algorithm::CheckResult(z_n, z_p, z_q);

	//clear
	mpz_clear(z_n);
	mpz_clear(z_nmod2);
	mpz_clear(z_nsqrt);
	mpz_clear(z_p);
	mpz_clear(z_q);
}



bool QuadraticSieve::Tonelli_Shanks(mpz_t n, mpz_t p){


	mpz_t m;
	mpz_t c;
	mpz_t t;
	mpz_t r;
	mpz_init(m);
	mpz_init(c);
	mpz_init(t);
	mpz_init(r);



	mpz_t nmod4;
	mpz_init(nmod4);
	mpz_mod_ui(nmod4, p, 4);
	if(mpz_cmp_ui(nmod4, 1) != 0 || mpz_jacobi(n, p) != 1){
		gmp_printf("init condition failed\n");
		return false;
	}
	mpz_clear(nmod4);



	mpz_t z;
	mpz_t s;
	mpz_t q;
	mpz_t qexp;
	mpz_t qmod2;
	mpz_init(s);
	mpz_init(q);
	mpz_init(qexp);
	mpz_init(qmod2);
	mpz_init_set(q, p);

	//q, s
	mpz_sub_ui(q, q, 1);
	mpz_init_set_ui(s, 0);
	mpz_mod_ui(qmod2, q, 2);
	while(mpz_cmp_ui(qmod2, 0) == 0){
		mpz_div_ui(q, q, 2);
		mpz_mod_ui(qmod2, q, 2);
		mpz_add_ui(s, s, 1);
	}



	//z
	mpz_init_set_ui(z, 2);
	while(mpz_jacobi(z, p) != -1){
		mpz_add_ui(z, z, 1);
	}
	gmp_printf(" %Zd \n", z );


	//q = 5
	//s = 3
	//z = 3

	//m
	mpz_mod(m, s, p);

	//c
	mpz_powm(c, z, q, p);

	//t
	mpz_powm(t, n, q, p);

	//r
	mpz_add_ui(qexp, q, 1);
	mpz_div_ui(qexp, qexp, 2);
	mpz_powm(r, n, qexp, p);


	mpz_clear(s);
	mpz_clear(q);
	mpz_clear(qexp);
	mpz_clear(qmod2);
	mpz_clear(z);



	gmp_printf(" n=%Zd, p=%Zd \n", n, p );
	gmp_printf(" m=%Zd \n", m);
	gmp_printf(" c=%Zd \n", c);
	gmp_printf(" t=%Zd \n", t);
	gmp_printf(" r=%Zd \n", r);


	mpz_t tpow2;
	mpz_t tres;
	mpz_t iterator;
	mpz_init(tpow2);
	mpz_init(tres);
	mpz_init(iterator);


//loop
	while(true){
		if(mpz_cmp_ui(t, 0) == 0){
			gmp_printf(" FAILED r=0 \n");
			break;
		}
		if(mpz_cmp_ui(t, 1) == 0){
			gmp_printf(" SUCCESS r=%Zd \n", r);
			break;
		}

		mpz_set_ui(iterator, 0);
		while(mpz_cmp(iterator, t) < 0){

			//todo
			//t ^(2 ^(i)) # 1
			mpz_add_ui(iterator, iterator, 1);
		}

	}

	mpz_clear(tpow2);
	mpz_clear(tres);
	mpz_clear(iterator);






	mpz_clear(m);
	mpz_clear(c);
	mpz_clear(t);
	mpz_clear(r);

	return false;
}


