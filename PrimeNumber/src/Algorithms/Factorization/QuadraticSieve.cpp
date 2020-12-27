#include "QuadraticSieve.h"

namespace Factorization {

	QuadraticSieve::QuadraticSieve() {}

	QuadraticSieve::~QuadraticSieve() {}

	void QuadraticSieve::Factor(string input){

		//declare
		mpz_t m5, m6, m7, m8, r0;

		//init
		mpz_set_str(this->m0, input.c_str(), 10);
		mpz_inits(m5, m6, m7, m8, r0, NULL);

		//algorithm
		mpz_mod_ui(m8, this->m0, 2);
		if(mpz_cmp_ui(m8, 0) == 0){
			mpz_set_ui(this->m1, 2);
			mpz_div_ui(this->m2, this->m0, 2);
		}else{
			Abstracts::Primality *primality = new Primality::TrialDivision();
			bool isPrime = primality->IsPrime(input);
			delete primality;
			if(isPrime == true){
				mpz_set_ui(this->m1, 1);
				mpz_set(this->m2, this->m0);
			}else{
				unsigned long m3 = 2;
				mpz_rootrem(r0, m8, this->m0, m3);
				if(mpz_cmp_ui(m8, 0) == 0){
					mpz_set(this->m1, r0);
					mpz_div(this->m2, this->m0, r0);
				}else{
					m3 = 3;
					mpz_rootrem(r0, m8, this->m0, m3);
					if(mpz_cmp_ui(m8, 0) == 0){
						mpz_set(this->m1, r0);
						mpz_div(this->m2, this->m0, r0);
					}else{
						m3 = 5;
						short m4 = 2;
						bool isPowerOfNumber = false;
						do{
							mpz_rootrem(r0, m8, this->m0, m3);
							if(mpz_cmp_ui(m8, 0) == 0){
								mpz_set(this->m1, r0);
								mpz_div(this->m2, this->m0, r0);
								isPowerOfNumber = true;
								break;
							}
							m3 = m3 + m4;
							m4 = 6 - m4;
						}while(mpz_cmp_ui(r0, 1) > 0);
						if(isPowerOfNumber == false){
							mpz_sqrtrem(m5, m8, this->m0);
							if(mpz_cmp_ui(m8, 0) != 0){
								mpz_add_ui(m5, m5, 1);
							}







							unsigned long upperBound = this->GetUpperBound(input);
							printf("UpperBound: %ld\n", upperBound);
							Abstracts::PrimesBelowUpperBound *primesBelowUpperBound = new PrimesBelowUpperBound::SieveOfEratosthenes();
							vector<Elements::PrimeOfQuadraticResidue*> *primesOfQuadraticResidue = primesBelowUpperBound->GetPrimesOfQuadraticResidue(upperBound, this->m0);
							delete primesBelowUpperBound;
							primesOfQuadraticResidue = this->AdaptSolutionsToFunction(primesOfQuadraticResidue, m5);
							unsigned long foundSmooth = 0;
							unsigned long minimumSmooth = primesOfQuadraticResidue->size();
							printf("Need to get more than %ld smooth number\n", minimumSmooth);
							long long beginOfInterval = 0;
							long long endOfInterval = 0;
							long long sizeOfInterval = 10000;
							vector<Elements::ElementOfQuadraticSieve*> smoothNumbers;
							vector<vector<bool>> matrix;
							while(foundSmooth <= minimumSmooth){
								unordered_map<string, Elements::ElementOfQuadraticSieve*> sieve;
								endOfInterval = beginOfInterval + sizeOfInterval;
								for(long long i = beginOfInterval; i < endOfInterval; i++){
									sieve.insert(pair<string, Elements::ElementOfQuadraticSieve*>(to_string(i), new Elements::ElementOfQuadraticSieve(i, this->m0, m5, primesOfQuadraticResidue->size()+1)));
									sieve.insert(pair<string, Elements::ElementOfQuadraticSieve*>(to_string(-i), new Elements::ElementOfQuadraticSieve(-i, this->m0, m5, primesOfQuadraticResidue->size()+1)));
								}
								beginOfInterval = endOfInterval;
								long long identOfPrime = 1;
								for(Elements::PrimeOfQuadraticResidue* quadraticResidue : *primesOfQuadraticResidue){
									while(quadraticResidue->s0Plus < endOfInterval){
										sieve.at(to_string(quadraticResidue->s0Plus))->divisors[identOfPrime] = 1;
										mpz_div(sieve.at(to_string(quadraticResidue->s0Plus))->divisible, sieve.at(to_string(quadraticResidue->s0Plus))->divisible, quadraticResidue->prime);
										quadraticResidue->s0Plus += quadraticResidue->p0;
									}
									while(-endOfInterval < quadraticResidue->s0Minus){
										sieve.at(to_string(quadraticResidue->s0Minus))->divisors[identOfPrime] = 1;
										mpz_div(sieve.at(to_string(quadraticResidue->s0Minus))->divisible, sieve.at(to_string(quadraticResidue->s0Minus))->divisible, quadraticResidue->prime);
										quadraticResidue->s0Minus -= quadraticResidue->p0;
									}
									if(quadraticResidue->p0 == 2) continue;
									while(quadraticResidue->s1Plus < endOfInterval){
										sieve.at(to_string(quadraticResidue->s1Plus))->divisors[identOfPrime] = 1;
										mpz_div(sieve.at(to_string(quadraticResidue->s1Plus))->divisible, sieve.at(to_string(quadraticResidue->s1Plus))->divisible, quadraticResidue->prime);
										quadraticResidue->s1Plus += quadraticResidue->p0;
									}
									while(-endOfInterval < quadraticResidue->s1Minus){
										sieve.at(to_string(quadraticResidue->s1Minus))->divisors[identOfPrime] = 1;
										mpz_div(sieve.at(to_string(quadraticResidue->s1Minus))->divisible, sieve.at(to_string(quadraticResidue->s1Minus))->divisible, quadraticResidue->prime);
										quadraticResidue->s1Minus -= quadraticResidue->p0;
									}
									identOfPrime += 1;
								}
								for(pair<string, Elements::ElementOfQuadraticSieve*> element : sieve){
									bool foundMinusSmooth = mpz_cmp_si(element.second->divisible, -1) == 0;
									bool foundPlusSmooth = mpz_cmp_ui(element.second->divisible, 1) == 0;
									if(foundMinusSmooth == true || foundPlusSmooth == true){
										if(foundMinusSmooth == true){
											element.second->divisors[0] = 1;
										}
										if(element.second->overMinusSqrt == false){
											//if(foundSmooth % 1000 == 0){
												printf("Found %ld/%ld smooth numbers\n", foundSmooth, minimumSmooth);
											//}
											foundSmooth++;
											smoothNumbers.push_back(element.second);
											matrix.push_back(element.second->divisors);
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
							for(unsigned long long i = 0; i < foundSmooth; i++){
								if(accumulate(matrix[i].begin(), matrix[i].end(), 0) == 0){
									mpz_set_ui(m6, 1);
									mpz_set_ui(m7, 1);
									for(unsigned long long j = 0; j < foundSmooth; j++){
										if(identity[i][j] == true){
											mpz_mul(m6, m6, smoothNumbers[j]->oryginal);
											mpz_mul(m7, m7, smoothNumbers[j]->element);
										}
									}
									mpz_sqrt(m6, m6);
									mpz_sqrt(m7, m7);
									mpz_sub(m8, m6, m7);
									mpz_mod(m8, m8, this->m0);
									if(mpz_cmp_ui(m8, 0) != 0){
										mpz_add(m8, m6, m7);
										mpz_mod(m8, m8, this->m0);
										if(mpz_cmp_ui(m8, 0) != 0){
											mpz_sub(m8, m6, m7);
											mpz_abs(m8, m8);
											mpz_gcd(this->m1, m8, this->m0);
											mpz_add(m8, m6, m7);
											mpz_gcd(this->m2, m8, this->m0);
										}
									}
								}
							}
							for(Elements::ElementOfQuadraticSieve* elementOfQuadraticSieve : smoothNumbers){
								delete elementOfQuadraticSieve;
							}
							for(Elements::PrimeOfQuadraticResidue* primeOfQuadraticResidue : *primesOfQuadraticResidue){
								delete primeOfQuadraticResidue;
							}
							delete primesOfQuadraticResidue;
						}
					}
				}
			}
		}

		//clear
		mpz_clears(m5, m6, m7, m8, r0, NULL);
	}

	vector<Elements::PrimeOfQuadraticResidue*> *QuadraticSieve::AdaptSolutionsToFunction(vector<Elements::PrimeOfQuadraticResidue*> *primesOfQuadraticResidue, mpz_t m3){
		for(Elements::PrimeOfQuadraticResidue *primeOfQuadraticResidue : *primesOfQuadraticResidue){
			mpz_sub(primeOfQuadraticResidue->solution0, primeOfQuadraticResidue->solution0, m3);
			mpz_mod(primeOfQuadraticResidue->solution0, primeOfQuadraticResidue->solution0, primeOfQuadraticResidue->prime);
			mpz_sub(primeOfQuadraticResidue->solution1, primeOfQuadraticResidue->solution1, m3);
			mpz_mod(primeOfQuadraticResidue->solution1, primeOfQuadraticResidue->solution1, primeOfQuadraticResidue->prime);
			primeOfQuadraticResidue->s0 = strtoll(mpz_get_str(NULL, 10, primeOfQuadraticResidue->solution0), NULL, 10);
			primeOfQuadraticResidue->s0Plus = primeOfQuadraticResidue->s0;
			primeOfQuadraticResidue->s0Minus = primeOfQuadraticResidue->s0 - primeOfQuadraticResidue->p0;
			primeOfQuadraticResidue->s1 = strtoll(mpz_get_str(NULL, 10, primeOfQuadraticResidue->solution1), NULL, 10);
			primeOfQuadraticResidue->s1Plus = primeOfQuadraticResidue->s1;
			primeOfQuadraticResidue->s1Minus = primeOfQuadraticResidue->s1 - primeOfQuadraticResidue->p0;
		}
		return primesOfQuadraticResidue;
	}

	unsigned long QuadraticSieve::GetUpperBound(string input){
		mpfr_t m0, ln, upperBound;
		mpfr_inits(m0, ln, upperBound, NULL);
		mpfr_set_str(m0, input.c_str(), 10, MPFR_RNDU);
		mpfr_log(ln, m0, MPFR_RNDU);
		mpfr_log(upperBound, ln, MPFR_RNDU);
		mpfr_mul(upperBound, ln, upperBound, MPFR_RNDU);
		mpfr_sqrt(upperBound, upperBound, MPFR_RNDU);
		mpfr_mul_d(upperBound, upperBound, 0.5, MPFR_RNDU);
		mpfr_exp(upperBound, upperBound, MPFR_RNDU);
		unsigned long result = mpfr_get_ui(upperBound, MPFR_RNDU);
		mpfr_clears(m0, ln, upperBound, NULL);
		return result;
	}
}
