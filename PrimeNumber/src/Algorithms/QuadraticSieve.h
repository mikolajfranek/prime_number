#include "../Configurations/MyConfiguration.h"
#include "Algorithm.h"

#ifndef ALGORITHMS_QUADRATICSIEVE_H_
#define ALGORITHMS_QUADRATICSIEVE_H_

class QuadraticSieve {
public:
	static void Factor(string n);

	static void Tonelli_Shanks(mpz_t n, mpz_t p, long& r1, long &r2);



#define N 3

	static void gaussianElimination(double mat[N][N+1]);
	static void  swap_row(double mat[N][N+1], int i, int j);
	static void  print(double mat[N][N+1]);
	static int  forwardElim(double mat[N][N+1]);
	static void  backSub(double mat[N][N+1]);


private:

};

#endif
