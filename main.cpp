#include "interpole1.h"
#include "interpole2.h"
#include "similarite1.h"
#include "cout.h"
#include "amoeba.h"
#include <fstream>
#include <ostream>
#include <iostream>
#include <cmath> 

void saveImage(string adresse_fichier,NRmatrix<double> Image);
NRmatrix<double> loadImage(string adresse_fichier);

void saveImage(string adresse_fichier,NRmatrix<double> Image){
	std::ofstream ecriture(adresse_fichier);
	if (!ecriture.fail() ){
		ecriture << "P2 ";
		ecriture << Image.ncols()<<" ";
		ecriture << Image.nrows()<<" ";
		ecriture << 255 <<std::endl;
		for (int i=0;i<Image.nrows();i++){
			for (int j=0;j<Image.ncols();j++){
				ecriture << Image[i][j]<< " ";
			}
			ecriture << std::endl;
		}
		ecriture.close();
	}
}

NRmatrix<double> loadImage(string adresse_fichier){
	std::ifstream lecture(adresse_fichier);
	if (!lecture.fail() ){
		char poubelle1;
		int nbr_lignes ,nbr_colonnes, poubelle2;
		
		
		lecture >> poubelle1;
		lecture >> poubelle2;
		lecture >> nbr_colonnes;
		lecture >> nbr_lignes;
		lecture >> poubelle2;
		
		NRmatrix<double> Image(nbr_lignes, nbr_colonnes);
		
		for (int i=0;i<nbr_lignes;i++){
			for (int j=0;j<nbr_colonnes;j++){
				lecture >> Image[i][j];
			}
		}
		lecture.close();
		
		return Image;
	}
}

int main(void){
	
	NRmatrix<double> Imref=loadImage("../Images/reference.pgm");
	NRmatrix<double> Im=loadImage("../Images/floating.pgm");
	
	interpole1 CRISTIANO;
	interpole2 SUUUUU;
	transformation MESSIII;
	deformation PAVAAAAAAAAAARD;
	
	NRmatrix<double> test(3,3,1);
	double compte=1;
	for (int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			test[i][j]=compte;
			compte++;
		}
	}
	int OK;
	double valeur;
	
	VecDoub parametre(3);
	parametre[0]=2;
	parametre[1]=0;
	parametre[2]=90;
	
	NRmatrix<int> masque(3,3);
	NRmatrix<double> image_deformee(3,3);
	PAVAAAAAAAAAARD.deforme(test,image_deformee,masque,parametre,SUUUUU);
	
	for (int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			std::cout << image_deformee[i][j] << " ";
		}
		std::cout << std::endl;
	}
	
	
	saveImage("../Images/Test_sauvegarde_ref.pgm",Imref);
	saveImage("../Images/Test_sauvegarde_image.pgm",Im);
	
	std::cout<<"Finito pipo"<<std::endl;
	
	return 0;
}
