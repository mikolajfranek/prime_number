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
		~QuadraticResidue();



		bool operator ==(const QuadraticResidue & quadraticResidue) const
		{
			if (mpz_cmp(this->Prime, quadraticResidue.Prime) == 0){
				return true;
			}
			return false;
		}
	};
}

namespace std
{
  template<> struct hash<Elements::QuadraticResidue>
  {
	  size_t operator()(const Elements::QuadraticResidue & quadraticResidue) const
	  {
		  return (hash<string>()(mpz_get_str(NULL, 10, quadraticResidue.Prime)));
	  }
  };
}

#endif
