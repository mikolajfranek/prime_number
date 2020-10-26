#include "../MyHeader.h"

#ifndef ABSTRACTS_FACTORIZATION_H_
#define ABSTRACTS_FACTORIZATION_H_

namespace Abstracts {
	class Factorization {
	public:
		virtual void Factor(string input) = 0;
		virtual ~Factorization() {}
	};
}

#endif
