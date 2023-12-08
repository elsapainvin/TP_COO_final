#include "interpole1.h"
#include <iostream>
#include <math.h> 

// Objectif : effectuer une interpolation bilinéaire pour estimer la valeur d'un point dans une image,
// en utilisant les pixels voisins.

//La fonction prend en entrée une matrice d'image Image de type NRmatrix<double>,
//les coordonnées x et y du point à interpoler,
//et un pointeur OK qui est utilisé pour indiquer si l'opération d'interpolation a réussi.

 double interpole1::interpolation(const NRmatrix<double>& Image, double x, double y, int* OK) const{
 	int H=Image.nrows();
 	int L=Image.ncols();
 	if ( (x<0) || (x>H-1) || (y<0) || (y>L-1)){ //verif si (x,y) sont dans le support de l'image
 		*OK=0; // on ne peut pas interpoler car le point n'est pas dans le support de l'image.
 		return 0;
 	}

	else{
		int i1 , i2 , j1 , j2 ;
		double dx,dy,dfy,dfx,dfxy,res ;
	
		//On calcule les indices des pixels voisins (i1, j1), (i1, j2), (i2, j1), et (i2, j2) dans la matrice Image.
		//Les indices sont obtenus en arrondissant vers le bas (floor) les coordonnées (x, y).
		i1 = floor(x);
		j1 = floor(y);
	
		if (i1==H-1){
			i1--;
		}
	
		if (j1==L-1){
			j1--;
		}
	
		i2 = i1+1 ;
		j2 = j1+1 ;

		//calcul des coefficients d'interpolation
		dx = x - i1;
		dy = y - j1;
		dfx = Image[ i2 ][ j1]-Image[ i1 ][ j1 ];
		dfy = Image[ i1 ][ j2]-Image[ i1 ][ j1 ];
		dfxy = Image[ i1 ][ j1]+Image[ i2 ][ j2 ]-Image[ i2 ][ j1 ]-Image[ i1 ][ j2 ];
	
		// Calcul de la valeur interpolée
		res = Image[i1 ][ j1 ] + dfx * dx + dfy * dy + dx * dy * dfxy;
		*OK=1;
		return res;
	}	
}
