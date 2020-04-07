#include "../Configurations/MyConfiguration.h"
#include "Algorithm.h"

#ifndef ALGORITHMS_QUADRATICSIEVE_H_
#define ALGORITHMS_QUADRATICSIEVE_H_

class QuadraticSieve {
public:
	static void Factor(string n);

	static void Tonelli_Shanks(mpz_t n, mpz_t p, long& r1, long &r2);



#define M 10

	static int PerformOperation(float a[][M], int n);
	static int CheckConsistency(float a[][M], int n, int flag);


private:
	static bool InputHasFormPowPToM(mpz_t n);



	//static bool EulerCriterion(mpz_t a, mpz_t p, mpz_t exp, mpz_t tem);
};

#endif
