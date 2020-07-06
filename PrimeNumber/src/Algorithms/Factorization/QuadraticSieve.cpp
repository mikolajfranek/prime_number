#include "QuadraticSieve.h"

namespace Factorization {
	void QuadraticSieve::Factor(string input){

		//declare
		mpz_t n, q, p, nmod, x, xrem,
				i, right, rightMod, left, leftMod, alpha, beta, gamma;

		//init
		mpz_inits(n, q, p, nmod, x, xrem,
				i, right, rightMod, left, leftMod, alpha, beta, gamma, NULL);

		//set
		mpz_set_str(n, input.c_str(), 10);

		//start algorithm
		mpz_mod_ui(nmod, n, 2);
		if(mpz_cmp_ui(nmod, 0) == 0){
			mpz_div_ui(q, n, 2);
			mpz_set_ui(p, 2);
		}else{
			if(Primality::TrialDivision::IsPrime(n) == true){
				mpz_set(q, n);
				mpz_set_ui(p, 1);
			}else{
				bool isPowerOfPrime = false;
				unsigned long int k = 2;
				do{
					mpz_rootrem(x, xrem, n, k);
					if(mpz_cmp_ui(xrem, 0) == 0){
						mpz_div(q, n, x);
						mpz_set(p, x);
						isPowerOfPrime = true;
						break;
					}
					k = k + 1;
				}while(mpz_cmp_ui(x, 1) > 0);
				if(isPowerOfPrime == false){
					//TODO


				}
			}


			return;
















			unsigned long long b = 0;
			unsigned long long y = 0;

			mpz_sqrtrem(x, xrem, n);
			if(mpz_cmp_ui(xrem, 0) != 0){
				mpz_add_ui(x, x, 1);
			}

			mpz_t *Y;
			mpz_t *V;

			vector<unsigned long long> factorBase = {};

			bool isFound = false;


			while(true){



				//update
				b += 100;
				y += 160;

				printf("Value of b = %d\n", b);

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
				MyHelper::MallocVector(&Y, y);
				MyHelper::MallocVector(&V, y);
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

				//calculate factors
				unsigned long long sizeRow = 0;
				unsigned long long sizeCol = factorBase.size();

				mpz_t *L;
				mpz_t *R;
				MyHelper::MallocVector(&L, sizeRow);
				MyHelper::MallocVector(&R, sizeRow);

				vector<vector<bool>> factors = {};
				for(unsigned long long i = 0; i < y; i++){
					if(mpz_cmp_ui(V[i], 1) == 0){

						//R
						mpz_set_str(alpha, to_string(i).c_str(), 10);
						mpz_add(alpha, alpha, x);
						mpz_pow_ui(beta, alpha, 2);
						MyHelper::ReallocVector(&R, sizeRow + 1);
						mpz_init2(R[sizeRow], sizeof(mpz_t));
						mpz_set(R[sizeRow], beta);

						//L
						MyHelper::ReallocVector(&L, sizeRow + 1);
						mpz_init2(L[sizeRow], sizeof(mpz_t));
						mpz_set(L[sizeRow], Y[i]);

						sizeRow += 1;

						vector<bool> factor = {};
						for(unsigned long long j = 0; j < factorBase.size(); j++){
							mpz_mod_ui(gamma, Y[i], factorBase[j]);
							factor.push_back(mpz_cmp_ui(gamma, 0) == 0);
						}
						factors.push_back(factor);
					}
				}


				printf("Value of size row = %d\n", sizeRow);
				printf("Value of size col = %d\n", sizeCol);

				//calculate matrix
				unsigned long long cn = 0;
				unsigned long long ck = 0;

				enum DIMENSION { EQUAL, ROW, COLUMN};
				DIMENSION dimension;

				if(sizeRow > sizeCol){
					cn = sizeRow;
					ck = sizeCol;
					dimension = ROW;
				}else if(sizeRow < sizeCol){
					cn = sizeCol;
					ck = sizeRow;
					dimension = COLUMN;
				}else{
					cn = ck = sizeCol = sizeRow;
					dimension = EQUAL;
				}

				for(vector<unsigned long long> c : MyHelper::GetCombination(cn, ck)){
					//create matrix
					vector<vector<bool>> A = {};
					vector<vector<bool>> B = MyHelper::GetIdentityMatrix(ck);
					vector<unsigned long long> index = {};
					if(dimension == EQUAL){
						A = factors;
					}else{
						for(unsigned long long i = 0; i < ck; i++){
							A.push_back(vector<bool>(ck, false));
						}
						//fill matrix
						unsigned long long u = 0;
						for(unsigned long long j : c){
							if(dimension == COLUMN){
								index.push_back(u);
								for(unsigned long long t = 0; t < ck; t++){
									A[t][u] = factors[t][j];
								}
							}else if (dimension == ROW){
								index.push_back(j);
								for(unsigned long long t = 0; t < ck; t++){
									A[u][t] = factors[j][t];
								}
							}
							u++;
						}
					}

					//solve
					GaussianElimination::SolveMod2(A, B);

					//search for row of zeros
					bool isRowZero = true;
					for(unsigned long long i = 0; i < ck; i++){
						isRowZero = true;
						for(unsigned long long j = 0; j < ck; j++){
							if(A[i][j]){
								isRowZero = false;
								break;
							}
						}
						//found zero row
						if(isRowZero){

							//calculate left and right side
							mpz_set_ui(left, 1);
							mpz_set_ui(right, 1);
							for(unsigned long long j = 0; j < ck; j++){
								//left
								mpz_mul_ui(gamma, L[index[j]], B[i][j]);
								if(mpz_cmp_ui(gamma, 0) != 0){
									mpz_mul(left, left, gamma);
								}

								//right
								mpz_mul_ui(gamma, R[index[j]], B[i][j]);
								if(mpz_cmp_ui(gamma, 0) != 0){
									mpz_mul(right, right, gamma);
								}
							}
							mpz_mod(leftMod, left, n);
							mpz_mod(rightMod, right, n);


							//check if are equal
							if(mpz_cmp(leftMod, rightMod) == 0){
								mpz_sqrt(alpha, left);
								mpz_sqrt(beta, right);

								mpz_sub(gamma, beta, alpha);
								mpz_gcd(p, n, gamma);

								if(mpz_cmp_ui(p, 1) != 0){
									isFound = true;
									mpz_div(q, n, p);
								}
							}
						}
						if(isFound) break;
					}
					if(isFound) break;
				}

				//clear
				for(unsigned long long i = 0; i < sizeRow; i++){
					mpz_clear(L[i]);
				}
				free(L);
				for(unsigned long long i = 0; i < y; i++){
					mpz_clear(Y[i]);
					mpz_clear(V[i]);
				}
				free(Y);
				free(V);
				if(isFound) break;
			}

			//check
			MyHelper::CheckResult(n, q, p);
		}

		//clear
		mpz_clears(n, q, p, nmod, x, xrem,
				i, right, rightMod, left, leftMod, alpha, beta, gamma, NULL);
	}
}
