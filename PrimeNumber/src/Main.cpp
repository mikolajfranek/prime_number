#include "Main.h"

/* run benchmark macro */
//BENCHMARK_MAIN();

int main(int argc, char *argv[]){
	//AlgorithmsAbstracts::IFactorization *factorization = new AlgorithmsFactorization::QuadraticSieve();
	//factorization->Factor(Elements::MyHelper::GetSemiPrime(20));
	//factorization->CheckResult(true);
	//delete factorization;




	mpz_t input, iterator;
	mpz_inits(input, iterator, NULL);

	//9999999999
	//1000000000

	for(int i = 0; i <= 80; i++){

		//20
		string inputStr = "99999999999999999999";
		for(int j = 0; j < i; j++){
			inputStr += "9";
		}
		mpz_set_str(input, inputStr.c_str(), 10);


		for(mpz_set(iterator, input); ; mpz_sub_ui(iterator, iterator, 2)){
			if(mpz_probab_prime_p(iterator, 15) > 0){
				mpz_sub_ui(input, input, 1);
				mpz_div_ui(input, input, 2);
				if(mpz_probab_prime_p(input, 15) > 0){

					gmp_printf(" %d %Zd\n", 20+i, iterator);
					break;
				}
			}
		}

	}






	mpz_clears(input, iterator, NULL);
	return 0;
}
