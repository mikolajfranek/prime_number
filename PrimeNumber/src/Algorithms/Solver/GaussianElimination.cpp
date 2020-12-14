#include "GaussianElimination.h"

namespace Solver {
	void GaussianElimination::SolveMod2(vector<vector<bool>> &A, vector<vector<bool>> &B){
		bool temp;
		unsigned long long nonZero;
		for(unsigned long long k = 0; k <= (A.size() - 2); k++){
			nonZero = k;
			for(unsigned long long i = k; i <= (A.size() - 1); i++){
				if(A[i][k] == true){
					nonZero = i;
					break;
				}
			}
			if(nonZero != k){
				for(unsigned long long i = 0; i <= (A.size() - 1); i++){
					temp = A[k][i];
					A[k][i] = A[nonZero][i];
					A[nonZero][i] = temp;
					temp = B[k][i];
					B[k][i] = B[nonZero][i];
					B[nonZero][i] = temp;
				}
			}
			if(A[k][k] == true){
				for(unsigned long long i = k + 1; i <= (A.size() - 1); i++){
					if(A[i][k] == true){
						for(unsigned long long j = 0; j < A.size(); j++){
							A[i][j] = A[i][j] ^ A[k][j];
							B[i][j] = B[i][j] ^ B[k][j];
						}
					}
				}
			}
		}
		for(unsigned long long k = (A[0].size() - 1); k >= 1; k--){
			if(A[k][k] == true){
				for(int i = k - 1; i >= 0; i--){
					if(A[i][k] == true){
						for(unsigned long long j = 0; j < A.size(); j++){
							A[i][j] = A[i][j] ^ A[k][j];
							B[i][j] = B[i][j] ^ B[k][j];
						}
					}
				}
			}
		}
	}
}
