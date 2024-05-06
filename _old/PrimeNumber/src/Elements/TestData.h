#include "../../../../_old/PrimeNumber/src/Main.h"

#ifndef ELEMENTS_TESTDATA_H_
#define ELEMENTS_TESTDATA_H_

namespace Elements {
	class TestData {
	public:
		static string GetRSASemiPrime(unsigned short numberOfBits);
		static string GetSafePrime(unsigned short numberOfBits);
	};
}

#endif
