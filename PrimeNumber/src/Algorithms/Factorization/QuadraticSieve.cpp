#include "QuadraticSieve.h"

namespace AlgorithmsFactorization {

	QuadraticSieve::QuadraticSieve() {}

	QuadraticSieve::~QuadraticSieve() {}

	void QuadraticSieve::Factor(string input){

		//declare
		mpz_t m6, m12, m13, m15, r0;

		//init
		mpz_set_str(this->m0, input.c_str(), 10);
		mpz_inits(m6, m12, m13, m15, r0, NULL);

		//algorithm
		mpz_mod_ui(m15, this->m0, 2);
		if(mpz_cmp_ui(m15, 0) == 0){
			mpz_set_ui(this->m1, 2);
			mpz_div_ui(this->m2, this->m0, 2);
		}else{
			AlgorithmsAbstracts::IPrimality* primality = new AlgorithmsPrimality::TrialDivision();
			bool isPrime = primality->IsPrime(input);
			delete primality;
			if(isPrime == true){
				mpz_set_ui(this->m1, 1);
				mpz_set(this->m2, this->m0);
			}else{
				unsigned long m3 = 2;
				mpz_rootrem(r0, m15, this->m0, m3);
				if(mpz_cmp_ui(m15, 0) == 0){
					mpz_set(this->m1, r0);
					mpz_div(this->m2, this->m0, r0);
				}else{
					m3 = 3;
					mpz_rootrem(r0, m15, this->m0, m3);
					if(mpz_cmp_ui(m15, 0) == 0){
						mpz_set(this->m1, r0);
						mpz_div(this->m2, this->m0, r0);
					}else{
						m3 = 5;
						short m4 = 2;
						bool isPowerOfNumber = false;
						do{
							mpz_rootrem(r0, m15, this->m0, m3);
							if(mpz_cmp_ui(m15, 0) == 0){
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
							mpz_sqrtrem(m6, m15, this->m0);
							if(mpz_cmp_ui(m15, 0) != 0){
								mpz_add_ui(m6, m6, 1);
							}
							AlgorithmsAbstracts::IPrimesBelowUpperBound* primesBelowUpperBound = new AlgorithmsPrimesBelowUpperBound::SieveOfEratosthenes();
							vector<unsigned long long>* VP = primesBelowUpperBound->GetPrimes(m5);
							vector<Elements::PrimeOfQuadraticResidue*>* VF = this->AdaptSolutionsToFunction(primesBelowUpperBound->GetPrimesOfQuadraticResidue(this->m0, VP), m6);
							delete VP;
							delete primesBelowUpperBound;
							unsigned long long n0 = 0;
							long long n1 = 0;
							long long n2 = 0;
							unsigned long m9 = VF->size();
							vector<vector<bool>> MD;
							vector<Elements::ElementOfQuadraticSieve*> VS;
							printf("Need to get more than %ld smooth number\n", m9);
							while(n0 <= m9){
								unordered_map<string, Elements::ElementOfQuadraticSieve*> VQ;
								n2 = n1 + 10000;
								for(long long n3 = n1; n3 < n2; n3 = n3 + 1){
									VQ.insert(pair<string, Elements::ElementOfQuadraticSieve*>(to_string(n3), new Elements::ElementOfQuadraticSieve(n3, this->m0, m6, m9+1)));
									VQ.insert(pair<string, Elements::ElementOfQuadraticSieve*>(to_string(-n3), new Elements::ElementOfQuadraticSieve(-n3, this->m0, m6, m9+1)));
								}
								n1 = n2;
								long long m10 = 1;
								for(Elements::PrimeOfQuadraticResidue* vf : *VF){
									while(vf->c0 < n2){
										VQ.at(to_string(vf->c0))->VD[m10] = 1;
										mpz_div(VQ.at(to_string(vf->c0))->c5, VQ.at(to_string(vf->c0))->c5, vf->vp);
										vf->c0 = vf->c0 + vf->p0;
									}
									while(-n2 < vf->c2){
										VQ.at(to_string(vf->c2))->VD[m10] = 1;
										mpz_div(VQ.at(to_string(vf->c2))->c5, VQ.at(to_string(vf->c2))->c5, vf->vp);
										vf->c2 = vf->c2 - vf->p0;
									}
									if(vf->p0 != 2)
									{
										while(vf->c1 < n2){
											VQ.at(to_string(vf->c1))->VD[m10] = 1;
											mpz_div(VQ.at(to_string(vf->c1))->c5, VQ.at(to_string(vf->c1))->c5, vf->vp);
											vf->c1 = vf->c1 + vf->p0;
										}
										while(-n2 < vf->c3){
											VQ.at(to_string(vf->c3))->VD[m10] = 1;
											mpz_div(VQ.at(to_string(vf->c3))->c5, VQ.at(to_string(vf->c3))->c5, vf->vp);
											vf->c3 = vf->c3 - vf->p0;
										}
									}
									m10 = m10 + 1;
								}
								for(pair<string, Elements::ElementOfQuadraticSieve*> vq : VQ){
									bool foundPlusSmooth = mpz_cmp_ui(vq.second->c5, 1) == 0;
									bool foundMinusSmooth = mpz_cmp_si(vq.second->c5, -1) == 0;
									if(foundPlusSmooth == true || foundMinusSmooth == true){
										if(mpz_cmp_ui(vq.second->c7, 0) >= 0){
											if(foundMinusSmooth == true){
												vq.second->VD[0] = 1;
											}
											MD.push_back(vq.second->VD);
											VS.push_back(vq.second);
											n0 = n0 + 1;
											//if(foundSmooth % 1000 == 0){
												printf("Found %ld/%ld smooth numbers\n", n0, m9);
											//}
										}else{
											delete vq.second;
										}
									}else{
										delete vq.second;
									}
								}
							}
							vector<vector<bool>> MU = Elements::MyHelper::GetIdentityMatrix(n0);
							AlgorithmsSolver::GaussianElimination::SolveMod2(MD, MU);
							for(unsigned long long m11 = 0; m11 < n0; m11 = m11 + 1){
								if(accumulate(MD[m11].begin(), MD[m11].end(), 0) == 0){
									mpz_set_ui(m12, 1);
									mpz_set_ui(m13, 1);
									for(unsigned long long m14 = 0; m14 < n0; m14 = m14 + 1){
										if(MU[m11][m14] == true){
											mpz_mul(m12, m12, VS[m14]->c6);
											mpz_mul(m13, m13, VS[m14]->c4);
										}
									}
									mpz_sub(m15, m12, m13);
									mpz_mod(m15, m15, this->m0);
									if(mpz_cmp_ui(m15, 0) == 0){
										mpz_sqrt(m12, m12);
										mpz_sqrt(m13, m13);
										mpz_sub(m15, m12, m13);
										mpz_mod(m15, m15, this->m0);
										if(mpz_cmp_ui(m15, 0) != 0){
											mpz_add(m15, m12, m13);
											mpz_mod(m15, m15, this->m0);
											if(mpz_cmp_ui(m15, 0) != 0){
												mpz_sub(m15, m12, m13);
												mpz_gcd(this->m1, m15, this->m0);
												mpz_add(m15, m12, m13);
												mpz_gcd(this->m2, m15, this->m0);
												break;
											}
										}
									}
								}
							}
							for(Elements::ElementOfQuadraticSieve* vs : VS){
								delete vs;
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
		mpz_clears(m6, m12, m13, m15, r0, NULL);
	}

	vector<Elements::PrimeOfQuadraticResidue*> *QuadraticSieve::AdaptSolutionsToFunction(vector<Elements::PrimeOfQuadraticResidue*> *VF, mpz_t m6){
		for(Elements::PrimeOfQuadraticResidue *vf : *VF){
			mpz_sub(vf->m7, vf->m7, m6);
			mpz_mod(vf->m7, vf->m7, vf->vp);
			mpz_sub(vf->m8, vf->m8, m6);
			mpz_mod(vf->m8, vf->m8, vf->vp);
			vf->c0 = strtoll(mpz_get_str(NULL, 10, vf->m7), NULL, 10);
			vf->c1 = strtoll(mpz_get_str(NULL, 10, vf->m8), NULL, 10);
			vf->c2 = vf->c0 - vf->p0;
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
