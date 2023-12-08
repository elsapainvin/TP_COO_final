#ifndef DEFORMATION_H
#define DEFORMATION_H

#include "nr3.h"
#include "transformation.h"
#include "interpole.h"

class deformation {
	private : 
	transformation t;
	public:
		void deforme(const NRmatrix<double>& Im, NRmatrix<double>& resDeforme, NRmatrix<int>& resMask, VecDoub& param, const interpole& meth_interpole) const;	
};

#endif
