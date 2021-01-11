#include "GaussianElimination.h"

namespace AlgorithmsSolver {
	void GaussianElimination::SolveMod2(vector<vector<bool>> &A, vector<vector<bool>> &B){
		bool temp;
		unsigned long long nonZero;
		for(unsigned long long k = 0; k < A.size(); k++){
			nonZero = k;
			for(unsigned long long i = k; i < A.size(); i++){
				if(A[i][k] == true){
					nonZero = i;
					break;
				}
			}
			if(nonZero != k){
				for(unsigned long long j = 0; j < A[0].size(); j++){
					temp = A[k][j];
					A[k][j] = A[nonZero][j];
					A[nonZero][j] = temp;
				}
				for(unsigned long long j = 0; j < B[0].size(); j++){
					temp = B[k][j];
					B[k][j] = B[nonZero][j];
					B[nonZero][j] = temp;
				}
			}
			if(A[k][k] == true){
				for(unsigned long long i = k + 1; i < A.size(); i++){
					if(A[i][k] == true){
						for(unsigned long long j = 0; j < A[0].size(); j++){
							A[i][j] = A[i][j] ^ A[k][j];
						}
						for(unsigned long long j = 0; j < B[0].size(); j++){
							B[i][j] = B[i][j] ^ B[k][j];
						}
					}
				}
			}
		}
		for(unsigned long long k = (A[0].size() - 1); k > 0; k--){
			if(A[k][k] == true){
				for(int i = k - 1; i >= 0; i--){
					if(A[i][k] == true){
						for(unsigned long long j = 0; j < A[0].size(); j++){
							A[i][j] = A[i][j] ^ A[k][j];
						}
						for(unsigned long long j = 0; j < B[0].size(); j++){
							B[i][j] = B[i][j] ^ B[k][j];
						}
					}
				}
			}
		}
	}
}
