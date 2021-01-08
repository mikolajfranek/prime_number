#include "QuadraticSieve.h"

namespace Factorization {

	QuadraticSieve::QuadraticSieve() {}

	QuadraticSieve::~QuadraticSieve() {}

	void QuadraticSieve::Factor(string input){

		//declare
		mpz_t m6, m17, m18, m19, r0;

		//init
		mpz_set_str(this->m0, input.c_str(), 10);
		mpz_inits(m6, m17, m18, m19, r0, NULL);

		//algorithm
		mpz_mod_ui(m19, this->m0, 2);
		if(mpz_cmp_ui(m19, 0) == 0){
			mpz_set_ui(this->m1, 2);
			mpz_div_ui(this->m2, this->m0, 2);
		}else{
			Abstracts::Primality* primality = new Primality::TrialDivision();
			bool isPrime = primality->IsPrime(input);
			delete primality;
			if(isPrime == true){
				mpz_set_ui(this->m1, 1);
				mpz_set(this->m2, this->m0);
			}else{
				unsigned long m3 = 2;
				mpz_rootrem(r0, m19, this->m0, m3);
				if(mpz_cmp_ui(m19, 0) == 0){
					mpz_set(this->m1, r0);
					mpz_div(this->m2, this->m0, r0);
				}else{
					m3 = 3;
					mpz_rootrem(r0, m19, this->m0, m3);
					if(mpz_cmp_ui(m19, 0) == 0){
						mpz_set(this->m1, r0);
						mpz_div(this->m2, this->m0, r0);
					}else{
						m3 = 5;
						short m4 = 2;
						bool isPowerOfNumber = false;
						do{
							mpz_rootrem(r0, m19, this->m0, m3);
							if(mpz_cmp_ui(m19, 0) == 0){
								mpz_set(this->m1, r0);
								mpz_div(this->m2, this->m0, r0);
								isPowerOfNumber = true;
								break;
							}
							m3 = m3 + m4;
							m4 = 6 - m4;
						}while(mpz_cmp_ui(r0, 1) > 0);
						if(isPowerOfNumber == false){
							unsigned long m5 = this->GetUpperBound(input);
							printf("UpperBound: %ld\n", m5);
							mpz_sqrtrem(m6, m19, this->m0);
							if(mpz_cmp_ui(m19, 0) != 0){
								mpz_add_ui(m6, m6, 1);
							}
							Abstracts::PrimesBelowUpperBound* primesBelowUpperBound = new PrimesBelowUpperBound::SieveOfEratosthenes();
							vector<unsigned long long>* VP = primesBelowUpperBound->GetPrimes(m5);
							vector<Elements::PrimeOfQuadraticResidue*>* VF = this->AdaptSolutionsToFunction(primesBelowUpperBound->GetPrimesOfQuadraticResidue(this->m0, VP), m6);
							delete VP;
							delete primesBelowUpperBound;














							//przesiewanie
							unsigned long found = 0;
							unsigned long minimum = VF->size();
							printf("Need to get more than %ld smooth number\n", minimum);
							long long begin = 0;
							long long end = 0;
							long long sizeOfInterval = 10000;
							vector<Elements::ElementOfQuadraticSieve*> smoothNumbers;
							vector<vector<bool>> matrix;
							while(found <= minimum){
								unordered_map<string, Elements::ElementOfQuadraticSieve*> sieve;
								end = begin + sizeOfInterval;
								for(long long i = begin; i < end; i++){
									sieve.insert(pair<string, Elements::ElementOfQuadraticSieve*>(to_string(i), new Elements::ElementOfQuadraticSieve(i, this->m0, m6, VF->size()+1)));
									sieve.insert(pair<string, Elements::ElementOfQuadraticSieve*>(to_string(-i), new Elements::ElementOfQuadraticSieve(-i, this->m0, m6, VF->size()+1)));
								}


								begin = end;
								long long identOfPrime = 1;
								for(Elements::PrimeOfQuadraticResidue* quadraticResidue : *VF){
									while(quadraticResidue->c0 < end){
										sieve.at(to_string(quadraticResidue->c0))->divisors[identOfPrime] = 1;
										mpz_div(sieve.at(to_string(quadraticResidue->c0))->divisible, sieve.at(to_string(quadraticResidue->c0))->divisible, quadraticResidue->vp);
										quadraticResidue->c0 += quadraticResidue->p0;
									}
									while(-end < quadraticResidue->c2){
										sieve.at(to_string(quadraticResidue->c2))->divisors[identOfPrime] = 1;
										mpz_div(sieve.at(to_string(quadraticResidue->c2))->divisible, sieve.at(to_string(quadraticResidue->c2))->divisible, quadraticResidue->vp);
										quadraticResidue->c2 -= quadraticResidue->p0;
									}
									if(quadraticResidue->p0 != 2)
									{
										while(quadraticResidue->c1 < end){
											sieve.at(to_string(quadraticResidue->c1))->divisors[identOfPrime] = 1;
											mpz_div(sieve.at(to_string(quadraticResidue->c1))->divisible, sieve.at(to_string(quadraticResidue->c1))->divisible, quadraticResidue->vp);
											quadraticResidue->c1 += quadraticResidue->p0;
										}
										while(-end < quadraticResidue->c3){
											sieve.at(to_string(quadraticResidue->c3))->divisors[identOfPrime] = 1;
											mpz_div(sieve.at(to_string(quadraticResidue->c3))->divisible, sieve.at(to_string(quadraticResidue->c3))->divisible, quadraticResidue->vp);
											quadraticResidue->c3 -= quadraticResidue->p0;
										}
									}
									identOfPrime += 1;
								}
								for(pair<string, Elements::ElementOfQuadraticSieve*> element : sieve){
									bool foundMinusSmooth = mpz_cmp_si(element.second->divisible, -1) == 0;
									bool foundPlusSmooth = mpz_cmp_ui(element.second->divisible, 1) == 0;
									if(foundMinusSmooth == true || foundPlusSmooth == true){
										if(element.second->overMinusSqrt == false){
											if(foundMinusSmooth == true){
												element.second->divisors[0] = 1;
											}

											//if(foundSmooth % 1000 == 0){
												printf("Found %ld/%ld smooth numbers\n", found, minimum);
											//}
											found++;
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


							//rozwiązywanie układu równań
							vector<vector<bool>> identity = Elements::MyHelper::GetIdentityMatrix(found);
							Solver::GaussianElimination::SolveMod2(matrix, identity);


							//odszukwanie rozwiązania, bo na pewno istnieje?
							bool foundSoultion = false;
							for(unsigned long long i = 0; i < found && foundSoultion == false; i++){
								if(accumulate(matrix[i].begin(), matrix[i].end(), 0) == 0){
									mpz_set_ui(m17, 1);
									mpz_set_ui(m18, 1);
									for(unsigned long long j = 0; j < found; j++){
										if(identity[i][j] == true){
											mpz_mul(m17, m17, smoothNumbers[j]->element);
											mpz_mul(m18, m18, smoothNumbers[j]->oryginal);
										}
									}
									mpz_sub(m19, m17, m18);
									mpz_mod(m19, m19, this->m0);
									if(mpz_cmp_ui(m19, 0) == 0){
										mpz_sqrt(m17, m17);
										mpz_sqrt(m18, m18);
										mpz_sub(m19, m17, m18);
										mpz_mod(m19, m19, this->m0);
										if(mpz_cmp_ui(m19, 0) != 0){
											mpz_add(m19, m17, m18);
											mpz_mod(m19, m19, this->m0);
											if(mpz_cmp_ui(m19, 0) != 0){
												mpz_sub(m19, m17, m18);
												mpz_gcd(this->m1, m19, this->m0);
												mpz_add(m19, m17, m18);
												mpz_gcd(this->m2, m19, this->m0);
												foundSoultion = true;
											}
										}
									}
								}
							}
							for(Elements::ElementOfQuadraticSieve* elementOfQuadraticSieve : smoothNumbers){
								delete elementOfQuadraticSieve;
							}









							for(Elements::PrimeOfQuadraticResidue* vf : *VF){
								delete vf;
							}
							delete VF;
						}
					}
				}
			}
		}

		//clear
		mpz_clears(m6, m17, m18, m19, r0, NULL);
	}

	vector<Elements::PrimeOfQuadraticResidue*> *QuadraticSieve::AdaptSolutionsToFunction(vector<Elements::PrimeOfQuadraticResidue*> *VF, mpz_t m6){
		for(Elements::PrimeOfQuadraticResidue *vf : *VF){
			mpz_sub(vf->m7, vf->m7, m6);
			mpz_mod(vf->m7, vf->m7, vf->vp);
			mpz_sub(vf->m8, vf->m8, m6);
			mpz_mod(vf->m8, vf->m8, vf->vp);
			vf->c0 = strtoll(mpz_get_str(NULL, 10, vf->m7), NULL, 10);
			vf->c2 = vf->c0 - vf->p0;
			vf->c1 = strtoll(mpz_get_str(NULL, 10, vf->m8), NULL, 10);
			vf->c3 = vf->c1 - vf->p0;
		}
		return VF;
	}

	unsigned long QuadraticSieve::GetUpperBound(string input){
		mpfr_t m0, lnOfm0, upperBound, ulongMax;
		mpfr_inits(m0, lnOfm0, upperBound, ulongMax,  NULL);
		mpfr_set_str(m0, input.c_str(), 10, MPFR_RNDU);
		mpfr_log(lnOfm0, m0, MPFR_RNDU);
		mpfr_log(upperBound, lnOfm0, MPFR_RNDU);
		mpfr_mul(upperBound, lnOfm0, upperBound, MPFR_RNDU);
		mpfr_sqrt(upperBound, upperBound, MPFR_RNDU);
		mpfr_mul_d(upperBound, upperBound, 0.5, MPFR_RNDU);
		mpfr_exp(upperBound, upperBound, MPFR_RNDU);
		mpfr_set_str(ulongMax, to_string(ULONG_MAX).c_str(), 10, MPFR_RNDU);
		if(mpfr_cmp(upperBound, ulongMax) > 0){
			printf("Error: Algorithms::QuadraticSieve::GetUpperBound\n");
			throw;
		}
		unsigned long result = mpfr_get_ui(upperBound, MPFR_RNDU);
		mpfr_clears(m0, lnOfm0, upperBound, ulongMax, NULL);
		return result;
	}
}
