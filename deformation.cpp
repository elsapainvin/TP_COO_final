#include "deformation.h"

// cette fonction prend une image en entrée, applique une transformation définie par les paramètres param,
// interpole les valeurs déformées à l'aide de la méthode spécifiée par meth_interpole,
// et stocke les résultats dans deux matrices de sortie :
//resDeforme pour les valeurs déformées et resMask pour les masques indiquant la validité des coordonnées déformées.


void deformation::deforme(const NRmatrix<double>& Im, NRmatrix<double>& resDeforme, NRmatrix<int>& resMask, VecDoub& param, const interpole& meth_interpole) const{
	
	int nbr_ligne=Im.nrows(); //dimensions de l'image
	int nbr_colonne=Im.ncols();
	for (int i=0;i<nbr_ligne;i++){ //on parcourt l'image d'entrée
		for (int j=0;j<nbr_colonne;j++){
			double iprime, jprime;
			int valeur_mask;
			double valeur_imDeforme;
			t.transforme(param,i,j,&iprime,&jprime); // t est une instance de déformation et on obtient
								// les coord déformées (iprime, jprime)
			valeur_imDeforme=meth_interpole.interpolation(Im,iprime,jprime,&valeur_mask); // verif si les coord déformées sont dans l'image
			resDeforme[i][j]=valeur_imDeforme; // on stocke les résultats 
			resMask[i][j]=valeur_mask;
		}
	}
}
