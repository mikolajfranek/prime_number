#include "../Main.h"

#ifndef ELEMENTS_ELEMENTOFSIEVE_H_
#define ELEMENTS_ELEMENTOFSIEVE_H_

namespace Elements {
	class ElementOfSieve {
	public:
		mpz_t Number;
		ElementOfSieve DeepCopy();
		ElementOfSieve();
		virtual ~ElementOfSieve();
	};
}

#endif
