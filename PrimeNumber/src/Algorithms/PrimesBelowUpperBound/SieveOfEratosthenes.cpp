#include "SieveOfEratosthenes.h"

namespace PrimesBelowUpperBound {

	SieveOfEratosthenes::SieveOfEratosthenes() {}

	SieveOfEratosthenes::~SieveOfEratosthenes() {}

	vector<unsigned long long>* SieveOfEratosthenes::GetPrimes(unsigned long long upperBound){
		vector<bool> VB(upperBound+1, true);
		for(unsigned long long m0 = 2; m0*m0 <= upperBound; m0++){
			if(VB[m0] == true){
				for(unsigned long long j = m0*m0; j <= upperBound; j+=m0){
					VB[j] = false;
				}
			}
		}
		vector<unsigned long long>* primes = new vector<unsigned long long>();
		for(unsigned long long m0 = 2; m0 <= upperBound; m0++){
			if(VB[m0] == true){
				primes->push_back(m0);
			}
		}
		return primes;
	}
}
