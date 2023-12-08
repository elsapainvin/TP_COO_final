#include "transformation.h"
#include <cmath>

void transformation::transforme(VecDoub& param, double x, double y, double* x_res, double* y_res) const{
	*x_res=cos(param[2]*(M_PI/180))*x-sin(param[2]*(M_PI/180))*y+param[0];
	*y_res=sin(param[2]*(M_PI/180))*x+cos(param[2]*(M_PI/180))*y+param[1];
}
