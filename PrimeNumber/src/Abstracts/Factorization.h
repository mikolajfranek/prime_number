#include "../MyHeader.h"

#ifndef ABSTRACTS_FACTORIZATION_H_
#define ABSTRACTS_FACTORIZATION_H_

namespace Abstracts {
	class Factorization {
	public:
		Factorization();
		virtual ~Factorization();
		virtual void Factor(string input) = 0;
		void CheckResult();
	protected:
		mpz_t m0, m1, m2;
	};
}

#endif
