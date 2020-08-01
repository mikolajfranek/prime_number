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
			unsigned long b = Other::MyHelper::GetUpperBoundOfPrimes(input);
			bool foundSolution = false;
			do{
				vector<Elements::QuadraticResidue> factorBase =  {};
				factorBase.push_back(Elements::QuadraticResidue(2, 1, 1));
				vector<unsigned long long> primes = PrimesBelowLimit::SieveOfEratosthenes::GetPrimes(b);





				for(unsigned long long prime : primes){
					Elements::QuadraticResidue residue = Elements::QuadraticResidue();


					//mpz_set_str(residue.Prime, to_string(prime).c_str(), 10);

					factorBase.push_back(residue);

					//if(mpz_legendre(n, residue.Prime) == 1){
						/*
						Solver::TonelliShanks::Solve(n, residue.Prime, residue.Solution1, residue.Solution2);
						mpz_sub(residue.Solution1, residue.Solution1, x);
						mpz_powm_ui(residue.Solution1, residue.Solution1, 1, residue.Prime);
						mpz_sub(residue.Solution2, residue.Solution2, x);
						mpz_powm_ui(residue.Solution2, residue.Solution2, 1, residue.Prime);
						residue.ULLPrime = strtoull(mpz_get_str(NULL, 10, residue.Prime), NULL, 10);
						residue.ULLIndexOfSolution1 = strtoull(mpz_get_str(NULL, 10, residue.Solution1), NULL, 10);
						residue.ULLIndexOfSolution2 = strtoull(mpz_get_str(NULL, 10, residue.Solution2), NULL, 10);
						*/

					//}
				}



				for(Elements::QuadraticResidue quadraticResidue : factorBase){
					printf("--> %ul\n", quadraticResidue.ULLPrime);
				}





				printf("--> end\n");
				break;


			}while(foundSolution == false);
		}

		//check
		Other::MyHelper::CheckResult(n, q, p);

		//clear
		mpz_clears(n, q, p, nmod, x, xrem, lh, rh, ls, rs, NULL);








			/*

			mpz_t *W, *V, *L, *R;
			Other::MyHelper::Malloc(&W, 0);
			Other::MyHelper::Malloc(&V, 0);
			Other::MyHelper::Malloc(&L, 0);
			Other::MyHelper::Malloc(&R, 0);
			mpz_sqrtrem(x, xrem, n);
			if(mpz_cmp_ui(xrem, 0) != 0){
				mpz_add_ui(x, x, 1);
			}
			unsigned long long cp, cf, cs;



//				vector<Elements::QuadraticResidue> residueDTO;
				for (unsigned long long prime : *primes){




//					Elements::QuadraticResidue *residue = new Elements::QuadraticResidue();
//					mpz_set_str(residue->Prime, to_string(prime).c_str(), 10);
//					if(mpz_legendre(n, residue->Prime) == 1){
//						Solver::TonelliShanks::Solve(n, residue->Prime, residue->Solution1, residue->Solution2);
//						mpz_sub(residue->Solution1, residue->Solution1, x);
//						mpz_powm_ui(residue->Solution1, residue->Solution1, 1, residue->Prime);
//						mpz_sub(residue->Solution2, residue->Solution2, x);
//						mpz_powm_ui(residue->Solution2, residue->Solution2, 1, residue->Prime);
//						residue->ULLPrime = strtoull(mpz_get_str(NULL, 10, residue->Prime), NULL, 10);
//						residue->ULLIndexOfSolution1 = strtoull(mpz_get_str(NULL, 10, residue->Solution1), NULL, 10);
//						residue->ULLIndexOfSolution2 = strtoull(mpz_get_str(NULL, 10, residue->Solution2), NULL, 10);
//						factorBase.push_back(residue);
//					}else{
//						delete residue;
//					}
				}
				cp = primes->size();
				delete primes;
				printf("b = %u, cp = %u, fb = %u\n", b, cp, factorBase.size());

				vector<vector<bool>*> A = {};
				cf = 0;
				cs = 0;
				while(cf <= cp){
					cs += 1;
					Other::MyHelper::Realloc(&W, cs);
					Other::MyHelper::Realloc(&V, cs);
					mpz_inits(W[cs-1], V[cs-1], NULL);
					mpz_set_str(V[cs-1], to_string(cs-1).c_str(), 10);
					mpz_add(V[cs-1], V[cs-1], x);
					mpz_pow_ui(V[cs-1], V[cs-1], 2);
					mpz_sub(V[cs-1], V[cs-1], n);
					mpz_set(W[cs-1], V[cs-1]);
					for(Elements::QuadraticResidue* residue : factorBase){
						Other::MyHelper::DivideSieve(W, cs, &residue->ULLIndexOfSolution1, residue->ULLPrime);
						Other::MyHelper::DivideSieve(W, cs, &residue->ULLIndexOfSolution2, residue->ULLPrime);
					}
					if(mpz_cmp_ui(W[cs-1], 1) == 0){
						cf += 1;
						Other::MyHelper::Realloc(&L, cf);
						mpz_init2(L[cf-1], sizeof(mpz_t));
						mpz_set_str(L[cf-1], to_string(cs-1).c_str(), 10);
						mpz_add(L[cf-1], L[cf-1], x);
						mpz_pow_ui(L[cf-1], L[cf-1], 2);
						Other::MyHelper::Realloc(&R, cf);
						mpz_init2(R[cf-1], sizeof(mpz_t));
						mpz_set(R[cf-1], V[cs-1]);
						vector<bool> *row = new vector<bool>;
						for(Elements::QuadraticResidue* residue : factorBase){
							mpz_mod(residue->ModPrime, R[cf-1], residue->Prime);
							row->push_back(mpz_cmp_ui(residue->ModPrime, 0) == 0);
						}
						A.push_back(row);
					}
					printf("b = %u, cp = %u, fb = %u, cf = %u, cs = %u\n", b, cp, factorBase.size(), cf, cs);
				}
				printf("b = %u, cp = %u, fb = %u, cf = %u, cs = %u\n", b, cp, factorBase.size(), cf, cs);

				vector<vector<bool>*> B = Other::MyHelper::GetIdentityMatrix(cf);
				Solver::GaussianElimination::SolveMod2(A, B);

				//TODO

				for(unsigned long long i = 0; i < cf; i++){
					if(accumulate((*A[i]).begin(), (*A[i]).end(), 0) == 0){
						mpz_set_ui(ls, 1);
						mpz_set_ui(rs, 1);
						for(unsigned long long j = 0; j < cf; j++){
							mpz_mul_ui(lh, L[j], (*B[i])[j]);
							if(mpz_cmp_ui(lh, 0) != 0){
								mpz_mul(ls, ls, lh);
							}

							mpz_mul_ui(rh, R[j], (*B[i])[j]);
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



				for(unsigned long long i = 0; i < cs; i++){
					//mpz_clears(W[i], V[i], NULL);
				}
				for(unsigned long long i = 0; i < cf; i++){
					//mpz_clears(L[i], R[i], NULL);
				}
				for (vector<bool> *row : A){
					//delete row;
				}
				for (Elements::QuadraticResidue *residue : factorBase){
					//delete residue;
				}
				b = b * 2;

				break;

			free(W);
			free(V);
			free(L);
			free(R);
		}
		*/

	}
}
