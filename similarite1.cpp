#include <iostream>
#include "similarite1.h"

// objectif : Ce code implémente une fonction similaire qui calcule la similarité entre deux images Im1 et Im2
                // en utilisant les pixels où les masques Mask1 et Mask2 sont tous deux non nuls. 

double similarite1::similaire(const NRmatrix<double>& Im1, const NRmatrix<double>& Mask1,const NRmatrix<double>& Im2,const NRmatrix<double>& Mask2) const
{
        double E=0; // somme des carrés des différences
        double compt=0; // compte le nb de pixels comparés
        int I=Im1.nrows();  // dimensions I et J des matrices
        int J=Im1.ncols(); 
        
        for (int i=0; i<I; i++) // on parcourt chaque pixel des images
        {
                for (int j=0; j<J; j+=1) 
                {
                        if (Mask1[i][j]&&Mask2[i][j]) // verif que les masques sont non nuls
                        {
                                E+=pow((Im2[i][j]-Im1[i][j]), 2);
                                compt+=1;    
                        }
                }       
        }
        return E/compt; // calcul de la similarité normalisée


        
}
