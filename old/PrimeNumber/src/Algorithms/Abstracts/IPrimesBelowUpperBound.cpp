#include "IPrimesBelowUpperBound.h"

namespace AlgorithmsAbstracts {

	IPrimesBelowUpperBound::IPrimesBelowUpperBound() {}

	IPrimesBelowUpperBound::~IPrimesBelowUpperBound() {}

	vector<Elements::PrimeOfQuadraticResidue*> *IPrimesBelowUpperBound::GetPrimesOfQuadraticResidue(mpz_t m0, vector<unsigned long long>* VP){
		vector<Elements::PrimeOfQuadraticResidue*> *VF = new vector<Elements::PrimeOfQuadraticResidue*>();
		VF->push_back(new Elements::PrimeOfQuadraticResidue(2, 1, 1));
		for(unsigned long long vp : *VP){
			if(vp != 2){
				Elements::PrimeOfQuadraticResidue *primeOfQuadraticResidue = new Elements::PrimeOfQuadraticResidue();
				mpz_set_str(primeOfQuadraticResidue->vp, to_string(vp).c_str(), 10);
				if(mpz_legendre(m0, primeOfQuadraticResidue->vp) == 1){
					AlgorithmsSolver::TonelliShanks::Solve(m0, primeOfQuadraticResidue->vp, primeOfQuadraticResidue->m7, primeOfQuadraticResidue->m8);
					primeOfQuadraticResidue->p0 = strtoll(mpz_get_str(NULL, 10, primeOfQuadraticResidue->vp), NULL, 10);
					primeOfQuadraticResidue->c0 = strtoll(mpz_get_str(NULL, 10, primeOfQuadraticResidue->m7), NULL, 10);
					primeOfQuadraticResidue->c1 = strtoll(mpz_get_str(NULL, 10, primeOfQuadraticResidue->m8), NULL, 10);
					VF->push_back(primeOfQuadraticResidue);
				}else{
					delete primeOfQuadraticResidue;
				}
			}
		}
		return VF;
	}
}
