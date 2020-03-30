#include "QuadraticSieve.h"

#include <math.h>

void QuadraticSieve::Factor(string input){

	//declare
	mpz_t z_n;
	mpz_t z_nmod2;
	mpz_t z_nsqrt;
	mpz_t z_nsqrtrem;
	mpz_t z_p;
	mpz_t z_q;
	mpz_t z_prime;

	//init
	mpz_init_set_str(z_n, input.c_str(), 10);
	mpz_init(z_nmod2);
	mpz_init(z_nsqrt);
	mpz_init(z_nsqrtrem);
	mpz_init(z_p);
	mpz_init(z_q);
	mpz_init(z_prime);


	//start algorithm
	mpz_mod_ui(z_nmod2, z_n, 2);
	if(mpz_cmp_ui(z_nmod2, 0) == 0){
		mpz_div_ui(z_q, z_n, 2);
		mpz_set_ui(z_p, 2);
	}else{

		mpz_sqrt(z_nsqrt, z_n);
		mpz_sqrtrem(z_nsqrt, z_nsqrtrem, z_n);
		if(mpz_cmp_ui(z_nsqrt, 0) != 0){
			mpz_add_ui(z_nsqrt, z_nsqrt, 1);
		}

		int size = 30;


		mpz_t R[size];
		mpz_t V[size];
		for(int i=0;i<size;i++) mpz_init2(R[i], sizeof(mpz_t));
		for(int i=0;i<size;i++) mpz_init2(V[i], sizeof(mpz_t));

		for(int i=0;i<size;i++){
			 mpz_set_ui(R[i], i);
			 mpz_add(R[i], R[i], z_nsqrt);
			 mpz_pow_ui(R[i], R[i], 2);
			 mpz_sub(R[i], R[i], z_n);
			 mpz_set(V[i], R[i]);
		}




		int primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,37,41,43,47,53,59,61,67,71, 73, 79, 83, 89, 97};
		int selected[10];
		int z = 0;
		for(int i = 0; i < sizeof(primes)/2 ; i++){
			mpz_set_ui(z_prime, primes[i]);
			if(mpz_jacobi(z_n, z_prime) == 1){
				selected[z++] = primes[i];
			}
		}




		int countPrime = z;
		for(int j = 0; j < countPrime+1; j++){

			mpz_set_ui(z_prime, selected[j]);

			//for p > 2 there is two result
			long r1, r2;
			Tonelli_Shanks(z_n, z_prime, r1, r2);

			if(selected[j] == 2){
				for(int x = r1; x < size; x+=primes[j]){
					mpz_div_ui(R[x], R[x], primes[j]);
				}
			}else{
				if(r1 != -1){
					r1 = (r1  - (long)mpz_get_ui(z_nsqrt)) % (long)selected[j];
					r1 = r1 < 0 ? r1 + selected[j] : r1;
					for(int x = r1; x < size; x+=selected[j]){
						mpz_div_ui(R[x], R[x], selected[j]);
					}
				}

				if(r2 != -1){
					r2 = (r2  - (long)mpz_get_ui(z_nsqrt)) % (long)selected[j];
					r2 = r2 < 0 ? r2 + selected[j] : r2;

					for(int x = r2; x < size; x+=selected[j]){
						mpz_div_ui(R[x], R[x], selected[j]);
					}
				}
			}

		}
		//how many R[i] = 1 must be?
		//for(int i=0;i<size;i++) cout << R[i] << endl;


		//prepare X i Y
		int x[3] = {0,0,0};
		int y[3] = {0,0,0};

		int j = 0;
		for(int i=0;i<size;i++){
			if((long)mpz_get_ui(R[i]) ==1){
				x[j] = i +  (long)mpz_get_ui(z_nsqrt);
				y[j++] = (long)mpz_get_ui(V[i]);
				cout << j << endl;
			}
		}

		return;




		int s[3] = {0,0,0};
		double matrix[4][4] = {
				{0.0,0.0,0.0,0.0},
				{0.0,0.0,0.0,0.0},
				{0.0,0.0,0.0,0.0},
				{0.0,0.0,0.0,0.0}
		};



		for(int i=0;i<4;i++) {
			for(int j = 0; j < countPrime+1; j++){
				if(y[i] % (int)primes[j] == 0){
					matrix[i][j] = 1.0;
					y[i] /= (int)primes[j];
				}
			}
		}


		//show matrix
		for(int i=0;i<3;i++){
			for(int j=0;j<4;j++){
				cout << matrix[i][j];
			}
			cout << endl;
		}

		int zero[4] = {0,0,0,0};


//
		//solve equation
		//gaussianElimination(matrix);




		return;






		for(int i=0;i<size;i++) mpz_clear(V[i]);
		for(int i=0;i<size;i++) mpz_clear(R[i]);

	}

	Algorithm::CheckResult(z_n, z_p, z_q);

	//clear
	mpz_clear(z_n);
	mpz_clear(z_nmod2);
	mpz_clear(z_nsqrt);
	mpz_clear(z_nsqrtrem);
	mpz_clear(z_p);
	mpz_clear(z_q);
	mpz_clear(z_prime);
}


// function to get matrix content
void QuadraticSieve::gaussianElimination(double mat[N][N+1])
{
    /* reduction into r.e.f. */
    int singular_flag = forwardElim(mat);

    /* if matrix is singular */
    if (singular_flag != -1)
    {
        printf("Singular Matrix.\n");

        /* if the RHS of equation corresponding to
           zero row  is 0, * system has infinitely
           many solutions, else inconsistent*/
        if (mat[singular_flag][N])
            printf("Inconsistent System.");
        else
            printf("May have infinitely many "
                   "solutions.");

        return;
    }

    /* get solution to system and print it using
       backward substitution */
    backSub(mat);
}

// function for elementary operation of swapping two rows
void  QuadraticSieve::swap_row(double mat[N][N+1], int i, int j)
{
    //printf("Swapped rows %d and %d\n", i, j);

    for (int k=0; k<=N; k++)
    {
        double temp = mat[i][k];
        mat[i][k] = mat[j][k];
        mat[j][k] = temp;
    }
}

// function to print matrix content at any stage
void  QuadraticSieve::print(double mat[N][N+1])
{
    for (int i=0; i<N; i++, printf("\n"))
        for (int j=0; j<=N; j++)
            printf("%lf ", mat[i][j]);

    printf("\n");
}

// function to reduce matrix to r.e.f.
int  QuadraticSieve::forwardElim(double mat[N][N+1])
{
    for (int k=0; k<N; k++)
    {
        // Initialize maximum value and index for pivot
        int i_max = k;
        int v_max = mat[i_max][k];

        /* find greater amplitude for pivot if any */
        for (int i = k+1; i < N; i++)
            if (abs(mat[i][k]) > v_max)
                v_max = mat[i][k], i_max = i;

        /* if a prinicipal diagonal element  is zero,
         * it denotes that matrix is singular, and
         * will lead to a division-by-zero later. */
        if (!mat[k][i_max])
            return k; // Matrix is singular

        /* Swap the greatest value row with current row */
        if (i_max != k)
            swap_row(mat, k, i_max);


        for (int i=k+1; i<N; i++)
        {
            /* factor f to set current row kth element to 0,
             * and subsequently remaining kth column to 0 */
            double f = mat[i][k]/mat[k][k];

            /* subtract fth multiple of corresponding kth
               row element*/
            for (int j=k+1; j<=N; j++)
                mat[i][j] -= mat[k][j]*f;

            /* filling lower triangular matrix with zeros*/
            mat[i][k] = 0;
        }

        //print(mat);        //for matrix state
    }
    //print(mat);            //for matrix state
    return -1;
}

// function to calculate the values of the unknowns
void  QuadraticSieve::backSub(double mat[N][N+1])
{
    double x[N];  // An array to store solution

    /* Start calculating from last equation up to the
       first */
    for (int i = N-1; i >= 0; i--)
    {
        /* start with the RHS of the equation */
        x[i] = mat[i][N];

        /* Initialize j to i+1 since matrix is upper
           triangular*/
        for (int j=i+1; j<N; j++)
        {
            /* subtract all the lhs values
             * except the coefficient of the variable
             * whose value is being calculated */
            x[i] -= mat[i][j]*x[j];
        }

        /* divide the RHS by the coefficient of the
           unknown being calculated */
        x[i] = x[i]/mat[i][i];
    }

    printf("\nSolution for the system:\n");
    for (int i=0; i<N; i++)
        printf("%lf\n", x[i]);
}

void QuadraticSieve::Tonelli_Shanks(mpz_t n, mpz_t p, long& r1, long &r2){

	mpz_t m;
	mpz_t c;
	mpz_t t;
	mpz_t r;
	mpz_init(m);
	mpz_init(c);
	mpz_init(t);
	mpz_init(r);


	mpz_t nmod4;
	mpz_init(nmod4);
	mpz_mod_ui(nmod4, p, 4);
	if(mpz_cmp_ui(nmod4, 1) != 0 || mpz_jacobi(n, p) != 1){
		gmp_printf("init condition failed\n");
		r1 = -1;
		r2 = -1;
		return;
	}
	mpz_clear(nmod4);



	mpz_t z;
	mpz_t s;
	mpz_t q;
	mpz_t qexp;
	mpz_t qmod2;
	mpz_init(s);
	mpz_init(q);
	mpz_init(qexp);
	mpz_init(qmod2);
	mpz_init_set(q, p);

	//q, s
	mpz_sub_ui(q, q, 1);
	mpz_init_set_ui(s, 0);
	mpz_mod_ui(qmod2, q, 2);
	while(mpz_cmp_ui(qmod2, 0) == 0){
		mpz_div_ui(q, q, 2);
		mpz_mod_ui(qmod2, q, 2);
		mpz_add_ui(s, s, 1);
	}



	//z
	mpz_init_set_ui(z, 2);
	while(mpz_jacobi(z, p) != -1){
		mpz_add_ui(z, z, 1);
	}
	//gmp_printf(" %Zd \n", z );


	//q = 5
	//s = 3
	//z = 3

	//m
	mpz_mod(m, s, p);

	//c
	mpz_powm(c, z, q, p);

	//t
	mpz_powm(t, n, q, p);

	//r
	mpz_add_ui(qexp, q, 1);
	mpz_div_ui(qexp, qexp, 2);
	mpz_powm(r, n, qexp, p);


	mpz_clear(s);
	mpz_clear(q);
	mpz_clear(qexp);
	mpz_clear(qmod2);
	mpz_clear(z);



	//gmp_printf(" n=%Zd, p=%Zd \n", n, p );
	//gmp_printf(" m=%Zd \n", m);
	//gmp_printf(" c=%Zd \n", c);
	//gmp_printf(" t=%Zd \n", t);
	//gmp_printf(" r=%Zd \n", r);


	mpz_t b;
	mpz_t tpow2;
	mpz_t msub;
	mpz_t tres;
	mpz_t iterator;
	mpz_t helper;
	mpz_init(b);
	mpz_init(tpow2);
	mpz_init(msub);
	mpz_init(tres);
	mpz_init(iterator);
	mpz_init(helper);


//loop
	while(true){
		if(mpz_cmp_ui(t, 0) == 0){
			gmp_printf(" FAILED r=0 \n");
			r1 = -1;
			r2 = -1;
			break;
		}
		if(mpz_cmp_ui(t, 1) == 0){
			gmp_printf(" SUCCESS r=%Zd \n", r);
			r1 = mpz_get_ui(r);

			if(mpz_get_ui(p) > 2){
				mpz_mul_si(r, r, -1);
				mpz_mod(r, r , p);

				r2 = mpz_get_ui(r);
			}else{
				r2 = -1;
			}

			break;
		}


		mpz_set_ui(iterator, 1);
		while(mpz_cmp(iterator, m) < 0){

			//power
			mpz_set_ui(tpow2, 2);
			for(mpz_set_ui(helper, 2); mpz_cmp(helper, iterator) <= 0; mpz_add_ui(helper, helper, 1)){
				mpz_mul_ui(tpow2, tpow2, 2);
			}

			//mul t
			mpz_set(tres, t);
			for(;mpz_cmp_ui(tpow2, 1) > 0; mpz_sub_ui(tpow2, tpow2, 1)){
				mpz_mul(tres, tres, t);
			}

			//congruence
			mpz_mod(tres, tres, p);
			if(mpz_cmp_ui(tres, 1) == 0) break;


			mpz_add_ui(iterator, iterator, 1);
		}



		//gmp_printf(" iterator=%Zd \n", iterator );


		mpz_set(msub, m);
		mpz_sub(msub, msub, iterator);
		mpz_sub_ui(msub, msub, 1);



		//power
		mpz_set_ui(tpow2, 2);
		for(mpz_set_ui(helper, 2); mpz_cmp(helper, msub) <= 0; mpz_add_ui(helper, helper, 1)){
			mpz_mul_ui(tpow2, tpow2, 2);
		}


		//mul b
		mpz_set(b, c);
		if(mpz_cmp_ui(msub, 0) != 0){
			for(;mpz_cmp_ui(tpow2, 1) > 0; mpz_sub_ui(tpow2, tpow2, 1)){
				mpz_mul(b, b, c);
			}
		}
		mpz_powm_ui(b, b, 1, p);



		mpz_set(m, iterator);
		mpz_powm_ui(m, m, 1, p);

		mpz_powm_ui(c, b, 2, p);

		mpz_mul(t, t, c);
		mpz_powm_ui(t, t, 1, p);

		mpz_mul(r, r, b);
		mpz_powm_ui(r, r, 1, p);


	}

	mpz_clear(b);
	mpz_clear(tpow2);
	mpz_clear(msub);
	mpz_clear(tres);
	mpz_clear(iterator);
	mpz_clear(helper);



	mpz_clear(m);
	mpz_clear(c);
	mpz_clear(t);
	mpz_clear(r);
}


