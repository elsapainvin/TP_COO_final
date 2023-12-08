#include <iostream>
#include "similarite1.h"

double similarite1::similaire(const NRmatrix<double>& Im1, const NRmatrix<double>& Mask1,const NRmatrix<double>& Im2,const NRmatrix<double>& Mask2) const
{
        double E=0;
        double compt=0;
        int I=Im1.nrows(); 
        int J=Im1.ncols(); 
        
        for (int i=0; i<I; i++)
        {
                for (int j=0; j<J; j+=1) 
                {
                        if (Mask1[i][j]&&Mask2[i][j])
                        {
                                E+=pow((Im2[i][j]-Im1[i][j]), 2);
                                compt+=1;    
                        }
                }       
        }
        return E/compt;
}
