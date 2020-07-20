#include "QuadraticSieve.h"

namespace Factorization {
	void QuadraticSieve::Factor(string input){

		//declare
		mpz_t n, q, p, nmod, x, xrem,
				right, rightMod, left, leftMod, alpha, beta, gamma;

		//init
		mpz_inits(n, q, p, nmod, x, xrem,
				right, rightMod, left, leftMod, alpha, beta, gamma, NULL);

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



			unsigned long long b;


			//wartość optymalna
			b = 30;









			mpz_sqrtrem(x, xrem, n);
			if(mpz_cmp_ui(xrem, 0) != 0){
				mpz_add_ui(x, x, 1);
			}




			bool theEnd = false;












			unsigned long long cs = 0, cp = 0, cf, cb;
			mpz_t* W;
			mpz_t* V;
			Other::MyHelper::Malloc(&W, cs);
			Other::MyHelper::Malloc(&V, cs);
			vector<Elements::QuadraticResidue*> factorBase = {new Elements::QuadraticResidue(2, 1, 1)};
			mpz_t *L;
			mpz_t *R;
			Other::MyHelper::Malloc(&L, cp);
			Other::MyHelper::Malloc(&R, cp);
			do{
				vector<vector<bool>> matrix = {};
				vector<unsigned long long>* primes = PrimesBelowLimit::SieveOfEratosthenes::GetPrimes(b);
				for (unsigned long long prime : *primes){
					Elements::QuadraticResidue* residue = new Elements::QuadraticResidue();
					mpz_set_str(residue->Prime, to_string(prime).c_str(), 10);
					if(mpz_legendre(n, residue->Prime) == 1){
						Solver::TonelliShanks::Solve(n, residue->Prime, residue->Solution1, residue->Solution2);
						mpz_sub(residue->Solution1, residue->Solution1, x);
						mpz_powm_ui(residue->Solution1, residue->Solution1, 1, residue->Prime);
						mpz_sub(residue->Solution2, residue->Solution2, x);
						mpz_powm_ui(residue->Solution2, residue->Solution2, 1, residue->Prime);
						residue->ULLPrime = strtoull(mpz_get_str(NULL, 10, residue->Prime), NULL, 10);
						residue->ULLIndexOfSolution1 = strtoull(mpz_get_str(NULL, 10, residue->Solution1), NULL, 10);
						residue->ULLIndexOfSolution2 = strtoull(mpz_get_str(NULL, 10, residue->Solution2), NULL, 10);
						factorBase.push_back(residue);
					}
				}
				cp = primes->size();
				delete primes;
				cf = 0;
				cb = 0;
				while(cf <= cp){
					cb = cs;
					cs = cs + 100;
					Other::MyHelper::Realloc(&W, cs);
					Other::MyHelper::Realloc(&V, cs);
					for(unsigned long long i = cb; i < cs; i++) {
						mpz_init2(W[i], sizeof(mpz_t));
						mpz_init2(V[i], sizeof(mpz_t));
						mpz_set_str(V[i], to_string(i).c_str(), 10);
						mpz_add(V[i], V[i], x);
						mpz_pow_ui(V[i], V[i], 2);
						mpz_sub(V[i], V[i], n);
						mpz_set(W[i], V[i]);
					}
					for(Elements::QuadraticResidue* residue : factorBase){
						Other::MyHelper::DivideSieve(W, cs, &residue->ULLIndexOfSolution1, residue->ULLPrime);
						Other::MyHelper::DivideSieve(W, cs, &residue->ULLIndexOfSolution2, residue->ULLPrime);
					}
					for(unsigned long long i = cb; i < cs; i++) {
						if(mpz_cmp_ui(W[i], 1) == 0){
							cf++;
							Other::MyHelper::Realloc(&L, cf);
							mpz_init2(L[cf-1], sizeof(mpz_t));
							mpz_set_str(L[cf-1], to_string(i).c_str(), 10);
							mpz_add(L[cf-1], L[cf-1], x);
							mpz_pow_ui(L[cf-1], L[cf-1], 2);
							Other::MyHelper::Realloc(&R, cf);
							mpz_init2(R[cf-1], sizeof(mpz_t));
							mpz_set(R[cf-1], V[i]);
							vector<bool> row = {};
							for(Elements::QuadraticResidue* residue : factorBase){
								mpz_mod(residue->ModPrime, R[cf-1], residue->Prime);
								row.push_back(mpz_cmp_ui(residue->ModPrime, 0) == 0);
							}
							matrix.push_back(row);
						}
					}

					printf("fb = %u, cf = %u, cp = %u, cs = %u\n", factorBase.size(), cf, cp, cs);
					break;
				}
				vector<vector<bool>> identityMatrix = Other::MyHelper::GetIdentityMatrix(cf);
				Solver::GaussianElimination::SolveMod2(matrix, identityMatrix);
				for(vector<bool> row : matrix){
					if(accumulate(row.begin(), row.end(), 0) == 0){



						for(unsigned long long j = 0; j < row.size(); j++){


						}

					}
				}




				Other::MyHelper::PrintMatrix(matrix);

				printf("\n");

				Other::MyHelper::PrintMatrix(identityMatrix);






/*
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
*/


				printf("The end is true");
return;



















				break;

				b = b * 2;


			}while(theEnd == false);






			//clear...
			for(unsigned long long i = 0; i < cs; i++){
				mpz_clear(W[i]);
				mpz_clear(V[i]);
			}
			for(unsigned long long i = 0; i < cf; i++){
				mpz_clear(L[i]);
				mpz_clear(R[i]);
			}
			free(W);
			free(V);
			free(L);
			free(R);

			printf("The end is true");
			return;





/*











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
					Solver::GaussianElimination::SolveMod2(A, B);

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

*/

			//check
			Other::MyHelper::CheckResult(n, q, p);
		}

		//clear
		mpz_clears(n, q, p, nmod, x, xrem,
				right, rightMod, left, leftMod, alpha, beta, gamma, NULL);
	}
}
