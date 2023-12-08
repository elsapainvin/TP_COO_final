#ifndef INTERPOLE1_H
#define INTERPOLE1_H

#include "nr3.h"
#include "interpole.h"

class interpole1 : public interpole{
	public:
		virtual double interpolation(const NRmatrix<double>& Image, double x, double y, int* OK) const;	
};

#endif
