#include "../../MyHeader.h"

#ifndef ALGORITHMS_FERMAT_H_
#define ALGORITHMS_FERMAT_H_

namespace Factorization {
	class Fermat : public Abstracts::Factorization  {
	public:
		Fermat();
		virtual ~Fermat();
		void Factor(string input);
	};
}

#endif
