#include "cout.h"

cout::cout(NRmatrix<double>* im, NRmatrix<double>* imRef, interpole* m_interpole, similarite* m_simil){
	Im=im;
	ImRef=imRef;
	meth_interpole=m_interpole;
	meth_simil=m_simil;
}

void cout::setIm(NRmatrix<double>* im){
	Im=im;
}

void cout::setImRef(NRmatrix<double>* imRef){
	ImRef=imRef;
}

void cout::setInterpole(interpole* m_interpole){
	meth_interpole=m_interpole;
}

void cout::setSimil(similarite* m_simil){
	meth_simil=m_simil;
}

double cout::operator() (VecDoub& param) const{
	int nbr_ligne=Im->nrows();
	int nbr_colonne=Im->ncols();
	
	NRmatrix<double> ImDef(nbr_ligne,nbr_colonne);
	NRmatrix<int> Mask(nbr_ligne,nbr_colonne);
	NRmatrix<int> Mask_ref(nbr_ligne,nbr_colonne,1);
	
	d.deforme(*Im, ImDef, Mask, param, *meth_interpole);
	
	return meth_simil->similaire(*ImRef,Mask_ref,ImDef,Mask);
}
