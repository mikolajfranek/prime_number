#include "SieveOfEratosthenes.h"

namespace PrimesBelowUpperBound {

	SieveOfEratosthenes::SieveOfEratosthenes() {}

	SieveOfEratosthenes::~SieveOfEratosthenes() {}

	void SieveOfEratosthenes::SearchPrimes(unsigned long long upperBound){
		bool v[upperBound+1];
		memset(v, true, upperBound+1);
		for(unsigned long long i = 2; i*i <= upperBound; i++){
			if(v[i] == true){
				for(unsigned long long j = i*i; j <= upperBound; j+=i){
					v[j] = false;
				}
			}
		}
		this->primes = {};
		for(unsigned long long i = 2; i <= upperBound; i++){
			if(v[i] == true){
				this->primes.push_back(i);
			}
		}
	}
}
