#include "QuadraticSieve.h"

vector<int> QuadraticSieve::GetPrimeListBelowN(int n){
	vector<int> primes = {};
	bool arr[n+1];
	memset(arr, true, sizeof(arr));
	int nsqrt = sqrt(n);
	for(int i = 2; i <= nsqrt; i++){
		if(arr[i]){
			for(int j = i*i; j <= n; j += i){
				arr[j] = false;
			}
		}
	}
	for(int i = 2; i < n; i++){
		if(arr[i]){
			primes.push_back(i);
		}
	}
	return primes;
}

void QuadraticSieve::PowCExpD(mpz_t r, mpz_t c, mpz_t d){
	mpz_t i;
	mpz_inits(i, NULL);
	mpz_set_ui(r, 1);
	for(mpz_set_ui(i, 0); mpz_cmp(i, d) < 0; mpz_add_ui(i, i, 1)){
		mpz_mul(r, r, c);
	}
	mpz_clears(i, NULL);
}

void QuadraticSieve::DivideSieve(mpz_t *sieve, int sizeOfSieve, int from, int step){
	for(int i = from; i < sizeOfSieve; i += step){
		mpz_div_ui(sieve[i], sieve[i], step);
	}
}

void QuadraticSieve::Tonelli_Shanks(mpz_t n, mpz_t p){

	mpz_t s, e, f, t, x, g, b, r, m, c, d, temp;
	mpz_inits(s, e, f, t, x, g, b, r, m, c, d, temp, NULL);

	//p-1 = s*2^(e)
	mpz_set_ui(e, 0);
	mpz_sub_ui(s, p, 1);
	mpz_mod_ui(temp, s, 2);
	while(mpz_cmp_ui(temp, 0) == 0){
		mpz_div_ui(s, s, 2);
		mpz_add_ui(e, e, 1);
		mpz_mod_ui(temp, s, 2);
	}

	//find non-residue
	mpz_set_ui(t, 3);
	while(mpz_legendre(t, p) != -1){
		mpz_add_ui(t, t, 1);
	}

	//initizalize
	mpz_powm_ui(r, e, 1, p);
	mpz_powm(g, t, s, p);
	mpz_powm(b, n, s, p);
	mpz_set(temp, s);
	mpz_add_ui(temp, temp, 1);
	mpz_div_ui(temp, temp, 2);
	mpz_powm(x, n, temp, p);

	while(true){
		//search m
		mpz_set_ui(m, 0);
		while(true){
			mpz_set_ui(c, 2);
			PowCExpD(temp, c, m);
			mpz_powm(f, b, temp, p);
			if(mpz_cmp_ui(f, 1) == 0) break;
			mpz_add_ui(m, m, 1);
		}

		//check
		if(mpz_cmp_ui(m, 0) == 0){
			mpz_set(p, x);
			break;
		}

		//update
		//r-m-1
		mpz_set(d, r);
		mpz_sub(d, d, m);
		mpz_sub_ui(d, d, 1);
		//2^(r-m-1)
		mpz_set_ui(c, 2);
		PowCExpD(temp, c, d);
		//g^(2^(r-m-1))
		mpz_set(c, g);
		mpz_set(d, temp);
		PowCExpD(temp, c, d);
		//x * g^(2^(r-m-1))
		mpz_mul(x, x, temp);
		mpz_powm_ui(x, x, 1, p);

		//r-m
		mpz_set(d, r);
		mpz_sub(d, d, m);
		//2^(r-m)
		mpz_set_ui(c, 2);
		PowCExpD(temp, c, d);
		//g^(2^(r-m))
		mpz_set(c, g);
		mpz_set(d, temp);
		PowCExpD(temp, c, d);
		//b * g^(2^(r-m))
		mpz_mul(b, b, temp);
		mpz_powm_ui(b, b, 1, p);

		//r-m
		mpz_set(d, r);
		mpz_sub(d, d, m);
		//2^(r-m)
		mpz_set_ui(c, 2);
		PowCExpD(temp, c, d);
		//g^(2^(r-m))
		mpz_set(c, g);
		mpz_set(d, temp);
		PowCExpD(g, c, d);
		mpz_powm_ui(g, g, 1, p);

		mpz_set(r, m);
		mpz_powm_ui(r, r, 1, p);
	}

	mpz_clears(s, e, f, t, x, g, b, r, m, c, d, temp, NULL);
}

void QuadraticSieve::Factor(string input){

	//declare
	mpz_t n, q, p, nmod, nsqrt, nsqrtrem, temp;

	//init
	mpz_inits(n, q, p, nmod, nsqrt, nsqrtrem, temp, NULL);

	//set
	mpz_set_str(n, input.c_str(), 10);

	//start algorithm
	mpz_mod_ui(nmod, n, 2);
	if(mpz_cmp_ui(nmod, 0) == 0){
		mpz_div_ui(q, n, 2);
		mpz_set_ui(p, 2);
	}else{
		mpz_sqrtrem(nsqrt, nsqrtrem, n);
		if(mpz_cmp_ui(nsqrtrem, 0) != 0){
			mpz_add_ui(nsqrt, nsqrt, 1);
		}

		int b = 30;
		int m = 100;

		//quadratic residue
		vector<int> primes = GetPrimeListBelowN(b);
		vector<int> quadraticResidue = {2};
		for (int prime : primes){
			if(prime == 2) continue;
			mpz_set_ui(temp, prime);
			if(mpz_legendre(n, temp) == 1){
				quadraticResidue.push_back(prime);
			}
		}

		//define
		mpz_t *Y;
		mpz_t *V;
		Y = (mpz_t *)malloc(m * sizeof(mpz_t));
		if(Y == NULL){
			printf("ERROR: Out of memory\n");
			return;
		}
		V = (mpz_t *)malloc(m * sizeof(mpz_t));
		if(V == NULL){
			printf("ERROR: Out of memory\n");
			return;
		}
		for(int i=0;i<m;i++) mpz_init2(Y[i], sizeof(mpz_t));
		for(int i=0;i<m;i++) mpz_init2(V[i], sizeof(mpz_t));

		//calculate Q(x)
		for(int i = 0; i < m; i++){
			 mpz_set_ui(V[i], i);
			 mpz_add(V[i], V[i], nsqrt);
			 mpz_pow_ui(V[i], V[i], 2);
			 mpz_sub(V[i], V[i], n);
			 mpz_set(Y[i], V[i]);
		}

		//divide sieve for '2' which is quadratic residue
		DivideSieve(V, m, 1, 2);

		//divide sieve for other
		int sqrt = mpz_get_ui(nsqrt), result_1, result_2;
		for (int residue : quadraticResidue){
			if(residue == 2) continue;

			mpz_set_ui(temp, residue);
			Tonelli_Shanks(n, temp);

			result_1 = mpz_get_ui(temp);
			result_2 = residue - result_1;

			//solve congruent
			result_1 = (result_1 - sqrt) % residue;
			result_1 = result_1 < 0 ? result_1 + residue : result_1;
			DivideSieve(V, m, result_1, residue);

			//solve congruent
			result_2 = (result_2 - sqrt) % residue;
			result_2 = result_2 < 0 ? result_2 + residue : result_2;
			DivideSieve(V, m, result_2, residue);
		}

		//calculate factor array
		vector<int> x = {};
		vector<int> h = {};
		for(int i = 0; i < m; i++){
			if((long)mpz_get_ui(V[i]) ==1){
				x.push_back(i+sqrt);
				h.push_back(mpz_get_ui(Y[i]));
			}
		}
		vector<vector<bool>> factors = {};
		for(int i = 0; i < (int)h.size(); i++){
			vector<bool> fac = {};
			for(int j = 0; j < (int)quadraticResidue.size(); j++){
				fac.push_back(h[i] % quadraticResidue[j] == 0);
			}
			factors.push_back(fac);
		}

		//calculate right side of equation
		long rightSide = 1;
		for(int i = 0; i < (int)x.size(); i++){
			rightSide *= x[i]*x[i];
		}
		rightSide = rightSide % mpz_get_ui(n);





		/*
		 * TODO
		 * find resources about algorithm gaussian elimination
		 * implement and test simple
		 * refactor to mpz_t
		 *
		 */

		printf("Right side is %d\n\n", rightSide);


		//matrix
		vector<vector<float>> matrix = {{0,0,1},
									    {1,1,0},
									    {1,1,1}};

		//pivot
		vector<int> pivot(matrix.size());
		iota(pivot.begin(), pivot.end(), 0);

		//init variables
		int det;
		bool err;

		//calculate triangular
		Gaussian_Triangular(matrix, pivot, det, err);
		if(err == true || det == 0){
			//do something
			printf("Wyznacznik jest równy zero\n");
		}


		//TODO

		//solve
		vector<vector<float>> identity = GetIdentityMatrix(matrix.size());
		//vector<float> b_temp(matrix.size());
		//b_temp[0] = 0;
		//b_temp[1] = 0;
		//b_temp[2] = 0;

		Gaussian_SolveMod2(matrix, pivot, identity);

		PrintMatrix(matrix);
		printf("\n");
		PrintMatrix(identity);
		printf("\n");

		for(int i = 0; i < pivot.size(); i++){
			printf("i = %d\tv = %d\n", i, pivot[i]);
		}

		//for(int i = 0; i < b_temp.size(); i++){
			//printf("nr = %d\tv = %f\n", pivot[i], b_temp[i]);
		//}




		//clear
		for(int i=0;i<m;i++) mpz_clear(Y[i]);
		for(int i=0;i<m;i++) mpz_clear(V[i]);
		free(Y);
		free(V);
	}

	//clear
	mpz_clears(n, q, p, nmod, nsqrt, nsqrtrem, temp, NULL);
	printf("This is end of program\n");
	return;
}


vector<vector<float>>QuadraticSieve::GetIdentityMatrix(int n){
	vector<vector<float>> result = {};
	int one = 0;
	for(int i = 0; i < n; i++){
		result.push_back(vector<float>(n, false));
		result[i][one++] = true;
	}
	return result;
}

void QuadraticSieve::PrintMatrix(vector<vector<float>> A){
	for(vector<float> x: A){
		for(float y : x){
			printf("%f ", y);
		}
		printf("\n");
	}
}

void QuadraticSieve::Gaussian_Triangular(vector<vector<float>> &A, vector<int> &pivot, int &det, bool &err){
	det = 1;
	err = false;

	vector<float> s(A.size(), 0);
	for(int i = 0; i < A.size(); i++){
		for(int j = 0; j < A.size(); j++){
			s[i] = abs(A[i][j]) > s[i] ? abs(A[i][j]) : s[i];
		}
	}

	float ck, temp;
	int i0;
	for(int k = 0; k < (A.size() - 1); k++){

		ck = 0;
		i0 = k;
		for(int i = k; i < A.size(); i++){
			if(abs(A[i][k] / s[i]) > ck){
				ck = abs(A[i][k] / s[i]);
				i0 = i;
			}
		}

		pivot[k] = i0;

		if(ck == 0){
			err = true;
			det = 0;
			return;
		}

		if(i0 != k){
			det = -1 * abs(det);
			for(int j = k; j < A.size(); j++){
				temp = A[k][j];
				A[k][j] = A[i0][j];
				A[i0][j] = temp;
			}
			temp = s[k];
			s[k] = s[i0];
			s[i0] = temp;
		}


		for(int i = k + 1; i < A.size(); i++){
			A[i][k] = temp = A[i][k] / A[k][k];
			for(int j = k + 1; j < A.size(); j++){
				A[i][j] = A[i][j] - (temp * A[k][j]);
			}
		}

		det = det * A[k][k];
	}

	det = det * A[A.size() - 1][A.size() - 1];
}

void QuadraticSieve::Gaussian_Solve(vector<vector<float>> &A, vector<int> &pivot, vector<float> &b){
	float temp;
	for(int k = 0; k < (A.size() - 1); k++){
		if(pivot[k] != k){
			temp = b[pivot[k]];
			b[pivot[k]] = b[k];
			b[k] = temp;
		}

		for(int i = k + 1; i < A.size(); i++){
			b[i] = b[i] - (A[i][k] * b[k]);
		}
	}

	b[A.size()-1] = b[A.size()-1] / A[A.size()-1][A.size()-1];

	for(int i = A.size()-2; i >= 0; i--){
		temp = 0;
		for(int j = i + 1; j < A.size(); j++){
			temp = temp + (A[i][j] * b[j]);
		}
		b[i] = (1 / A[i][i]) * (b[i] - temp);
	}
}



void QuadraticSieve::Gaussian_SolveMod2(vector<vector<float>> &A, vector<int> &pivot, vector<vector<float>> &b){
	/*
	float temp;
	for(int k = 0; k < (A.size() - 1); k++){
		if(pivot[k] != k){
			temp = b[pivot[k]];
			b[pivot[k]] = b[k];
			b[k] = temp;
		}

		for(int i = k + 1; i < A.size(); i++){
			b[i] = b[i] - (A[i][k] * b[k]);
		}
	}

	b[A.size()-1] = b[A.size()-1] / A[A.size()-1][A.size()-1];

	for(int i = A.size()-2; i >= 0; i--){
		temp = 0;
		for(int j = i + 1; j < A.size(); j++){
			temp = temp + (A[i][j] * b[j]);
		}
		b[i] = (1 / A[i][i]) * (b[i] - temp);
	}
	*/
}

//may be use?
bool QuadraticSieve::InputHasFormPowPToM(mpz_t n){

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
