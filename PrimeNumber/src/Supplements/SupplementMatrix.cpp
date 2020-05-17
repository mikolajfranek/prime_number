#include "SupplementMatrix.h"


vector<vector<float>> SupplementMatrix::GetIdentityMatrix(int n){
	vector<vector<float>> result = {};
	int one = 0;
	for(int i = 0; i < n; i++){
		result.push_back(vector<float>(n, false));
		result[i][one++] = true;
	}
	return result;
}

void SupplementMatrix::PrintMatrix(vector<vector<float>> A){
	for(vector<float> x: A){
		for(float y : x){
			printf("%f ", y);
		}
		printf("\n");
	}
}

void SupplementMatrix::Gaussian_SolveMod2(vector<vector<float>> &A, vector<vector<float>> &b){

	//triangular
	float temp;
	int i0;
	for(int k = 0; k <= (A.size() - 2); k++){

		//search for non-zero value
		i0 = k;
		for(int i = k; i <= A.size() - 1; i++){
			if(A[i][k] != 0){
				i0 = i;
				break;
			}
		}

		//change row
		if(i0 != k){
			for(int j = 0; j < A.size(); j++){
				temp = A[k][j];
				A[k][j] = A[i0][j];
				A[i0][j] = temp;

				temp = b[k][j];
				b[k][j] = b[i0][j];
				b[i0][j] = temp;
			}
		}

		//calculate
		if(A[k][k] != 0){
			for(int i = k + 1; i < A.size(); i++){
				if(A[i][k] != 0){
					for(int j = 0; j < A.size(); j++){
						A[i][j] = (int)(A[i][j] + A[k][j]) % 2;
						b[i][j] = (int)(b[i][j] + b[k][j]) % 2;
					}
				}
			}
		}
	}



	//solve - reverse
	for(int k = (A.size() - 1); k >= 1; k--){
		if(A[k][k] != 0){
			for(int i = k - 1; i >= 0; i--){
				if(A[i][k] != 0){
					for(int j = 0; j < A.size(); j++){
						A[i][j] = (int)(A[i][j] + A[k][j]) % 2;
						b[i][j] = (int)(b[i][j] + b[k][j]) % 2;
					}
				}
			}
		}
	}
}

