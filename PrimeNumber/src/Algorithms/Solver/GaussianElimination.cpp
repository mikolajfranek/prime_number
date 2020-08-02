#include "GaussianElimination.h"

namespace Solver {
	void GaussianElimination::SolveMod2(vector<vector<bool>> &A, vector<vector<bool>> &B){
		bool t;
		unsigned long long c;
		for(unsigned long long k = 0; k <= (A.size() - 2); k++){
			//search for non-zero value
			c = k;
			for(unsigned long long i = k; i <= (A.size() - 1); i++){
				if(A[i][k]){
					c = i;
					break;
				}
			}
			//change row
			if(c != k){
				for(unsigned long long j = 0; j <= (A.size() - 1); j++){
					t = A[k][j];
					A[k][j] = A[c][j];
					A[c][j] = t;

					t = B[k][j];
					B[k][j] = B[c][j];
					B[c][j] = t;
				}
			}
			//calculate
			if(A[k][k]){
				for(unsigned long long i = k + 1; i <= (A.size() - 1); i++){
					if(A[i][k]){
						for(unsigned long long j = 0; j < A.size(); j++){
							A[i][j] = A[i][j] ^ A[k][j];
							B[i][j] = B[i][j] ^ B[k][j];
						}
					}
				}
			}
		}


		return;
		for(int k = (A.size() - 1); k >= 1; k--){
			//calculate
			if(A[k][k]){
				for(int i = k - 1; i >= 0; i--){
					if(A[i][k]){
						for(unsigned j = 0; j < A.size(); j++){
							A[i][j] = A[i][j] ^ A[k][j];
							B[i][j] = B[i][j] ^ B[k][j];
						}
					}
				}
			}
		}
	}
}
