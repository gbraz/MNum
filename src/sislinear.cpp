#include "../header/sislinear.h"

SisLinear::SisLinear(){

}

std::vector<std::vector<double> > SisLinear::pivotear(std::vector<std::vector<double> > mat){
	for(int i = 0; i < mat.size(); i++){

	}
	return mat;
}

std::vector<std::vector<double> > SisLinear::lu(std::vector<std::vector<double> > a){
	double mult;

	for(int i = 0; i < a.size(); i++)
		for(int j = i+1; j < a.size(); j++){
			mult = a[j][i]/a[i][i];
			for(int k = i; k < a.size(); k++)
				a[j][k] = a[j][k] - mult*a[i][k];
			a[j][i] = mult;
		}

	return a;
}