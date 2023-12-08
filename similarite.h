#ifndef SIMILARITE_H
#define SIMILARITE_H

#include "nr3.h"

class similarite{
	public:
		virtual double similaire(const NRmatrix<double>& Im1, const NRmatrix<int>& Mask1,const NRmatrix<double>& Im2,const NRmatrix<int>& Mask2) const =0;	
};

#endif
