#include "QuadraticSieve.h"

namespace Factorization {

	QuadraticSieve::QuadraticSieve() {}

	QuadraticSieve::~QuadraticSieve() {}

	void QuadraticSieve::Factor(string input){

		//declare
		mpz_t m3, m4, n0, r0;

		//init
		mpz_set_str(this->m0, input.c_str(), 10);
		mpz_inits(m3, m4, n0, r0, NULL);

		//algorithm
		mpz_mod_ui(m4, this->m0, 2);
		if(mpz_cmp_ui(m4, 0) == 0){
			mpz_set_ui(this->m1, 2);
			mpz_div_ui(this->m2, this->m0, 2);
		}else{
			Abstracts::Primality *primality = new Primality::TrialDivision();
			bool isPrime = primality->IsPrime(input.c_str());
			delete primality;
			if(isPrime == true){
				mpz_set_ui(this->m1, 1);
				mpz_set(this->m2, this->m0);
			}else{
				unsigned long int a = 2;
				mpz_rootrem(r0, m4, this->m0, a);
				if(mpz_cmp_ui(m4, 0) == 0){
					mpz_set(this->m1, r0);
					mpz_div(this->m2, this->m0, r0);
				}else{
					a = 3;
					mpz_rootrem(r0, m4, this->m0, a);
					if(mpz_cmp_ui(m4, 0) == 0){
						mpz_set(this->m1, r0);
						mpz_div(this->m2, this->m0, r0);
					}else{
						a = 5;
						short b = 2;
						bool isPowerOfNumber = false;
						do{
							mpz_rootrem(r0, m4, this->m0, a);
							if(mpz_cmp_ui(m4, 0) == 0){
								mpz_set(this->m1, r0);
								mpz_div(this->m2, this->m0, r0);
								isPowerOfNumber = true;
								break;
							}
							a = a + b;
							b = 6 - b;
						}while(mpz_cmp_ui(r0, 1) > 0);
						if(isPowerOfNumber == false){
							mpz_sqrtrem(m3, m4, m0);
							if(mpz_cmp_ui(m4, 0) != 0){
								mpz_add_ui(m3, m3, 1);
							}
							unsigned long upperBound = Elements::MyHelper::GetUpperBoundOfPrimes(input);

							Abstracts::PrimesBelowUpperBound *primesBelowUpperBound = new PrimesBelowUpperBound::SieveOfEratosthenes();
							vector<Elements::QuadraticResidue*> *quadraticResidues = this->GetQuadraticResidues(primesBelowUpperBound->GetQuadraticResidues(upperBound, this->m0), m3);
							delete primesBelowUpperBound;





							//TODO START

							for(Elements::QuadraticResidue* quadraticResidue : *quadraticResidues){
								printf("%u %u %u\n", quadraticResidue->p0, quadraticResidue->m0, quadraticResidue->m1);
							}
							printf("%ul\n", upperBound);

							//TODO END



							//clean pointers
							for(Elements::QuadraticResidue* quadraticResidue : *quadraticResidues){
								delete quadraticResidue;
							}
							delete quadraticResidues;
						}
					}
				}
			}
		}

		//clear
		mpz_clears(m3, m4, n0, r0, NULL);
	}

	vector<Elements::QuadraticResidue*> *QuadraticSieve::GetQuadraticResidues(vector<Elements::QuadraticResidue*> *quadraticResidues, mpz_t m3){
		for(Elements::QuadraticResidue *quadraticResidue : *quadraticResidues){
			mpz_sub(quadraticResidue->solution0, quadraticResidue->solution0, m3);
			mpz_powm_ui(quadraticResidue->solution0, quadraticResidue->solution0, 1, quadraticResidue->prime);
			mpz_sub(quadraticResidue->solution1, quadraticResidue->solution1, m3);
			mpz_powm_ui(quadraticResidue->solution1, quadraticResidue->solution1, 1, quadraticResidue->prime);
			quadraticResidue->p0 = strtoull(mpz_get_str(NULL, 10, quadraticResidue->prime), NULL, 10);
			quadraticResidue->m0 = strtoull(mpz_get_str(NULL, 10, quadraticResidue->solution0), NULL, 10);
			quadraticResidue->m1 = strtoull(mpz_get_str(NULL, 10, quadraticResidue->solution1), NULL, 10);
		}
		return quadraticResidues;
	}
}








/*
			//TODO
			mpz_sqrtrem(x, xrem, n);
			if(mpz_cmp_ui(xrem, 0) != 0){
				mpz_add_ui(x, x, 1);
			}
			unsigned long b = Other::MyHelper::GetUpperBoundOfPrimes(input);
			unsigned long long cp, cf, cs;

			bool foundSolution = false;
			do{


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

