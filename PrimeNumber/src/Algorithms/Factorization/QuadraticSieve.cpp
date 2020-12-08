#include "QuadraticSieve.h"

namespace Factorization {

	QuadraticSieve::QuadraticSieve() {}

	QuadraticSieve::~QuadraticSieve() {}

	void QuadraticSieve::Factor(string input){

		//declare
		mpz_t m3, m4, m5, m6, n0, r0;

		//init
		mpz_set_str(this->m0, input.c_str(), 10);
		mpz_inits(m3, m4, m5, m6, n0, r0, NULL);

		//algorithm
		mpz_mod_ui(m6, this->m0, 2);
		if(mpz_cmp_ui(m6, 0) == 0){
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
				mpz_rootrem(r0, m6, this->m0, a);
				if(mpz_cmp_ui(m6, 0) == 0){
					mpz_set(this->m1, r0);
					mpz_div(this->m2, this->m0, r0);
				}else{
					a = 3;
					mpz_rootrem(r0, m6, this->m0, a);
					if(mpz_cmp_ui(m6, 0) == 0){
						mpz_set(this->m1, r0);
						mpz_div(this->m2, this->m0, r0);
					}else{
						a = 5;
						short b = 2;
						bool isPowerOfNumber = false;
						do{
							mpz_rootrem(r0, m6, this->m0, a);
							if(mpz_cmp_ui(m6, 0) == 0){
								mpz_set(this->m1, r0);
								mpz_div(this->m2, this->m0, r0);
								isPowerOfNumber = true;
								break;
							}
							a = a + b;
							b = 6 - b;
						}while(mpz_cmp_ui(r0, 1) > 0);
						if(isPowerOfNumber == false){
							mpz_sqrtrem(m3, m6, m0);
							if(mpz_cmp_ui(m6, 0) != 0){
								mpz_add_ui(m3, m3, 1);
							}
							//TODO










							long long upperBound = this->GetUpperBoundOfPrimes(input);
							long long sizeOfSieve = 10000;
							printf("UpperBound: %u\n", upperBound);
							upperBound = 150;

							Abstracts::PrimesBelowUpperBound *primesBelowUpperBound = new PrimesBelowUpperBound::SieveOfEratosthenes();
							vector<Elements::QuadraticResidue*> *quadraticResidues = primesBelowUpperBound->GetQuadraticResidues(upperBound, this->m0);
							delete primesBelowUpperBound;
							quadraticResidues = this->GetQuadraticResidues(quadraticResidues, m3);
							long long foundSmooth = 0;
							long long minimumSmooth = quadraticResidues->size();
							printf("Need to get more than %u smooth number\n", minimumSmooth);








							long long sizeOfFactorBase = quadraticResidues->size()+1;
							vector<vector<bool>> matrix;
							vector<Elements::ElementOfQuadraticSieve*> smoothNumbers;
							long long h = 0;
							while(foundSmooth <= minimumSmooth){
								map<long long, Elements::ElementOfQuadraticSieve*> sieve;
								for(long long i = h; i < h + sizeOfSieve; i++){
									sieve.insert(pair<long long, Elements::ElementOfQuadraticSieve*>(i, new Elements::ElementOfQuadraticSieve(i, m0, m3, sizeOfFactorBase)));
									sieve.insert(pair<long long, Elements::ElementOfQuadraticSieve*>(-i, new Elements::ElementOfQuadraticSieve(-i, m0, m3, sizeOfFactorBase)));
								}
								h += sizeOfSieve;


								//wykonaj dzielenie
								long long ident = 1;
								for(Elements::QuadraticResidue* quadraticResidue : *quadraticResidues){

									//gmp_printf("%ld \t %ld %ld \n", quadraticResidue->p0, quadraticResidue->s0Minus, quadraticResidue->s0Plus);
									//gmp_printf("%ld \t %ld %ld \n", quadraticResidue->p0, quadraticResidue->s1Minus, quadraticResidue->s1Plus);

									while(quadraticResidue->s0Plus < h){
										sieve[quadraticResidue->s0Plus]->divisors[ident] = 1;
										mpz_div(sieve[quadraticResidue->s0Plus]->divisible, sieve[quadraticResidue->s0Plus]->divisible, quadraticResidue->prime);
										quadraticResidue->s0Plus += quadraticResidue->p0;
									}
									while(-h < quadraticResidue->s0Minus){
										sieve[quadraticResidue->s0Minus]->divisors[ident] = 1;
										mpz_div(sieve[quadraticResidue->s0Minus]->divisible, sieve[quadraticResidue->s0Minus]->divisible, quadraticResidue->prime);
										quadraticResidue->s0Minus -= quadraticResidue->p0;
									}
									if(quadraticResidue->p0 == 2) continue;
									while(quadraticResidue->s1Plus < h){
										sieve[quadraticResidue->s1Plus]->divisors[ident] = 1;
										mpz_div(sieve[quadraticResidue->s1Plus]->divisible, sieve[quadraticResidue->s1Plus]->divisible, quadraticResidue->prime);
										quadraticResidue->s1Plus += quadraticResidue->p0;
									}
									while(-h < quadraticResidue->s1Minus){
										sieve[quadraticResidue->s1Minus]->divisors[ident] = 1;
										mpz_div(sieve[quadraticResidue->s1Minus]->divisible, sieve[quadraticResidue->s1Minus]->divisible, quadraticResidue->prime);
										quadraticResidue->s1Minus -= quadraticResidue->p0;
									}
									ident += 1;
								}



								for(pair<long long, Elements::ElementOfQuadraticSieve*> element : sieve){

									//gmp_printf("%ld \t %Zd Zd \n", element.first, element.second->oryginal, element.second->divisible);

									bool foundMinusSmooth = false;
									if(mpz_cmp_si(element.second->divisible, -1) == 0){
										element.second->divisors[0] = 1;
										foundMinusSmooth = true;
									}
									if(foundMinusSmooth == true || (mpz_cmp_ui(element.second->divisible, 1) == 0)){

										if(element.second->hasOverMinusSqrt == false){

											foundSmooth++;
											//if(foundSmooth % 100 == 0){
												printf("Found %ld/%ld smooth number\n", foundSmooth, minimumSmooth);
											//}
											matrix.push_back(element.second->divisors);
											smoothNumbers.push_back(element.second);
										}else{
											delete element.second;
										}
									}else{
										delete element.second;
									}
								}
							}






							vector<vector<bool>> identity = Elements::MyHelper::GetIdentityMatrix(foundSmooth);

							Solver::GaussianElimination::SolveMod2(matrix, identity);



							for(unsigned long i = 0; i < matrix.size(); i++){
								if(accumulate(matrix[i].begin(), matrix[i].end(), 0) == 0){
									mpz_set_ui(m4, 1);
									mpz_set_ui(m5, 1);

									for(unsigned long j = 0; j < identity.size(); j++){
										if(identity[i][j] == true){
											mpz_mul(m4, m4, smoothNumbers[j]->oryginal);
											mpz_mul(m5, m5, smoothNumbers[j]->ident);
											mpz_mul(m5, m5, smoothNumbers[j]->ident);
										}
									}


									mpz_sqrt(m4, m4);
									mpz_sqrt(m5, m5);

									mpz_sub(m6, m4, m5);
									mpz_mod(m6, m6, m0);
									if(mpz_cmp_ui(m6, 0) != 0){
										mpz_add(m6, m4, m5);
										mpz_mod(m6, m6, m0);
										if(mpz_cmp_ui(m6, 0) != 0){

											mpz_sub(m6, m4, m5);
											mpz_abs(m6, m6);
											mpz_gcd(m1, m6, m0);

											mpz_add(m6, m4, m5);
											mpz_gcd(m2, m6, m0);
										}
									}
								}
							}





							//clean pointers
							for(Elements::ElementOfQuadraticSieve* element : smoothNumbers){
								delete element;
							}
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
		mpz_clears(m3, m4, m5, m6, n0, r0, NULL);
	}

	vector<Elements::QuadraticResidue*> *QuadraticSieve::GetQuadraticResidues(vector<Elements::QuadraticResidue*> *quadraticResidues, mpz_t m3){
		for(Elements::QuadraticResidue *quadraticResidue : *quadraticResidues){
			mpz_sub(quadraticResidue->solution0, quadraticResidue->solution0, m3);
			mpz_powm_ui(quadraticResidue->solution0, quadraticResidue->solution0, 1, quadraticResidue->prime);
			mpz_sub(quadraticResidue->solution1, quadraticResidue->solution1, m3);
			mpz_powm_ui(quadraticResidue->solution1, quadraticResidue->solution1, 1, quadraticResidue->prime);
			quadraticResidue->p0 = strtoull(mpz_get_str(NULL, 10, quadraticResidue->prime), NULL, 10);
			quadraticResidue->s0 = strtoull(mpz_get_str(NULL, 10, quadraticResidue->solution0), NULL, 10);
			quadraticResidue->s0Plus = quadraticResidue->s0;
			quadraticResidue->s0Minus = quadraticResidue->s0 - quadraticResidue->p0;
			quadraticResidue->s1 = strtoull(mpz_get_str(NULL, 10, quadraticResidue->solution1), NULL, 10);
			quadraticResidue->s1Plus = quadraticResidue->s1;
			quadraticResidue->s1Minus = quadraticResidue->s1 - quadraticResidue->p0;
		}
		return quadraticResidues;
	}

	long long QuadraticSieve::GetUpperBoundOfPrimes(string input){
		mpfr_t n, lnOfN, upperBound;
		mpfr_inits(n, lnOfN, upperBound, NULL);
		mpfr_set_str(n, input.c_str(), 10, MPFR_RNDU);
		mpfr_log(lnOfN, n, MPFR_RNDU);
		mpfr_log(upperBound, lnOfN, MPFR_RNDU);
		mpfr_mul(upperBound, lnOfN, upperBound, MPFR_RNDU);
		mpfr_sqrt(upperBound, upperBound, MPFR_RNDU);
		mpfr_mul_d(upperBound, upperBound, 0.5, MPFR_RNDU);
		mpfr_exp(upperBound, upperBound, MPFR_RNDU);
		long long result = mpfr_get_ui(upperBound, MPFR_RNDU);
		mpfr_clears(n, lnOfN, upperBound, NULL);
		return result;
	}
}
