#include "SieveOfEratosthenes.h"

namespace PrimesBelowLimit {
vector<unsigned long long> SieveOfEratosthenes::GetPrimes(unsigned long long limit){
		bool v[limit+1];
		memset(v, true, sizeof(v));
		for(unsigned long long i = 2; i*i <= limit; i++){
			if(v[i] == true){
				for(unsigned long long j = i*i; j <= limit; j += i){
					v[j] = false;
				}
			}
		}
		vector<unsigned long long>  primes = {};
		for(unsigned long long i = 2; i <= limit; i++){
			if(v[i] == true){
				primes.push_back(i);
			}
		}
		return primes;
	}
}
