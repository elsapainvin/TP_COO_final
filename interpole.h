#ifndef INTERPOLE_H
#define INTERPOLE_H

#include "nr3.h"

class interpole{
	public:
		virtual double interpolation(const NRmatrix<double>& Image, double x, double y, int* OK) const =0;	
};

#endif
