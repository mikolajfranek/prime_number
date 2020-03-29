#include "QuadraticSieve.h"

void QuadraticSieve::Factor(string input){

	//declare
	mpz_t z_n;
	mpz_t z_nmod2;
	mpz_t z_nsqrt;
	mpz_t z_nsqrtrem;
	mpz_t z_p;
	mpz_t z_q;
	mpz_t z_prime;

	//init
	mpz_init_set_str(z_n, input.c_str(), 10);
	mpz_init(z_nmod2);
	mpz_init(z_nsqrt);
	mpz_init(z_nsqrtrem);
	mpz_init(z_p);
	mpz_init(z_q);
	mpz_init(z_prime);

	//start algorithm
	mpz_mod_ui(z_nmod2, z_n, 2);
	if(mpz_cmp_ui(z_nmod2, 0) == 0){
		mpz_div_ui(z_q, z_n, 2);
		mpz_set_ui(z_p, 2);
	}else{

		mpz_sqrt(z_nsqrt, z_n);
		mpz_sqrtrem(z_nsqrt, z_nsqrtrem, z_n);
		if(mpz_cmp_ui(z_nsqrt, 0) != 0){
			mpz_add_ui(z_nsqrt, z_nsqrt, 1);
		}


		mpz_t R[100];
		for(int i=0;i<100;i++) mpz_init2(R[i], sizeof(mpz_t));

		for(int i=0;i<100;i++){
			 mpz_set_ui(R[i], i);
			 mpz_add(R[i], R[i], z_nsqrt);
			 mpz_pow_ui(R[i], R[i], 2);
			 mpz_sub(R[i], R[i], z_n);
		}



		int primes[4] = {2,17,23,29};
		for(int j = 0; j < 4; j++){

			mpz_set_ui(z_prime, primes[j]);

			//for p > 2 there is two result
			long r1, r2;
			Tonelli_Shanks(z_n, z_prime, r1, r2);


			if(r1 != -1){
				cout << r1 << endl;
				r1 = (r1  - mpz_get_ui(z_nsqrt)) % primes[j];
				cout << r1 << endl;

				for(int x = r1; x < 100; x+=primes[j]){
					mpz_div_ui(R[x], R[x], primes[j]);
				}
			}

			if(r2 != -1){
				cout << r2 << endl;
				r2 = (r2  - mpz_get_ui(z_nsqrt)) ;
				cout << r2 << endl;

				for(int x = r2; x < 100; x+=primes[j]){
					mpz_div_ui(R[x], R[x], primes[j]);
				}
			}


		}

		//for(int i=0;i<100;i++) cout << R[i] << endl;

		return;







		for(int i=0;i<100;i++) mpz_clear(R[i]);





		//wybierz B
		//wubierz alfa

		//utworz wektor do siewania
		//utworz funkcje Qx
		//zepelnij siewnik Qx

		//dla kazdej liczby z bazy czynnikow:
			//rozwiaz rownanie - Tonelli_Shanks
			//rozwiazanie pozwala



		//2, 23 - init condition failed
		//17, 29 - ok
		//mpz_set_ui(z_iterator, 29);
		//Tonelli_Shanks(z_n, z_iterator);
	}

	Algorithm::CheckResult(z_n, z_p, z_q);

	//clear
	mpz_clear(z_n);
	mpz_clear(z_nmod2);
	mpz_clear(z_nsqrt);
	mpz_clear(z_nsqrtrem);
	mpz_clear(z_p);
	mpz_clear(z_q);
	mpz_clear(z_prime);
}



void QuadraticSieve::Tonelli_Shanks(mpz_t n, mpz_t p, long& r1, long &r2){

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
		r1 = -1;
		r2 = -1;
		//return false;
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
	//gmp_printf(" %Zd \n", z );


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



	//gmp_printf(" n=%Zd, p=%Zd \n", n, p );
	//gmp_printf(" m=%Zd \n", m);
	//gmp_printf(" c=%Zd \n", c);
	//gmp_printf(" t=%Zd \n", t);
	//gmp_printf(" r=%Zd \n", r);


	mpz_t b;
	mpz_t tpow2;
	mpz_t msub;
	mpz_t tres;
	mpz_t iterator;
	mpz_t helper;
	mpz_init(b);
	mpz_init(tpow2);
	mpz_init(msub);
	mpz_init(tres);
	mpz_init(iterator);
	mpz_init(helper);


//loop
	while(true){
		if(mpz_cmp_ui(t, 0) == 0){
			gmp_printf(" FAILED r=0 \n");
			r1 = -1;
			r2 = -1;
			break;
		}
		if(mpz_cmp_ui(t, 1) == 0){
			gmp_printf(" SUCCESS r=%Zd \n", r);
			r1 = mpz_get_ui(r);

			if(mpz_get_ui(p) > 2){
				mpz_mul_si(r, r, -1);
				mpz_mod(r, r , p);

				r2 = mpz_get_ui(r);
			}else{
				r2 = -1;
			}

			break;
		}


		mpz_set_ui(iterator, 1);
		while(mpz_cmp(iterator, m) < 0){

			//power
			mpz_set_ui(tpow2, 2);
			for(mpz_set_ui(helper, 2); mpz_cmp(helper, iterator) <= 0; mpz_add_ui(helper, helper, 1)){
				mpz_mul_ui(tpow2, tpow2, 2);
			}

			//mul t
			mpz_set(tres, t);
			for(;mpz_cmp_ui(tpow2, 1) > 0; mpz_sub_ui(tpow2, tpow2, 1)){
				mpz_mul(tres, tres, t);
			}

			//congruence
			mpz_mod(tres, tres, p);
			if(mpz_cmp_ui(tres, 1) == 0) break;


			mpz_add_ui(iterator, iterator, 1);
		}



		//gmp_printf(" iterator=%Zd \n", iterator );


		mpz_set(msub, m);
		mpz_sub(msub, msub, iterator);
		mpz_sub_ui(msub, msub, 1);



		//power
		mpz_set_ui(tpow2, 2);
		for(mpz_set_ui(helper, 2); mpz_cmp(helper, msub) <= 0; mpz_add_ui(helper, helper, 1)){
			mpz_mul_ui(tpow2, tpow2, 2);
		}


		//mul b
		mpz_set(b, c);
		if(mpz_cmp_ui(msub, 0) != 0){
			for(;mpz_cmp_ui(tpow2, 1) > 0; mpz_sub_ui(tpow2, tpow2, 1)){
				mpz_mul(b, b, c);
			}
		}
		mpz_powm_ui(b, b, 1, p);



		mpz_set(m, iterator);
		mpz_powm_ui(m, m, 1, p);

		mpz_powm_ui(c, b, 2, p);

		mpz_mul(t, t, c);
		mpz_powm_ui(t, t, 1, p);

		mpz_mul(r, r, b);
		mpz_powm_ui(r, r, 1, p);


	}

	mpz_clear(b);
	mpz_clear(tpow2);
	mpz_clear(msub);
	mpz_clear(tres);
	mpz_clear(iterator);
	mpz_clear(helper);



	mpz_clear(m);
	mpz_clear(c);
	mpz_clear(t);
	mpz_clear(r);
}


