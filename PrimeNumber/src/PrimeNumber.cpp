#include <iostream>
#include "Algorithms/SieveOfEratosthenes.h"
using namespace std;

#include <stdio.h>
#include <gmp.h>
#include <gmpxx.h>

#include <benchmark/benchmark.h>


static void BM_StringCreation(benchmark::State& state) {
  for (auto _ : state)
    std::string empty_string;
}
// Register the function as a benchmark
BENCHMARK(BM_StringCreation);

// Define another benchmark
static void BM_StringCopy(benchmark::State& state) {
  std::string x = "hello";
  for (auto _ : state)

    std::string copy(x);
}
BENCHMARK(BM_StringCopy);

BENCHMARK_MAIN();

/*
int main(int argc, char **argv) {

	mpz_t p;
	mpz_t q ;
	mpz_t n;

	mpz_init(p);
	mpz_init(q);
	mpz_init(n);

	mpz_set_str(p, "1000", 10);
	mpz_set_str(q, "2", 10);

	mpz_mul(n, p, q);

	gmp_printf("%Zd = %Zd * %Zd\n", n, p, q);

	mpz_clear(p);
	mpz_clear(q);
	mpz_clear(n);


	SieveOfEratosthenes sieveOfEratosthenes;

	sieveOfEratosthenes.Factor(21);

	return 0;
}
*/
