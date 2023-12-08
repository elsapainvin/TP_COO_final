#ifndef COUT_H
#define COUT_H

#include "nr3.h"
#include "transformation.h"
#include "interpole.h"
#include "deformation.h"
#include "similarite.h"

class cout {
	private : 
	NRmatrix<double>* Im;
	NRmatrix<double>* ImRef;
	interpole* meth_interpole;
	similarite* meth_simil;
	deformation d;
	
	public:
		cout(NRmatrix<double>* im, NRmatrix<double>* imRef, interpole* m_interpole, similarite* m_simil);
		void setIm(NRmatrix<double>* im);
		void setImRef(NRmatrix<double>* imRef);
		void setInterpole(interpole* m_interpole);
		void setSimil(similarite* m_simil);
		double operator() (VecDoub& param) const;	
};

#endif
