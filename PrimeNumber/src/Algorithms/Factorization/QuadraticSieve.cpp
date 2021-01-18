#include "QuadraticSieve.h"

namespace AlgorithmsFactorization {

	QuadraticSieve::QuadraticSieve() {}

	QuadraticSieve::~QuadraticSieve() {}

	void QuadraticSieve::Factor(string input){

		//parent
		AlgorithmsAbstracts::IFactorization::Factor(input);

		//declare
		mpz_t m6, m12, m13, n4, r0;

		//init
		mpz_inits(m6, m12, m13, n4, r0, NULL);

		//algorithm
		unsigned long m3 = this->GetUpperBound(input);
		mpz_set_ui(n4, m3);
		AlgorithmsFactorization::TrialDivision *trialDivision = new AlgorithmsFactorization::TrialDivision();
		trialDivision->Factor(input, n4);
		bool foundNotTrivial = trialDivision->AreFactorsTrivial() == false;
		if(foundNotTrivial == true){
			mpz_set(this->m1, trialDivision->m1);
			mpz_set(this->m2, trialDivision->m2);
		}
		delete trialDivision;
		if(foundNotTrivial == false){
			AlgorithmsAbstracts::IPrimality* primality = new AlgorithmsPrimality::TrialDivision();
			bool isPrime = primality->IsPrime(input);
			delete primality;
			if(isPrime == true){
				mpz_set_ui(this->m1, 1);
				mpz_set(this->m2, this->m0);
			}else{
				unsigned long m4 = 2;
				mpz_rootrem(r0, n4, this->m0, m4);
				if(mpz_cmp_ui(n4, 0) == 0){
					mpz_set(this->m1, r0);
					mpz_div(this->m2, this->m0, r0);
				}else{
					m4 = 3;
					mpz_rootrem(r0, n4, this->m0, m4);
					if(mpz_cmp_ui(n4, 0) == 0){
						mpz_set(this->m1, r0);
						mpz_div(this->m2, this->m0, r0);
					}else{
						m4 = 5;
						short m5 = 2;
						bool isPowerOfNumber = false;
						do{
							mpz_rootrem(r0, n4, this->m0, m4);
							if(mpz_cmp_ui(n4, 0) == 0){
								mpz_set(this->m1, r0);
								mpz_div(this->m2, this->m0, r0);
								isPowerOfNumber = true;
								break;
							}
							m4 = m4 + m5;
							m5 = 6 - m5;
						}while(mpz_cmp_ui(r0, 1) > 0);
						if(isPowerOfNumber == false){
							mpz_sqrtrem(m6, n4, this->m0);
							if(mpz_cmp_ui(n4, 0) != 0){
								mpz_add_ui(m6, m6, 1);
							}
							AlgorithmsAbstracts::IPrimesBelowUpperBound* primesBelowUpperBound = new AlgorithmsPrimesBelowUpperBound::SieveOfEratosthenes();
							vector<unsigned long long>* VP = primesBelowUpperBound->GetPrimes(m3);
							vector<Elements::PrimeOfQuadraticResidue*>* VF = this->AdaptSolutionsToFunction(primesBelowUpperBound->GetPrimesOfQuadraticResidue(this->m0, VP), m6);
							delete VP;
							delete primesBelowUpperBound;
							bool firstIteration = true;
							unsigned long long n0 = 0;
							long long n1 = 0;
							long long n2 = 0;
							unsigned long long n3 = 0;
							unsigned long m9 = VF->size();
							vector<vector<bool>> MD;
							vector<vector<bool>> MU;
							vector<Elements::ElementOfQuadraticSieve*> VS;
							while(this->AreFactorsSet() == false){
								printf("Need to get more than %ld smooth number\n", m9);
								while(n0 <= m9 || n0 == n3){
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
												//if(foundSmooth % 100 == 0){
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
								n3 = n0;
								if(firstIteration == true){
									firstIteration = false;
									MU = Elements::MyHelper::GetIdentityMatrix(n0);
								}else{
									Elements::MyHelper::FitIdentityMatrix(MU, n0);
								}
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
										mpz_sub(n4, m12, m13);
										mpz_mod(n4, n4, this->m0);
										if(mpz_cmp_ui(n4, 0) == 0){
											mpz_sqrt(m12, m12);
											mpz_sqrt(m13, m13);
											mpz_sub(n4, m12, m13);
											mpz_mod(n4, n4, this->m0);
											if(mpz_cmp_ui(n4, 0) != 0){
												mpz_add(n4, m12, m13);
												mpz_mod(n4, n4, this->m0);
												if(mpz_cmp_ui(n4, 0) != 0){
													mpz_sub(n4, m12, m13);
													mpz_gcd(this->m1, n4, this->m0);
													mpz_add(n4, m12, m13);
													mpz_gcd(this->m2, n4, this->m0);
													break;
												}
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
		mpz_clears(m6, m12, m13, n4, r0, NULL);
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
		printf("UpperBound: %ld\n", result);
		return result;
	}
}
