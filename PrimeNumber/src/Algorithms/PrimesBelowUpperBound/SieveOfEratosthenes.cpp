#include "SieveOfEratosthenes.h"

namespace PrimesBelowUpperBound {

	SieveOfEratosthenes::SieveOfEratosthenes() {}

	SieveOfEratosthenes::~SieveOfEratosthenes() {}

	vector<long long> SieveOfEratosthenes::SearchPrimes(long long upperBound){
		vector<bool> v(upperBound+1, true);
		for(long long i = 2; i*i <= upperBound; i++){
			if(v[i] == true){
				for(long long j = i*i; j <= upperBound; j+=i){
					v[j] = false;
				}
			}
		}
		vector<long long> primes = {};
		for(long long i = 2; i <= upperBound; i++){
			if(v[i] == true){
				primes.push_back(i);
			}
		}
		return primes;
	}
}
