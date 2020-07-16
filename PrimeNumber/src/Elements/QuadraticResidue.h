#include "../MyHeader.h"

#ifndef ELEMENTS_QUADRATICRESIDUE_H_
#define ELEMENTS_QUADRATICRESIDUE_H_

namespace Elements {
	class QuadraticResidue {
	public:
		mpz_t Prime;
		mpz_t Solution1;
		mpz_t Solution2;
		QuadraticResidue();
		QuadraticResidue(short n, short solution1, short solution2);
		~QuadraticResidue();
	};

	struct HashQuadraticResidue {
	    size_t operator() (QuadraticResidue const * quadraticResidue) const {
	    	return hash<string>{}(mpz_get_str(NULL, 10, quadraticResidue->Prime));
	    }
	};

	struct EqualToQuadraticResidue {
		bool operator()(QuadraticResidue const * quadraticResidue1, QuadraticResidue const * quadraticResidue2) const {
			if (mpz_cmp(quadraticResidue1->Prime, quadraticResidue2->Prime) == 0){
				return true;
			}
			return false;
		}
	};
}

#endif
