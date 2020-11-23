#include "QuadraticSieve.h"

namespace Factorization {

	QuadraticSieve::QuadraticSieve() {}

	QuadraticSieve::~QuadraticSieve() {}

	void QuadraticSieve::Factor(string input){

		//declare
		//...

		//init
		mpz_set_str(n0, input.c_str(), 10);
		//...

		//algorithm
		//...


		//clear
		//...






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



		}


		printf("end\n");
		//clear
		mpz_clears(n, q, p, nmod, x, xrem, lh, rh, ls, rs, NULL);
		return;
	}
}


		/*

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
			mpz_sqrtrem(x, xrem, n);
			if(mpz_cmp_ui(xrem, 0) != 0){
				mpz_add_ui(x, x, 1);
			}
			unsigned long b = Other::MyHelper::GetUpperBoundOfPrimes(input);
			unsigned long long cp, cf, cs;

			bool foundSolution = false;
			do{
				vector<Elements::QuadraticResidue> factorBase =  {Elements::QuadraticResidue(2, 1, 1)};
				vector<unsigned long long> primes = PrimesBelowLimit::SieveOfEratosthenes::GetPrimes(b);
				for(unsigned long long prime : primes){
					Elements::QuadraticResidue residue = Elements::QuadraticResidue();
					mpz_set_str(residue.Prime, to_string(prime).c_str(), 10);
					if(mpz_legendre(n, residue.Prime) == 1){
						Solver::TonelliShanks::Solve(n, residue.Prime, residue.Solution1, residue.Solution2);
						mpz_sub(residue.Solution1, residue.Solution1, x);
						mpz_powm_ui(residue.Solution1, residue.Solution1, 1, residue.Prime);
						mpz_sub(residue.Solution2, residue.Solution2, x);
						mpz_powm_ui(residue.Solution2, residue.Solution2, 1, residue.Prime);
						residue.ULLPrime = strtoull(mpz_get_str(NULL, 10, residue.Prime), NULL, 10);
						residue.ULLIndexOfSolution1 = strtoull(mpz_get_str(NULL, 10, residue.Solution1), NULL, 10);
						residue.ULLIndexOfSolution2 = strtoull(mpz_get_str(NULL, 10, residue.Solution2), NULL, 10);
						factorBase.push_back(residue);
					}
				}
				cp = primes.size();
				printf("b = %u, fb = %u, cp = %u\n", b, factorBase.size(), cp);

				vector<Elements::ElementOfSieve> W = {};
				vector<Elements::ElementOfSieve> V = {};
				vector<Elements::ElementOfSieve> L = {};
				vector<Elements::ElementOfSieve> R = {};
				vector<vector<bool>> A = {};
				cf = 0;
				cs = 0;
				while(cf <= cp){
					cs += 1;
					Elements::ElementOfSieve elementOfSieve1 = Elements::ElementOfSieve();
					mpz_set_str(elementOfSieve1.Number, to_string(cs-1).c_str(), 10);
					mpz_add(elementOfSieve1.Number, elementOfSieve1.Number, x);
					mpz_pow_ui(elementOfSieve1.Number, elementOfSieve1.Number, 2);
					mpz_sub(elementOfSieve1.Number, elementOfSieve1.Number, n);
					W.push_back(elementOfSieve1);
					V.push_back(elementOfSieve1.DeepCopy());
					for(Elements::QuadraticResidue residue : factorBase){
						Other::MyHelper::DivideSieve(W, cs, &residue.ULLIndexOfSolution1, residue.ULLPrime);
						Other::MyHelper::DivideSieve(W, cs, &residue.ULLIndexOfSolution2, residue.ULLPrime);
					}
					if(mpz_cmp_ui(W[cs-1].Number, 1) == 0){
						cf += 1;
						Elements::ElementOfSieve elementOfSieve2 = Elements::ElementOfSieve();
						mpz_set_str(elementOfSieve2.Number, to_string(cs-1).c_str(), 10);
						mpz_add(elementOfSieve2.Number, elementOfSieve2.Number, x);
						mpz_pow_ui(elementOfSieve2.Number, elementOfSieve2.Number, 2);
						L.push_back(elementOfSieve2);
						Elements::ElementOfSieve elementOfSieve3 = Elements::ElementOfSieve();
						mpz_set(elementOfSieve3.Number, V[cs-1].Number);
						R.push_back(elementOfSieve3);
						vector<bool> row = {};
						for(Elements::QuadraticResidue residue : factorBase){
							mpz_mod(residue.ModPrime, R[cf-1].Number, residue.Prime);
							row.push_back(mpz_cmp_ui(residue.ModPrime, 0) == 0);
						}
						A.push_back(row);
					}
					printf("b = %u, fb = %u, cp = %u, cf = %u, cs = %u\n", b, factorBase.size(), cp, cf, cs);
				}
				printf("b = %u, fb = %u, cp = %u, cf = %u, cs = %u\n", b, factorBase.size(), cp, cf, cs);

				vector<vector<bool>> B = Other::MyHelper::GetIdentityMatrix(cf);

				//TODO
				//ERROR
				Solver::GaussianElimination::SolveMod2(A, B);


				for(unsigned long long i = 0; i < cf; i++){
					if(accumulate(A[i].begin(), A[i].end(), 0) == 0){
						mpz_set_ui(ls, 1);
						mpz_set_ui(rs, 1);
						for(unsigned long long j = 0; j < cf; j++){
							mpz_mul_ui(lh, L[j].Number, B[i][j]);
							if(mpz_cmp_ui(lh, 0) != 0){
								mpz_mul(ls, ls, lh);
							}

							mpz_mul_ui(rh, R[j].Number, B[i][j]);
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

				break;

			}while(foundSolution == false);


		//check
		//CheckResult(n, q, p);

		//clear
		mpz_clears(n, q, p, nmod, x, xrem, lh, rh, ls, rs, NULL);
		*/

