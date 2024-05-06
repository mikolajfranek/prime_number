#include "../../../../../_old/PrimeNumber/src/Algorithms/Solver/GaussianElimination.h"

namespace AlgorithmsSolver {
	void GaussianElimination::SolveMod2(vector<vector<bool>> &A, vector<vector<bool>> &B){
		bool temporary;
		unsigned long long idRowValueOne;
		for(unsigned long long col = 0; col < A[0].size(); col++){
			idRowValueOne = col;
			for(unsigned long long idRow = col; idRow < A.size(); idRow++){
				if(A[idRow][col] == true){
					idRowValueOne = idRow;
					break;
				}
			}
			if(idRowValueOne != col){
				for(unsigned long long j = 0; j < A[0].size(); j++){
					temporary = A[col][j];
					A[col][j] = A[idRowValueOne][j];
					A[idRowValueOne][j] = temporary;
				}
				for(unsigned long long j = 0; j < B[0].size(); j++){
					temporary = B[col][j];
					B[col][j] = B[idRowValueOne][j];
					B[idRowValueOne][j] = temporary;
				}
			}
			if(A[col][col] == true){
				for(unsigned long long idRow = col + 1; idRow < A.size(); idRow++){
					if(A[idRow][col] == true){
						for(unsigned long long j = 0; j < A[0].size(); j++){
							A[idRow][j] = A[idRow][j] ^ A[col][j];
						}
						for(unsigned long long j = 0; j < B[0].size(); j++){
							B[idRow][j] = B[idRow][j] ^ B[col][j];
						}
					}
				}
			}
		}
		for(unsigned long long col = (A[0].size() - 1); col > 0; col--){
			if(A[col][col] == true){
				for(int idRow = col - 1; idRow >= 0; idRow--){
					if(A[idRow][col] == true){
						for(unsigned long long j = 0; j < A[0].size(); j++){
							A[idRow][j] = A[idRow][j] ^ A[col][j];
						}
						for(unsigned long long j = 0; j < B[0].size(); j++){
							B[idRow][j] = B[idRow][j] ^ B[col][j];
						}
					}
				}
			}
		}
	}
}
