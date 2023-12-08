#include "deformation.h"

void deformation::deforme(const NRmatrix<double>& Im, NRmatrix<double>& resDeforme, NRmatrix<int>& resMask, VecDoub& param, const interpole& meth_interpole) const{
	int nbr_ligne=Im.nrows();
	int nbr_colonne=Im.ncols();
	for (int i=0;i<nbr_ligne;i++){
		for (int j=0;j<nbr_colonne;j++){
			double iprime, jprime;
			int valeur_mask;
			double valeur_imDeforme;
			t.transforme(param,i,j,&iprime,&jprime);
			valeur_imDeforme=meth_interpole.interpolation(Im,iprime,jprime,&valeur_mask);
			resDeforme[i][j]=valeur_imDeforme;
			resMask[i][j]=valeur_mask;
		}
	}
}
