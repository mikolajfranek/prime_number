#include "QuadraticSieve.h"

void QuadraticSieve::Factor(string input){

	//declare
	mpz_t n, q, p, nmod, x, xrem, right, rightMod, left, leftMod, alpha, beta, gamma;

	//init
	mpz_inits(n, q, p, nmod, x, xrem, right, rightMod, left, leftMod, alpha, beta, gamma, NULL);

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

//------------------------ WHILE END ------------------------

		//calculate right side
		unsigned long long sizeRow = 0;
		unsigned long long sizeCol = factorBase.size();

		mpz_t *H;
		MyHelper::MallocVector(&H, sizeRow);

		mpz_set_ui(right, 1);
		vector<vector<bool>> factors = {};

		for(unsigned long long i = 0; i < y; i++){
			if(mpz_cmp_ui(V[i], 1) == 0){

				mpz_set_str(alpha, to_string(i).c_str(), 10);
				mpz_add(alpha, alpha, x);

				mpz_pow_ui(beta, alpha, 2);
				mpz_mul(right, right, beta);

				MyHelper::ReallocVector(&H, sizeRow + 1);
				mpz_init2(H[sizeRow], sizeof(mpz_t));
				mpz_set(H[sizeRow], Y[i]);
				sizeRow += 1;

				vector<bool> factor = {};
				for(unsigned long long j = 0; j < factorBase.size(); j++){
					mpz_mod_ui(gamma, Y[i], factorBase[j]);
					factor.push_back(mpz_cmp_ui(gamma, 0) == 0);
				}
				factors.push_back(factor);
			}
		}
		mpz_mod(rightMod, right, n);







		//TODO and test

		vector<vector<unsigned long long>> combinations = {};

		enum MY { EQUAL, ROW, COLUMN};
		//calculate left side

		if(sizeRow > sizeCol){

		}else if(sizeRow < sizeCol){

		}else{


			combinations = MyHelper::GetCombination(sizeCol, sizeRow);
		}


		for(vector<unsigned long long> c : MyHelper::GetCombination(sizeCol, sizeRow)){

			//create matrix
			vector<vector<bool>> A = {};
			for(unsigned long long i = 0; i < sizeRow; i++){
				A.push_back(vector<bool>(sizeRow, 0));
			}

			//fill matrix
			unsigned long long u = 0;
			for(unsigned long long j : c){

				for(unsigned long long t = 0; t < sizeRow; t++){
					A[t][u] = factors[t][j];
				}
				u++;
			}

			//solve
			vector<vector<bool>> B = MyHelper::GetIdentityMatrix(sizeRow);
			GaussianElimination::SolveMod2(A, B);

			//search for row of zeros
			bool isRowZero = true;
			bool isFound = false;
			for(unsigned long long i = 0; i < sizeRow; i++){
				isRowZero = true;
				for(unsigned long long j = 0; j < sizeRow; j++){
					if(A[i][j]){
						isRowZero = false;
						break;
					}
				}

				if(isRowZero){
					mpz_set_ui(left, 1);
					for(unsigned long long j = 0; j < sizeRow; j++){
						mpz_mul_ui(gamma, H[j], (int)B[i][j]);
						if(mpz_cmp_ui(gamma, 0) != 0){
							mpz_mul(left, left, gamma);
						}
					}
					mpz_mod(leftMod, left, n);

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
		}






















		//check
		MyHelper::CheckResult(n, q, p);


		//clear
		for(unsigned long long i = 0; i < sizeRow; i++){
			mpz_clear(H[i]);
		}
		free(H);
		for(unsigned long long i = 0; i < y; i++){
			mpz_clear(Y[i]);
			mpz_clear(V[i]);
		}
		free(Y);
		free(V);
	}

	//clear
	mpz_clears(n, q, p, nmod, x, xrem, right, rightMod, left, leftMod, alpha, beta, gamma, NULL);
}
