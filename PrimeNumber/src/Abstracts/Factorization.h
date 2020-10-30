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
		mpz_t n0, n1, n2;
	};
}

#endif
