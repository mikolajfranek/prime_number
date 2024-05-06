#include "../../../../_old/PrimeNumber/src/Elements/MyHelper.h"

namespace Elements {

	void MyHelper::PrintMatrix(vector<vector<bool>> matrix){
		for(vector<bool> row : matrix){
			for(bool element : row){
				printf("%d", element);
			}
			printf("\n");
		}
	}

	vector<vector<bool>> MyHelper::GetIdentityMatrix(long long size){
		vector<vector<bool>> r = {};
		for(long long i = 0; i < size; i++){
			vector<bool> row = vector<bool>(size, false);
			r.push_back(row);
			r[i][i] = true;
		}
		return r;
	}

	void MyHelper::FitIdentityMatrix(vector<vector<bool>> &MU, long long size){
		for(long long i = 0; i < MU.size(); i++){
			MU[i].resize(size);
		}
		for(long long i = MU.size(); i < size; i++){
			vector<bool> row = vector<bool>(size, false);
			MU.push_back(row);
			MU[i][i] = true;
		}
	}

	void MyHelper::PowCExpD(mpz_t r, mpz_t c, mpz_t d){
		mpz_t i;
		mpz_inits(i, NULL);
		mpz_set_ui(r, 1);
		for(mpz_set_ui(i, 0); mpz_cmp(i, d) < 0; mpz_add_ui(i, i, 1)){
			mpz_mul(r, r, c);
		}
		mpz_clears(i, NULL);
	}
}
