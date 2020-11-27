#include "PrimesBelowUpperBound.h"

namespace Abstracts {

	PrimesBelowUpperBound::PrimesBelowUpperBound() {}

	PrimesBelowUpperBound::~PrimesBelowUpperBound() {}

	vector<Elements::QuadraticResidue*>* PrimesBelowUpperBound::GetQuadraticResidues(unsigned long long upperBound, mpz_t m0){
		vector<Elements::QuadraticResidue*> *quadraticResidues = new vector<Elements::QuadraticResidue*>();
		quadraticResidues->push_back(new Elements::QuadraticResidue(2, 1, 1));
		for(unsigned long long prime : this->GetPrimes(upperBound)){
			Elements::QuadraticResidue* quadraticResidue = new Elements::QuadraticResidue();
			mpz_set_str(quadraticResidue->prime, to_string(prime).c_str(), 10);
			if(mpz_legendre(m0, quadraticResidue->prime) == 1){
				Solver::TonelliShanks::Solve(m0, quadraticResidue->prime, quadraticResidue->solution0, quadraticResidue->solution1);
				quadraticResidue->p0 = strtoull(mpz_get_str(NULL, 10, quadraticResidue->prime), NULL, 10);
				quadraticResidue->m0 = strtoull(mpz_get_str(NULL, 10, quadraticResidue->solution0), NULL, 10);
				quadraticResidue->m1 = strtoull(mpz_get_str(NULL, 10, quadraticResidue->solution1), NULL, 10);
				quadraticResidues->push_back(quadraticResidue);
			}else{
				delete quadraticResidue;
			}
		}
		return quadraticResidues;
	}
}
