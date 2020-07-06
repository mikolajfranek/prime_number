#include "TrialDivision.h"

namespace Primality {
	void TrialDivision::IsPrime(string n, bool prediction){
		mpz_t r;
		mpz_inits(r, NULL);
		mpz_set_str(r, n.c_str(), 10);
		if(TrialDivision::IsPrime(r) != prediction){
			printf("Error: TrialDivision::IsPrime\n");
		}
		mpz_clears(r, NULL);
	}

	bool TrialDivision::IsPrime(mpz_t n){
		//TODO
		return false;
	}
}
