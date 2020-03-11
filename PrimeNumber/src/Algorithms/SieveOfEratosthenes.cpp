#include "SieveOfEratosthenes.h"

SieveOfEratosthenes::SieveOfEratosthenes() {}

void SieveOfEratosthenes::Factor(string input){
	const char *text = input.c_str();

	mpz_t n;
	mpz_t p;
	mpz_t q;
	mpz_t iterator;
	mpz_t iterator_step;
	mpz_t modulo;
	mpz_t n_sqrt;
	mpz_t n_div_iterator;

	mpz_init_set_str(n, text, 10);
	mpz_init(p);
	mpz_init(q);
	mpz_init_set_str(iterator, "3", 10);
	mpz_init_set_str(iterator_step, "2", 10);
	mpz_init(modulo);
	mpz_init(n_sqrt);

	mpz_sqrt(n_sqrt, n);
	while(iterator < n_sqrt){
		mpz_mod(modulo, n, iterator);
		if(modulo == 0){
			mpz_set(p, iterator);
			mpz_div(n_div_iterator, n, iterator);
			mpz_set(q, n_div_iterator);

			gmp_printf("%Zd = %Zd * %Zd\n", n, p, q);
			return;
		}
		mpz_add(iterator, iterator, iterator_step);
	}

	gmp_printf("%Zd = %Zd * %Zd\n", n, p, q);

	mpz_clear(n);
	mpz_clear(p);
	mpz_clear(q);
}

SieveOfEratosthenes::~SieveOfEratosthenes() {}
