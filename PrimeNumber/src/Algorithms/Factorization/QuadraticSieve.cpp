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
			bool isPrime = primality->IsPrime(input);
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
							unsigned long upperBound = this->GetUpperBound(input);
							printf("UpperBound: %ld\n", upperBound);
							Abstracts::PrimesBelowUpperBound *primesBelowUpperBound = new PrimesBelowUpperBound::SieveOfEratosthenes();
							vector<Elements::PrimeOfQuadraticResidue*> *primesOfQuadraticResidue = primesBelowUpperBound->GetPrimesOfQuadraticResidue(upperBound, this->m0);
							delete primesBelowUpperBound;
							primesOfQuadraticResidue = this->AdaptSolutionsToFunction(primesOfQuadraticResidue, m3);
							unsigned long foundSmooth = 0;
							unsigned long minimumSmooth = primesOfQuadraticResidue->size();
							printf("Need to get more than %ld smooth number\n", minimumSmooth);






							long long beginOfInterval = 0;
							long long sizeOfInterval = 10000;



							vector<vector<bool>> matrix;
							vector<Elements::ElementOfQuadraticSieve*> smoothNumbers;

							while(foundSmooth <= minimumSmooth){


								unordered_map<string, Elements::ElementOfQuadraticSieve*> sieve;
								for(long long i = beginOfInterval; i < beginOfInterval + sizeOfInterval; i++){
									sieve.insert(pair<string, Elements::ElementOfQuadraticSieve*>(to_string(i), new Elements::ElementOfQuadraticSieve(i, m0, m3, primesOfQuadraticResidue->size()+1)));
									sieve.insert(pair<string, Elements::ElementOfQuadraticSieve*>(to_string(-i), new Elements::ElementOfQuadraticSieve(-i, m0, m3, primesOfQuadraticResidue->size()+1)));
								}
								beginOfInterval += sizeOfInterval;


								//wykonaj dzielenie
								long long identOfPrime = 1;
								for(Elements::PrimeOfQuadraticResidue* quadraticResidue : *primesOfQuadraticResidue){

									//gmp_printf("%ld \t %ld %ld \n", quadraticResidue->p0, quadraticResidue->s0Minus, quadraticResidue->s0Plus);
									//gmp_printf("%ld \t %ld %ld \n", quadraticResidue->p0, quadraticResidue->s1Minus, quadraticResidue->s1Plus);

									while(quadraticResidue->s0Plus < beginOfInterval){
										sieve.at(to_string(quadraticResidue->s0Plus))->divisors[identOfPrime] = 1;
										mpz_div(sieve.at(to_string(quadraticResidue->s0Plus))->divisible, sieve.at(to_string(quadraticResidue->s0Plus))->divisible, quadraticResidue->prime);
										quadraticResidue->s0Plus += quadraticResidue->p0;
									}
									while(-beginOfInterval < quadraticResidue->s0Minus){
										sieve.at(to_string(quadraticResidue->s0Minus))->divisors[identOfPrime] = 1;
										mpz_div(sieve.at(to_string(quadraticResidue->s0Minus))->divisible, sieve.at(to_string(quadraticResidue->s0Minus))->divisible, quadraticResidue->prime);
										quadraticResidue->s0Minus -= quadraticResidue->p0;
									}
									if(quadraticResidue->p0 == 2) continue;
									while(quadraticResidue->s1Plus < beginOfInterval){
										sieve.at(to_string(quadraticResidue->s1Plus))->divisors[identOfPrime] = 1;
										mpz_div(sieve.at(to_string(quadraticResidue->s1Plus))->divisible, sieve.at(to_string(quadraticResidue->s1Plus))->divisible, quadraticResidue->prime);
										quadraticResidue->s1Plus += quadraticResidue->p0;
									}
									while(-beginOfInterval < quadraticResidue->s1Minus){
										sieve.at(to_string(quadraticResidue->s1Minus))->divisors[identOfPrime] = 1;
										mpz_div(sieve.at(to_string(quadraticResidue->s1Minus))->divisible, sieve.at(to_string(quadraticResidue->s1Minus))->divisible, quadraticResidue->prime);
										quadraticResidue->s1Minus -= quadraticResidue->p0;
									}
									identOfPrime += 1;
								}



								for(pair<string, Elements::ElementOfQuadraticSieve*> element : sieve){

									//gmp_printf("%ld \t %Zd Zd \n", element.first, element.second->oryginal, element.second->divisible);

									bool foundMinusSmooth = false;
									if(mpz_cmp_si(element.second->divisible, -1) == 0){
										element.second->divisors[0] = 1;
										foundMinusSmooth = true;
									}
									if(foundMinusSmooth == true || (mpz_cmp_ui(element.second->divisible, 1) == 0)){

										if(element.second->hasOverMinusSqrt == false){


											if(foundSmooth % 1000 == 0){
												printf("Found %ld/%ld smooth number\n", foundSmooth, minimumSmooth);
											}
											foundSmooth++;
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


							for(Elements::ElementOfQuadraticSieve* element : smoothNumbers){
								delete element;
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
		mpz_clears(m3, m4, m5, m6, n0, r0, NULL);
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
