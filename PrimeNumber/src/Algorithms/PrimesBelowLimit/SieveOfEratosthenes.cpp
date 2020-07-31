#include "SieveOfEratosthenes.h"

namespace PrimesBelowLimit {
	vector<unsigned long long> *SieveOfEratosthenes::GetPrimes(unsigned long long limit){
		bool* v = new bool[limit+1];
		memset(v, true, limit+1);
		for(unsigned long long i = 2; i*i <= limit; i++){
			if(v[i] == true){
				for(unsigned long long j = i*i; j <= limit; j+=i){
					v[j] = false;
				}
			}
		}
		vector<unsigned long long> *primes = new vector<unsigned long long>();
		for(unsigned long long i = 2; i <= limit; i++){
			if(v[i] == true){
				primes->push_back(i);
			}
		}
		delete[] v;
		return primes;
	}
}
