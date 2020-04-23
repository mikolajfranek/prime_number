#include "QuadraticSieve.h"


list<int> QuadraticSieve::GetPrimeListBelowN(int n){
	list<int> primes = {};
	bool arr[n+1];
	memset(arr, true, sizeof(arr));
	int nsqrt = sqrt(n);
	for(int i = 2; i <= nsqrt; i++){
		if(arr[i]){
			for(int j = i*i; j <= n; j += i){
				arr[j] = false;
			}
		}
	}
	for(int i = 2; i < n; i++){
		if(arr[i]){
			primes.push_back(i);
		}
	}
	return primes;
}


void QuadraticSieve::Factor(string input){

	//declare
	mpz_t n, q, p, nmod, nsqrt, nsqrtrem, temp;

	//init
	mpz_inits(n, q, p, nmod, nsqrt, nsqrtrem, temp, NULL);

	//set
	mpz_set_str(n, input.c_str(), 10);

	//start algorithm
	mpz_mod_ui(nmod, n, 2);
	if(mpz_cmp_ui(nmod, 0) == 0){
		mpz_div_ui(q, n, 2);
		mpz_set_ui(p, 2);
	}else{
		mpz_sqrtrem(nsqrt, nsqrtrem, n);
		if(mpz_cmp_ui(nsqrtrem, 0) != 0){
			mpz_add_ui(nsqrt, nsqrt, 1);
		}


		int b = 30;
		int m = 100;


		//quadratic residue
		list<int> quadraticResidue = {};
		for (int prime : GetPrimeListBelowN(b)){
			mpz_set_ui(temp, prime);
			if(mpz_legendre(n, temp) == 1){
				quadraticResidue.push_back(prime);
			}
		}

		//define
		mpz_t Y[m];
		mpz_t V[m];
		for(int i=0;i<m;i++) mpz_init2(Y[i], sizeof(mpz_t));
		for(int i=0;i<m;i++) mpz_init2(V[i], sizeof(mpz_t));

		//calculate Q(x)
		for(int i = 0; i < m; i++){
			 mpz_set_ui(V[i], i);
			 mpz_add(V[i], V[i], nsqrt);
			 mpz_pow_ui(V[i], V[i], 2);
			 mpz_sub(V[i], V[i], n);
			 mpz_set(Y[i], V[i]);
		}


		quadraticResidue.pop_front();
		for (int residue : quadraticResidue){
			mpz_set_ui(temp, residue);
			cout << residue << endl;
			Tonelli_Shanks(n, temp);
		}


/*
		for (int residue : quadraticResidue){
			mpz_set_ui(temp, residue);

			long r1, r2;
			Tonelli_Shanks(n, temp, r1, r2);

			cout << r1 << " -- " << r2 << endl;


		}
*/

		//print
		//for(int i=0;i<m;i++) {
			//gmp_printf("--- %Zd\n", V[i]);
		//}



		//clear
		for(int i=0;i<m;i++) mpz_clear(Y[i]);
		for(int i=0;i<m;i++) mpz_clear(V[i]);
	}

	//clear
	mpz_clears(n, q, p, nmod, nsqrt, nsqrtrem, temp, NULL);
	gmp_printf("This is end of program\n");
	return;
}




		/*
		int size = 100;

		mpz_t R[size];
		mpz_t V[size];
		for(int i=0;i<size;i++) mpz_init2(R[i], sizeof(mpz_t));
		for(int i=0;i<size;i++) mpz_init2(V[i], sizeof(mpz_t));

		for(int i=0;i<size;i++){
			 mpz_set_si(R[i], i);
			 mpz_add(R[i], R[i], nsqrt);
			 mpz_pow_ui(R[i], R[i], 2);
			 mpz_sub(R[i], R[i], n);
			 mpz_set(V[i], R[i]);
		}


		int countPrime = 4;
		int ppp[] = {2, 17, 23, 29};

		for(int j = 0; j < countPrime; j++){

			mpz_set_si(temp1, ppp[j]);

			//for p > 2 there is two result
			long r1, r2;
			Tonelli_Shanks(n, temp1, r1, r2);

			cout << r1 << " -- " << r2 << endl;

			if(ppp[j] == 2){
				for(int x = r1; x < size; x+=ppp[j]){
					mpz_div_ui(R[x], R[x], ppp[j]);
				}
			}else{
				if(r1 != -1){
					r1 = (r1  - (long)mpz_get_ui(nsqrt)) % (long)ppp[j];
					r1 = r1 < 0 ? r1 + ppp[j] : r1;
					for(int x = r1; x < size; x+=ppp[j]){
						mpz_div_ui(R[x], R[x], ppp[j]);
					}
				}

				if(r2 != -1){
					r2 = (r2  - (long)mpz_get_ui(nsqrt)) % (long)ppp[j];
					r2 = r2 < 0 ? r2 + ppp[j] : r2;

					for(int x = r2; x < size; x+=ppp[j]){
						mpz_div_ui(R[x], R[x], ppp[j]);
					}
				}
			}

		}
		//how many R[i] = 1 must be?



		//124, 127, 195
		int x[3] = {0,0,0};


		//29, 782, 22678
		int Q[3] = {0,0,0};

		int j = 0;
		for(int i=0;i<size;i++){
			if((long)mpz_get_ui(R[i]) ==1){
				x[j] = i +  (long)mpz_get_ui(nsqrt);
				Q[j++] = (long)mpz_get_ui(V[i]);

			}
		}



		int s[3] = {0,0,0};
		float matrix[M][M] = {
				{0,0,0,0, 0},
				{0,0,0,0, 0},
				{0,0,0,0, 0},
		};



		for(int i=0;i<3;i++) {
			for(int j = 0; j < 4; j++){
				if(Q[i] % (int)ppp[j] == 0){
					matrix[i][j] = 1.0;
					//q[i] /= (int)ppp[j];
				}
			}
		}


		//show matrix
		for(int i=0;i<3;i++){
			for(int j=0;j<5;j++){
				cout << matrix[i][j];
			}
			cout << endl;
		}

		int nn = 2, flag = 0;
		flag = PerformOperation(matrix, nn);

		cout << endl;
		//show matrix

		long a = 1;
		long bb = 1;
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				a = a * (int)(x[j]*matrix[i][j]);
				bb = bb * (int)(Q[j]*matrix[i][j]);
			}
			break;
		}

		bb = sqrt(bb);

		//cout << a << endl;
		//cout << b << endl;
		//cout << mpz_get_ui(z_n) << endl;

		mpz_set_ui(p, a-bb);
		mpz_set_ui(q, mpz_get_ui(n) );

		//gcd
		mpz_gcd(p, p, q);

		mpz_div(q, n, p);



		for(int i=0;i<size;i++) mpz_clear(V[i]);
		for(int i=0;i<size;i++) mpz_clear(R[i]);

	}

	Algorithm::CheckResult(n, p, q);

	//clear
	mpz_clear(n);
	mpz_clear(nmod2);
	mpz_clear(nsqrt);
	mpz_clear(nsqrtrem);
	mpz_clear(p);
	mpz_clear(q);
	mpz_clear(temp1);
	*/





bool QuadraticSieve::InputHasFormPowPToM(mpz_t n){

	bool result = false;

	//declare
	mpz_t root, rem;

	//init
	mpz_inits(root, rem, NULL);

	//start
	for(long m = 2; ;m++){
		mpz_rootrem(root, rem, n, m);
		if(mpz_cmp_ui(rem, 0) == 0){
			result = true;
			break;
		}else if(mpz_cmp_ui(root, 1) == 0){
			break;
		}
	}

	//clear
	mpz_clears(root, rem, NULL);

	return result;
}



// function to reduce matrix to reduced
// row echelon form.
int QuadraticSieve::PerformOperation(float a[][M], int n)
{
    int i, j, k = 0, c, flag = 0, m = 0;
    float pro = 0;

    // Performing elementary operations
    for (i = 0; i < n; i++)
    {
        if (a[i][i] == 0)
        {
            c = 1;
            while (a[i + c][i] == 0 && (i + c) < n)
                c++;
            if ((i + c) == n) {
                flag = 1;
                break;
            }
            for (j = i, k = 0; k <= n; k++)
                swap(a[j][k], a[j+c][k]);
        }

        for (j = 0; j < n; j++) {

            // Excluding all i == j
            if (i != j) {

                // Converting Matrix to reduced row
                // echelon form(diagonal matrix)
                float pro = a[j][i] / a[i][i];

                for (k = 0; k <= n; k++)
                    a[j][k] = a[j][k] - (a[i][k]) * pro;
            }
        }
    }
    return flag;
}


// To check whether infinite solutions
// exists or no solution exists
int QuadraticSieve::CheckConsistency(float a[][M], int n, int flag)
{
    int i, j;
    float sum;

    // flag == 2 for infinite solution
    // flag == 3 for No solution
    flag = 3;
    for (i = 0; i < n; i++)
    {
        sum = 0;
        for (j = 0; j < n; j++)
            sum = sum + a[i][j];
        if (sum == a[i][j])
            flag = 2;
    }
    return flag;
}

void QuadraticSieve::PowCExpD(mpz_t r, mpz_t c, mpz_t d){
	mpz_t i;
	mpz_inits(i);
	mpz_set_ui(r, 1);
	for(mpz_set_ui(i, 0); mpz_cmp(i, d) <= 0; mpz_add_ui(i, i, 1)){
		mpz_mul(r, r, c);
	}
	mpz_clears(i);
}

void QuadraticSieve::Tonelli_Shanks(mpz_t n, mpz_t p){

	mpz_t s, e, f, t, x, g, b, r, m, c, d, temp;
	mpz_inits(s, e, f, t, x, g, b, r, m, c, d, temp, NULL);

	//p-1 = s*2^(e)
	mpz_set_ui(e, 0);
	mpz_sub_ui(s, p, 1);
	mpz_mod_ui(temp, s, 2);
	while(mpz_cmp_ui(temp, 0) == 0){
		mpz_div_ui(s, s, 2);
		mpz_add_ui(e, e, 1);
		mpz_mod_ui(temp, s, 2);
	}

	//(p-1)/2
	mpz_set(temp, p);
	mpz_sub_ui(temp, temp, 1);
	mpz_div_ui(temp, temp, 2);

	//t^((p-1)/2) mod p
	mpz_set_ui(t, 2);
	mpz_powm(f, t, temp, p);

	//find non-residue
	while(mpz_legendre(t, p) == -1){
		mpz_add_ui(t, t, 1);
	}

	//initizalize
	mpz_powm_ui(r, e, 1, p);
	mpz_powm(g, t, s, p);
	mpz_powm(b, n, s, p);
	mpz_set(temp, s);
	mpz_add_ui(temp, temp, 1);
	mpz_div_ui(temp, temp, 2);
	mpz_powm(x, n, temp, p);




	while(true){
		//search m
		mpz_set_ui(m, 0);
		while(true){
			mpz_set_ui(c, 2);
			PowCExpD(temp, c, m);
			mpz_powm(temp, b, temp, p);
			if(mpz_cmp_ui(temp, 1) == 0) break;
			mpz_add_ui(m, m, 1);
		}

		//check
		if(mpz_cmp_ui(m, 0) == 0){
			gmp_printf("SOLUTION--- %Zd\n", x);
			break;
		}

		gmp_printf("??--- %Zd\n", x);


		//update
		//r-m-1
		mpz_set(d, r);
		mpz_sub(d, d, m);
		mpz_sub_ui(d, d, 1);
		//2^(r-m-1)
		mpz_set_ui(c, 2);
		PowCExpD(temp, c, d);
		//g^(2^(r-m-1))
		mpz_set(c, g);
		mpz_set(d, temp);
		PowCExpD(temp, c, d);
		//x * g^(2^(r-m-1))
		mpz_mul(x, x, temp);
		mpz_powm_ui(x, x, 1, p);


		//r-m
		mpz_set(d, r);
		mpz_sub(d, d, m);
		//2^(r-m)
		mpz_set_ui(c, 2);
		PowCExpD(temp, c, d);
		//g^(2^(r-m))
		mpz_set(c, g);
		mpz_set(d, temp);
		PowCExpD(temp, c, d);
		//b * g^(2^(r-m))
		mpz_mul(b, b, temp);
		mpz_powm_ui(b, b, 1, p);


		//r-m
		mpz_set(d, r);
		mpz_sub(d, d, m);
		//2^(r-m)
		mpz_set_ui(c, 2);
		PowCExpD(temp, c, d);
		//g^(2^(r-m))
		mpz_set(c, g);
		mpz_set(d, temp);
		PowCExpD(g, c, d);
		mpz_powm_ui(g, g, 1, p);


		mpz_set(r, m);
		mpz_powm_ui(r, r, 1, p);
	}

	mpz_clears(p, s, e, f, t, x, g, b, r, m, c, d, temp, NULL);

}














	/*

	mpz_t m;
	mpz_t c;
	mpz_t t;
	mpz_t r;
	mpz_init(m);
	mpz_init(c);
	mpz_init(t);
	mpz_init(r);




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
	*/



