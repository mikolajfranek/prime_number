#include "NumberFactoring.h"

int NumberFactoring::Main(MyConfiguration::NUMBER_FACTORING algorithm){

	//#TODO - get also 617 digit number
	for(int i = 10; i <= 10; i+=10){
		switch(algorithm){
			case MyConfiguration::NUMBER_FACTORING::SIEVE_OF_ERATOSTHENES:
					cout << MyConfiguration::GetSemiPrime(i) << endl;
				break;

			case MyConfiguration::NUMBER_FACTORING::FERMAT:

				break;
		}
	}

	return 0;
}
