#include "../Main.h"

#ifndef ABSTRACTS_PRIMALITY_H_
#define ABSTRACTS_PRIMALITY_H_

namespace Abstracts {
	class Primality {
	public:
		Primality();
		virtual ~Primality();
		virtual bool IsPrime(string input) = 0;
		void CheckResult(bool isPrime, bool prediction);
	protected:
		mpz_t m0;
	};
}

#endif
