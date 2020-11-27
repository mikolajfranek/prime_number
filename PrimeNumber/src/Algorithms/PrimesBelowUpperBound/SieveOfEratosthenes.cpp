#include "SieveOfEratosthenes.h"

namespace PrimesBelowUpperBound {

	SieveOfEratosthenes::SieveOfEratosthenes() {}

	SieveOfEratosthenes::~SieveOfEratosthenes() {}

	vector<unsigned long long> SieveOfEratosthenes::GetPrimes(unsigned long long upperBound){
		bool v[upperBound+1];
		memset(v, true, upperBound+1);
		for(unsigned long long i = 2; i*i <= upperBound; i++){
			if(v[i] == true){
				for(unsigned long long j = i*i; j <= upperBound; j+=i){
					v[j] = false;
				}
			}
		}
		vector<unsigned long long> primes = {};
		for(unsigned long long i = 2; i <= upperBound; i++){
			if(v[i] == true){
				primes.push_back(i);
			}
		}
		return primes;
	}
}
