#include "../../../../../_old/PrimeNumber/src/Algorithms/Solver/TonelliShanks.h"

namespace AlgorithmsSolver {
	void TonelliShanks::Solve(mpz_t n, mpz_t p, mpz_t solution1, mpz_t solution2){

		mpz_t s, e, f, t, x, g, b, r, m, c, d, temp;
		mpz_inits(s, e, f, t, x, g, b, r, m, c, d, temp, NULL);

		//p-1 = s*2^(e)
		mpz_set_ui(e, 0);
		mpz_sub_ui(s, p, 1);
		mpz_mod_ui(temp, s, 2);
		while(mpz_cmp_ui(temp, 0) == 0){
			mpz_div_ui(s, s, 2);
			mpz_add_ui(e, e, 1);
			mpz_mod_ui(temp, s, 2);
		}

		//find non-residue
		mpz_set_ui(t, 3);
		while(mpz_legendre(t, p) != -1){
			mpz_add_ui(t, t, 1);
		}

		//initizalize
		mpz_powm_ui(r, e, 1, p);
		mpz_powm(g, t, s, p);
		mpz_powm(b, n, s, p);
		mpz_set(temp, s);
		mpz_add_ui(temp, temp, 1);
		mpz_div_ui(temp, temp, 2);
		mpz_powm(x, n, temp, p);

		while(true){
			//search m
			mpz_set_ui(m, 0);
			while(true){
				mpz_set_ui(c, 2);
				Elements::MyHelper::PowCExpD(temp, c, m);
				mpz_powm(f, b, temp, p);
				if(mpz_cmp_ui(f, 1) == 0) break;
				mpz_add_ui(m, m, 1);
			}

			//check
			if(mpz_cmp_ui(m, 0) == 0){
				mpz_set(solution1, x);
				mpz_sub(solution2, p, solution1);
				break;
			}

			//update
			//r-m-1
			mpz_set(d, r);
			mpz_sub(d, d, m);
			mpz_sub_ui(d, d, 1);
			//2^(r-m-1)
			mpz_set_ui(c, 2);
			Elements::MyHelper::PowCExpD(temp, c, d);
			//g^(2^(r-m-1))
			mpz_set(c, g);
			mpz_set(d, temp);
			Elements::MyHelper::PowCExpD(temp, c, d);
			//x * g^(2^(r-m-1))
			mpz_mul(x, x, temp);
			mpz_powm_ui(x, x, 1, p);

			//r-m
			mpz_set(d, r);
			mpz_sub(d, d, m);
			//2^(r-m)
			mpz_set_ui(c, 2);
			Elements::MyHelper::PowCExpD(temp, c, d);
			//g^(2^(r-m))
			mpz_set(c, g);
			mpz_set(d, temp);
			Elements::MyHelper::PowCExpD(temp, c, d);
			//b * g^(2^(r-m))
			mpz_mul(b, b, temp);
			mpz_powm_ui(b, b, 1, p);

			//r-m
			mpz_set(d, r);
			mpz_sub(d, d, m);
			//2^(r-m)
			mpz_set_ui(c, 2);
			Elements::MyHelper::PowCExpD(temp, c, d);
			//g^(2^(r-m))
			mpz_set(c, g);
			mpz_set(d, temp);
			Elements::MyHelper::PowCExpD(g, c, d);
			mpz_powm_ui(g, g, 1, p);

			mpz_set(r, m);
			mpz_powm_ui(r, r, 1, p);
		}

		mpz_clears(s, e, f, t, x, g, b, r, m, c, d, temp, NULL);
	}
}
