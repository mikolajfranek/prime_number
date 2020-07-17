#include "../../MyHeader.h"

#ifndef ALGORITHMS_SOLVER_TONELLISHANKS_H_
#define ALGORITHMS_SOLVER_TONELLISHANKS_H_

namespace Solver {
	class TonelliShanks {
	public:
		static void Solve(mpz_t n, mpz_t p, mpz_t alpha, mpz_t beta);
	};
}

#endif
