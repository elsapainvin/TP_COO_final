#ifndef INTERPOLE2_H
#define INTERPOLE2_H

#include "nr3.h"
#include "interpole.h"

class interpole2 : public interpole{
	public:
		virtual double interpolation(const NRmatrix<double>& Image, double x, double y, int* OK) const;	
};

#endif
