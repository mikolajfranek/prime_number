#include "Configurations/MyConfiguration.h"
#include "Programs/NumberFactoring.h"
#include "Programs/PrimalityTesting.h"





static void BM_StringCreation(benchmark::State& state) {
  for (auto _ : state)
    string empty_string;
}
// Register the function as a benchmark
BENCHMARK(BM_StringCreation);

// Define another benchmark
static void BM_StringCopy(benchmark::State& state) {
  string x = "hello";
  for (auto _ : state)
    string copy(x);
}
BENCHMARK(BM_StringCopy);




/* benchmark methods */
//BENCHMARK_MAIN();

/* number factoring */
NUMBER_FACTORING(MyConfiguration::NUMBER_FACTORING::SIEVE_OF_ERATOSTHENES);

/* primality testing */
//PRIMALITY_TESTING(MyConfiguration::PRIMALITY_TESTING::EXAMPLE);
