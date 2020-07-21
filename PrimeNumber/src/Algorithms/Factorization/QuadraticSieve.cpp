#include "QuadraticSieve.h"

namespace Factorization {
	void QuadraticSieve::Factor(string input){

		//declare
		mpz_t n, q, p, nmod, x, xrem, lh, rh, ls, rs;

		//init
		mpz_inits(n, q, p, nmod, x, xrem, lh, rh, ls, rs, NULL);

		//set
		mpz_set_str(n, input.c_str(), 10);

		//start algorithm
		mpz_mod_ui(nmod, n, 2);
		if(mpz_cmp_ui(nmod, 0) == 0){
			mpz_div_ui(q, n, 2);
			mpz_set_ui(p, 2);
		}else{
			if(Primality::TrialDivision::IsPrime(n) == true){
				mpz_set(q, n);
				mpz_set_ui(p, 1);
			}else{
				bool isPowerOfPrime = false;
				unsigned long int k = 2;
				do{
					mpz_rootrem(x, xrem, n, k);
					if(mpz_cmp_ui(xrem, 0) == 0){
						mpz_div(q, n, x);
						mpz_set(p, x);
						isPowerOfPrime = true;
						break;
					}
					k = k + 1;
				}while(mpz_cmp_ui(x, 1) > 0);
				if(isPowerOfPrime == false){
					//TODO


				}
			}










			//TODO
			/*
			 * zarzadzanie pamiecia
			 * testowanie
			 * odmierzenie czasu, ktora czesc najdluzej?
			 */


			//wartość optymalna
			unsigned long long b = Other::MyHelper::GetUpperBoundOfPrimes(n);

			printf("b = %u\n", b);
			return;

			unsigned long long csAdd = 10000;


			mpz_sqrtrem(x, xrem, n);
			if(mpz_cmp_ui(xrem, 0) != 0){
				mpz_add_ui(x, x, 1);
			}
			bool foundSolution = false;
			unsigned long long cs = 0, cp = 0, cf, cb;
			mpz_t* W;
			mpz_t* V;
			Other::MyHelper::Malloc(&W, cs);
			Other::MyHelper::Malloc(&V, cs);
			vector<Elements::QuadraticResidue*> factorBase;
			mpz_t *L;
			mpz_t *R;
			Other::MyHelper::Malloc(&L, cp);
			Other::MyHelper::Malloc(&R, cp);
			do{
				factorBase = {new Elements::QuadraticResidue(2, 1, 1)};
				vector<vector<bool>> A = {}; //TUTAJ JEST ERROR
				vector<unsigned long long>* primes = PrimesBelowLimit::SieveOfEratosthenes::GetPrimes(b);
				for (unsigned long long prime : *primes){
					Elements::QuadraticResidue* residue = new Elements::QuadraticResidue();
					mpz_set_str(residue->Prime, to_string(prime).c_str(), 10);
					if(mpz_legendre(n, residue->Prime) == 1){
						Solver::TonelliShanks::Solve(n, residue->Prime, residue->Solution1, residue->Solution2);
						mpz_sub(residue->Solution1, residue->Solution1, x);
						mpz_powm_ui(residue->Solution1, residue->Solution1, 1, residue->Prime);
						mpz_sub(residue->Solution2, residue->Solution2, x);
						mpz_powm_ui(residue->Solution2, residue->Solution2, 1, residue->Prime);
						residue->ULLPrime = strtoull(mpz_get_str(NULL, 10, residue->Prime), NULL, 10);
						residue->ULLIndexOfSolution1 = strtoull(mpz_get_str(NULL, 10, residue->Solution1), NULL, 10);
						residue->ULLIndexOfSolution2 = strtoull(mpz_get_str(NULL, 10, residue->Solution2), NULL, 10);
						factorBase.push_back(residue);
					}
				}
				cp = primes->size();
				printf("b = %u, cp = %u\n", b, cp);

				delete primes;
				cf = 0;
				cb = 0;
				while(cf <= cp){
					cb = cs;
					cs = cs + csAdd;
					Other::MyHelper::Realloc(&W, cs);
					Other::MyHelper::Realloc(&V, cs);
					for(unsigned long long i = cb; i < cs; i++) {
						mpz_init2(W[i], sizeof(mpz_t));
						mpz_init2(V[i], sizeof(mpz_t));
						mpz_set_str(V[i], to_string(i).c_str(), 10);
						mpz_add(V[i], V[i], x);
						mpz_pow_ui(V[i], V[i], 2);
						mpz_sub(V[i], V[i], n);
						mpz_set(W[i], V[i]);
					}

					//ERROR
					printf("b = %u, fb = %u, cf = %u, cp = %u, cs = %u\n", b, factorBase.size(), cf, cp, cs);
					for(Elements::QuadraticResidue* residue : factorBase){
						Other::MyHelper::DivideSieve(W, cs, &residue->ULLIndexOfSolution1, residue->ULLPrime);
						Other::MyHelper::DivideSieve(W, cs, &residue->ULLIndexOfSolution2, residue->ULLPrime);
						gmp_printf("--- %Zd ---\n", residue->Prime);
					}
					printf("---\n");

					for(unsigned long long i = cb; i < cs; i++) {
						if(mpz_cmp_ui(W[i], 1) == 0){
							cf++;
							Other::MyHelper::Realloc(&L, cf);
							mpz_init2(L[cf-1], sizeof(mpz_t));
							mpz_set_str(L[cf-1], to_string(i).c_str(), 10);
							mpz_add(L[cf-1], L[cf-1], x);
							mpz_pow_ui(L[cf-1], L[cf-1], 2);
							Other::MyHelper::Realloc(&R, cf);
							mpz_init2(R[cf-1], sizeof(mpz_t));
							mpz_set(R[cf-1], V[i]);
							vector<bool> row = {};
							for(Elements::QuadraticResidue* residue : factorBase){
								mpz_mod(residue->ModPrime, R[cf-1], residue->Prime);
								row.push_back(mpz_cmp_ui(residue->ModPrime, 0) == 0); //ERROR
							}
							A.push_back(row);
						}
					}
				}
				printf("### b = %u, fb = %u, cf = %u, cp = %u, cs = %u\n", b, factorBase.size(), cf, cp, cs);
				vector<vector<bool>> B = Other::MyHelper::GetIdentityMatrix(cf);
				Solver::GaussianElimination::SolveMod2(A, B);
				for(unsigned long long i = 0; i < cf; i++){
					if(accumulate(A[i].begin(), A[i].end(), 0) == 0){
						mpz_set_ui(ls, 1);
						mpz_set_ui(rs, 1);
						for(unsigned long long j = 0; j < cf; j++){
							mpz_mul_ui(lh, L[j], B[i][j]);
							if(mpz_cmp_ui(lh, 0) != 0){
								mpz_mul(ls, ls, lh);
							}
							mpz_mul_ui(rh, R[j], B[i][j]);
							if(mpz_cmp_ui(rh, 0) != 0){
								mpz_mul(rs, rs, rh);
							}
						}
						if(mpz_congruent_p(ls, rs, n) != 0){
							mpz_sqrt(ls, ls);
							mpz_sqrt(rs, rs);
							mpz_sub(lh, ls, rs);
							mpz_add(rh, ls, rs);
							mpz_abs(lh, lh);
							mpz_abs(rh, rh);
							mpz_gcd(p, lh, n);
							mpz_gcd(q, rh, n);
							if(mpz_cmp_ui(p, 1) != 0 && mpz_cmp_ui(q, 1) != 0){
								foundSolution = true;
								break;
							}
						}
					}
				}
				b = b * 2;
				for(unsigned long long i = 0; i < cs; i++){
					mpz_clear(W[i]);
					mpz_clear(V[i]);
				}
				for(unsigned long long i = 0; i < cf; i++){
					mpz_clear(L[i]);
					mpz_clear(R[i]);
				}
			}while(foundSolution == false);

			free(W);
			free(V);
			free(L);
			free(R);
		}


		//check
		Other::MyHelper::CheckResult(n, q, p);

		//clear
		mpz_clears(n, q, p, nmod, x, xrem, lh, rh, ls, rs, NULL);
	}
}
