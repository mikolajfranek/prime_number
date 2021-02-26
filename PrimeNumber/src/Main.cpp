#include "Main.h"

/* run benchmark macro */
//BENCHMARK_MAIN();

#include <iostream>
#include <gmpxx.h>

int main(int argc, char *argv[]){
	//AlgorithmsAbstracts::IFactorization *factorization = new AlgorithmsFactorization::QuadraticSieve();
	//factorization->Factor(Elements::MyHelper::GetSemiPrime(20));
	//factorization->CheckResult(true);
	//delete factorization;



	string path = "/home/debian/Dokumenty/pierwsze4092.txt";
	ComponentsFiles::FileWriter *fileOne = new ComponentsFiles::FileWriter(path);


	mpz_t input, iterator;
	mpz_inits(input, iterator, NULL);


	//awk 'NR % 2 == 0' pierwsze.txt | tr -d '[:alpha:]' | tr -d '[=;=]' | tr -d '[="=]' | tr -d '[:blank:]' | xargs openssl prime $1 | xargs -I {} bash -c 'if [[ "{}" =~ "is not prime" ]]; then echo "1"; fi'


	for(int i = 4092; i <= 4096; i++){

		//20
		string inputStr = "";
		for(int j = 0; j < (i); j++){
			inputStr += "1";
		}
		mpz_set_str(input, inputStr.c_str(), 2);



		for(mpz_set(iterator, input); ; mpz_sub_ui(iterator, iterator, 2)){
			if(mpz_probab_prime_p(iterator, 15) > 0){
				mpz_sub_ui(input, input, 1);
				mpz_div_ui(input, input, 2);
				if(mpz_probab_prime_p(input, 15) > 0){

					string toOutput = "";


					FILE *result;
					result=fopen(path.c_str(),"a+");


				    mpz_class a(iterator);
				    if(a.get_str(2).length() != i){
				    	printf("%d is not ok\n", i);
				    }else{
				    	printf("%d\n", i);
				    }
					gmp_fprintf(result, "case %d:\n\treturn \"%Zd\";", i, iterator);


					fclose(result);

					fileOne->writeLine(toOutput);




					break;
				}
			}
		}

	}






	mpz_clears(input, iterator, NULL);
	return 0;
}
