#include "QuadraticSieve.h"

void QuadraticSieve::Factor(string input){

	//declare
	mpz_t n, q, p, nmod, x, xrem, temp;

	//init
	mpz_inits(n, q, p, nmod, x, xrem, temp, NULL);

	//set
	mpz_set_str(n, input.c_str(), 10);

	//start algorithm
	mpz_mod_ui(nmod, n, 2);
	if(mpz_cmp_ui(nmod, 0) == 0){
		mpz_div_ui(q, n, 2);
		mpz_set_ui(p, 2);
	}else{

		unsigned long long b = 0;
		unsigned long long y = 0;

		mpz_sqrtrem(x, xrem, n);
		if(mpz_cmp_ui(xrem, 0) != 0){
			mpz_add_ui(x, x, 1);
		}

		mpz_t *Y;
		mpz_t *V;

		vector<unsigned long long> factorBase = {};


//------------------------ WHILE BEGIN ------------------------

		//update
		b += 30;
		y += 100;

		//init
		MyHelper::InitializeVector(&Y, y);
		for(unsigned long long i = 0; i < y; i++) mpz_init2(Y[i], sizeof(mpz_t));
		MyHelper::InitializeVector(&V, y);
		for(unsigned long long i = 0; i < y; i++) mpz_init2(V[i], sizeof(mpz_t));

		//calculate Q(x)
		for(unsigned long long i = 0; i < y; i++){
			 mpz_set_ui(V[i], i);
			 mpz_add(V[i], V[i], x);
			 mpz_pow_ui(V[i], V[i], 2);
			 mpz_sub(V[i], V[i], n);
			 mpz_set(Y[i], V[i]);
		}

		//factor base
		factorBase = {2};
		for (unsigned long long prime : MyHelper::GetPrimesBelowN(b)){
			if(prime != 2){
				mpz_set_ui(temp, prime);
				if(mpz_legendre(n, temp) == 1){
					factorBase.push_back(prime);
				}
			}
		}

		//divide sieve for 2
		MyHelper::DivideSieve(V, y, 1, 2);


//------------------------ WHILE END ------------------------













		//divide sieve for other
		int sqrtOfN = mpz_get_ui(x), result_1, result_2;

		for (int prime : factorBase){
			if(prime != 2){

				mpz_set_ui(temp, prime);
				TonelliShanks::Solve(n, temp);

				result_1 = mpz_get_ui(temp);
				result_2 = prime - result_1;

				//solve congruent
				result_1 = (result_1 - sqrtOfN) % prime;
				result_1 = result_1 < 0 ? result_1 + prime : result_1;
				MyHelper::DivideSieve(V, y, result_1, prime);

				//solve congruent
				result_2 = (result_2 - sqrtOfN) % prime;
				result_2 = result_2 < 0 ? result_2 + prime : result_2;
				MyHelper::DivideSieve(V, y, result_2, prime);

			}
		}













		//calculate factor array
		vector<int> x = {};
		vector<int> h = {};
		for(int i = 0; i < y; i++){
			if((long)mpz_get_ui(V[i]) == 1){
				x.push_back(i+sqrtOfN);
				h.push_back(mpz_get_ui(Y[i]));
			}
		}
		vector<vector<bool>> factors = {};
		for(int i = 0; i < (int)h.size(); i++){
			vector<bool> fac = {};
			for(int j = 0; j < (int)factorBase.size(); j++){
				fac.push_back(h[i] % factorBase[j] == 0);
			}
			factors.push_back(fac);
		}

		//calculate right side of equation
		long right = 1;
		long rightSide = 1;
		for(int i = 0; i < (int)x.size(); i++){
			rightSide *= x[i]*x[i];
			right *= x[i];
		}
		rightSide = rightSide % mpz_get_ui(n);
		printf("Right side is %d\n\n", rightSide);









		//29 - 782 - 22678
		int w = (int)h.size();

		//2 - 17 - 23 - 29
		int k = (int)factorBase.size();


		if(w > k){
			//row
			for(vector<int> v : MyHelper::GetCombination(w, k)){

				vector<vector<float>> matrix = {};
				for(int i = 0; i < k; i++){
					matrix.push_back(vector<float>(k, 0));
				}

				vector<int> kk = vector<int>(k, 0);
				int u = 0;
				for(int j : v){
					kk[u] = h[j];
					for(int t = 0; t < w; t++){
						matrix[u][t] = factors[j][t];
					}
					u++;
				}

				//solve matrix
			}

		}else if(w < k){
			//column
			for(vector<int> v : MyHelper::GetCombination(k, w)){

				vector<vector<float>> matrix = {};
				for(int i = 0; i < w; i++){
					matrix.push_back(vector<float>(w, 0));
				}

				vector<int> kk = h;
				int u = 0;
				for(int j : v){
					for(int t = 0; t < w; t++){
						matrix[t][u] = factors[t][j];
					}
					u++;
				}

				vector<vector<float>> identity = MyHelper::GetIdentityMatrix(matrix.size());
				MyHelper::Gaussian_SolveMod2(matrix, identity);
				bool found = false;


				for(unsigned int i = 0; i < matrix.size(); i++){
					bool rowZero = true;
					for(unsigned int j = 0; j < matrix.size(); j++){
						if(matrix[i][j] == 1){
							rowZero = false;
							break;
						}
					}

					if(rowZero){
						int leftSide = 1;
						int left = 1;
						long tem = 0;
						for(unsigned int j = 0; j < identity.size(); j++){
							tem = ((int)identity[i][j] * kk[j]);
							leftSide *= (tem ? tem : 1);
							left *= (tem ? tem : 1);
						}
						leftSide = leftSide % mpz_get_ui(n);




						if(leftSide == rightSide){
							tem = right - sqrt(left);
							mpz_set_ui(temp, tem);

							mpz_gcd(p, n, temp);

							printf("Result is %d\n\n", (int)mpz_get_ui(p));

							//if not 1 then q is
							//RESULT OK
						}
					}
				}

				if(found) break;
			}

		}else{
			vector<int> kk = h;

			//solve matrix
		}

		return;



		//clear
		for(int i=0;i<y;i++) mpz_clear(Y[i]);
		for(int i=0;i<y;i++) mpz_clear(V[i]);
		free(Y);
		free(V);
	}

	//clear
	mpz_clears(n, q, p, nmod, x, xrem, temp, NULL);
	printf("This is end of program\n");
	return;
}
