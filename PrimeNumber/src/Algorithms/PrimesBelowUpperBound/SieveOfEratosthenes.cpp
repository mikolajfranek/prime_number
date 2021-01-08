#include "SieveOfEratosthenes.h"

namespace PrimesBelowUpperBound {

	SieveOfEratosthenes::SieveOfEratosthenes() {}

	SieveOfEratosthenes::~SieveOfEratosthenes() {}

	vector<unsigned long long>* SieveOfEratosthenes::GetPrimes(unsigned long long upperBound){
		vector<bool> v(upperBound+1, true);
		for(unsigned long long i = 2; i*i <= upperBound; i++){
			if(v[i] == true){
				for(unsigned long long j = i*i; j <= upperBound; j+=i){
					v[j] = false;
				}
			}
		}
		vector<unsigned long long>* primes = new vector<unsigned long long>();
		for(unsigned long long i = 2; i <= upperBound; i++){
			if(v[i] == true){
				primes->push_back(i);
			}
		}
		return primes;
	}
}
