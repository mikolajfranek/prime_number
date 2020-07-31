#include "../../MyHeader.h"

#ifndef ALGORITHMS_SOLVER_GAUSSIANELIMINATION_H_
#define ALGORITHMS_SOLVER_GAUSSIANELIMINATION_H_

namespace Solver {
	class GaussianElimination {
	public:
		static void SolveMod2(vector<vector<bool>*> &A, vector<vector<bool>*> &B);
	};
}

#endif
