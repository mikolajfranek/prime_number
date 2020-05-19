#include "QuadraticSieve.h"

void QuadraticSieve::Factor(string input){

	//declare
	mpz_t n, q, p, nmod, x, xrem, alpha, beta, gamma;

	//init
	mpz_inits(n, q, p, nmod, x, xrem, alpha, beta, gamma, NULL);

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

		//factor base
		factorBase = {2};
		for (unsigned long long prime : MyHelper::GetPrimesBelowN(b)){
			if(prime != 2){
				mpz_set_str(gamma, to_string(prime).c_str(), 10);
				if(mpz_legendre(n, gamma) == 1){
					factorBase.push_back(prime);
				}
			}
		}

		//init
		MyHelper::InitializeVector(&Y, y);
		MyHelper::InitializeVector(&V, y);
		for(unsigned long long i = 0; i < y; i++) {
			mpz_init2(Y[i], sizeof(mpz_t));
			mpz_init2(V[i], sizeof(mpz_t));

			//calculate Q(x)
			mpz_set_str(V[i], to_string(i).c_str(), 10);
			mpz_add(V[i], V[i], x);
			mpz_pow_ui(V[i], V[i], 2);
			mpz_sub(V[i], V[i], n);
			mpz_set(Y[i], V[i]);
		}

		//divide sieve for 2
		MyHelper::DivideSieve(V, y, 1, 2);

		//divide sieve for other
		for (unsigned long long prime : factorBase){
			if(prime != 2){
				mpz_set_str(gamma, to_string(prime).c_str(), 10);

				TonelliShanks::Solve(n, gamma, alpha, beta);

				mpz_sub(alpha, alpha, x);
				mpz_powm_ui(alpha, alpha, 1, gamma);
				MyHelper::DivideSieve(V, y, strtoull(mpz_get_str(NULL, 10, alpha), NULL, 10), prime);

				mpz_sub(beta, beta, x);
				mpz_powm_ui(beta, beta, 1, gamma);
				MyHelper::DivideSieve(V, y, strtoull(mpz_get_str(NULL, 10, beta), NULL, 10), prime);
			}
		}

//------------------------ WHILE END ------------------------














		int sqrtOfN = mpz_get_ui(x);

		//calculate factor array
		vector<int> h = {};

		long right = 1;
		long rightSide = 1;


		vector<vector<bool>> factors = {};

		for(unsigned long long i = 0; i < y; i++){


			if(mpz_cmp_ui(V[i], 1) == 0){

				int xx = i+sqrtOfN;

				rightSide *= xx*xx;
				right *= xx;

				h.push_back(mpz_get_ui(Y[i]));


				vector<bool> fac = {};
				for(int j = 0; j < (int)factorBase.size(); j++){
					fac.push_back(mpz_get_ui(Y[i]) % factorBase[j] == 0);
				}
				factors.push_back(fac);
			}
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
							mpz_set_ui(gamma, tem);

							mpz_gcd(p, n, gamma);

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



		//clear
		for(unsigned long long i=0;i<y;i++){
			mpz_clear(Y[i]);
			mpz_clear(V[i]);
		}
		free(Y);
		free(V);
	}

	//clear
	mpz_clears(n, q, p, nmod, x, xrem, alpha, beta, gamma, NULL);
}
