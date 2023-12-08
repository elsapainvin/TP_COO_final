#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include "nr3.h"

class transformation{
	public:
		void transforme(VecDoub& param, double x, double y, double* x_res, double* y_res) const;	
		//ordre des paramètres dans param : tx, ty, théta
};

#endif
