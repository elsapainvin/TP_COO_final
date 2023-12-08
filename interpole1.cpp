#include "interpole1.h"
#include <iostream>
#include <math.h> 

/*calculer la valeur d’une image I pour des coordonnées non entières. Interpolation bilinéaire*/

 double interpole1::interpolation(const NRmatrix<double>& Image, double x, double y, int* OK) const{
 	int H=Image.nrows();
 	int L=Image.ncols();
 	if ( (x<0) || (x>H-1) || (y<0) || (y>L-1)){
 		*OK=0; // on ne peut pas interpoler car le point n'est pas dans le support de l'image.
 		return 0;
 	}

	else{
		int i1 , i2 , j1 , j2 ;
		double dx,dy,dfy,dfx,dfxy,res ;
	
		// floor permet d'arrondir valeur inférieure.
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

		dx = x - i1;
		dy = y - j1;
		dfx = Image[ i2 ][ j1]-Image[ i1 ][ j1 ];
		dfy = Image[ i1 ][ j2]-Image[ i1 ][ j1 ];
		dfxy = Image[ i1 ][ j1]+Image[ i2 ][ j2 ]-Image[ i2 ][ j1 ]-Image[ i1 ][ j2 ];
	
		// La valeur de I au point (x,y):
		res = Image[i1 ][ j1 ] + dfx * dx + dfy * dy + dx * dy * dfxy;
		*OK=1;
		return res;
	}	
}
