#include "SupplementHelper.h"

void SupplementHelper::CheckResult(mpz_t n, mpz_t q, mpz_t p){
	mpz_t q_mul_p;
	mpz_inits(q_mul_p, NULL);
	mpz_mul(q_mul_p, q, p);
	if(mpz_cmp(n, q_mul_p) == 0){
		gmp_printf("OK: %Zd = %Zd * %Zd\n", n, q, p);
	}else{
		gmp_printf("ERROR: %Zd = %Zd * %Zd\n", n, q, p);
	}
	mpz_clears(q_mul_p, NULL);
}

void SupplementHelper::PowCExpD(mpz_t r, mpz_t c, mpz_t d){
	mpz_t i;
	mpz_inits(i, NULL);
	mpz_set_ui(r, 1);
	for(mpz_set_ui(i, 0); mpz_cmp(i, d) < 0; mpz_add_ui(i, i, 1)){
		mpz_mul(r, r, c);
	}
	mpz_clears(i, NULL);
}

void SupplementHelper::DivideSieve(mpz_t *sieve, int sizeOfSieve, int from, int step){
	for(int i = from; i < sizeOfSieve; i += step){
		mpz_div_ui(sieve[i], sieve[i], step);
	}
}

vector<vector<int>> SupplementHelper::GetCombination(int n, int k){
	vector<vector<int>> result = {};
	string bitmask(k, 1);
    bitmask.resize(n, 0);

    do {
    	vector<int> v = {};
        for (int i = 0; i < n; ++i)
        {
            if (bitmask[i]) {
            	v.push_back(i);
            }
        }
        result.push_back(v);
    } while (prev_permutation(bitmask.begin(), bitmask.end()));
    return result;
}

//may be use?
bool SupplementHelper::InputHasFormPowPToM(mpz_t n){

	bool result = false;

	//declare
	mpz_t root, rem;

	//init
	mpz_inits(root, rem, NULL);

	//start
	for(long m = 2; ;m++){
		mpz_rootrem(root, rem, n, m);
		if(mpz_cmp_ui(rem, 0) == 0){
			result = true;
			break;
		}else if(mpz_cmp_ui(root, 1) == 0){
			break;
		}
	}

	//clear
	mpz_clears(root, rem, NULL);

	return result;
}


