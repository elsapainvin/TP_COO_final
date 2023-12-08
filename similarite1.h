#ifndef SIMILARITE1_H
#define SIMILARITE1_H

#include "nr3.h"
#include "similarite.h"

class similarite1 : public similarite{
	public:
		virtual double similaire(const NRmatrix<double>& Im1, const NRmatrix<double>& Mask1,const NRmatrix<double>& Im2,const NRmatrix<double>& Mask2) const;	
};

#endif
