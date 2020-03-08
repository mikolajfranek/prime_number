#include <iostream>
#include "Algorithms/SieveOfEratosthenes.h"
using namespace std;

int main() {
	SieveOfEratosthenes *sieveOfEratosthenes = new SieveOfEratosthenes();

	sieveOfEratosthenes -> Factor(21);

	return 0;
}
