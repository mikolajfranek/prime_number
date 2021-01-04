#include "PrimesBelowUpperBound.h"

namespace Abstracts {

	PrimesBelowUpperBound::PrimesBelowUpperBound() {}

	PrimesBelowUpperBound::~PrimesBelowUpperBound() {}

	vector<Elements::PrimeOfQuadraticResidue*> *PrimesBelowUpperBound::GetPrimesOfQuadraticResidue(unsigned long upperBound, mpz_t m0){
		vector<Elements::PrimeOfQuadraticResidue*> *primesOfQuadraticResidue = new vector<Elements::PrimeOfQuadraticResidue*>();
		primesOfQuadraticResidue->push_back(new Elements::PrimeOfQuadraticResidue(2, 1, 1));
		for(unsigned long long prime : this->GetPrimes(upperBound)){
			if(prime > LLONG_MAX){
				printf("Error: Abstracts::PrimesBelowUpperBound::GetPrimesOfQuadraticResidues\n");
				throw;
			}
			if(prime == 2) continue;
			Elements::PrimeOfQuadraticResidue *primeOfQuadraticResidue = new Elements::PrimeOfQuadraticResidue();
			mpz_set_str(primeOfQuadraticResidue->prime, to_string(prime).c_str(), 10);
			if(mpz_legendre(m0, primeOfQuadraticResidue->prime) == 1){

				Solver::TonelliShanks::Solve(m0, primeOfQuadraticResidue->prime, primeOfQuadraticResidue->solution0, primeOfQuadraticResidue->solution1);
				primeOfQuadraticResidue->p0 = strtoll(mpz_get_str(NULL, 10, primeOfQuadraticResidue->prime), NULL, 10);
				primeOfQuadraticResidue->s0 = strtoll(mpz_get_str(NULL, 10, primeOfQuadraticResidue->solution0), NULL, 10);
				primeOfQuadraticResidue->s1 = strtoll(mpz_get_str(NULL, 10, primeOfQuadraticResidue->solution1), NULL, 10);
				primesOfQuadraticResidue->push_back(primeOfQuadraticResidue);
			}else{
				delete primeOfQuadraticResidue;
			}
		}
		return primesOfQuadraticResidue;
	}
}
