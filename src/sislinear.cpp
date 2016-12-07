#include "../header/sislinear.h"

SisLinear::SisLinear(){

}

bool SisLinear::pivotear(std::vector<std::vector<double> > mat, std::vector<double> p, int i){
	int r;
	double pivo, aux1;
	std::vector<double> aux2;

	pivo = abs(mat[i][i]);
	r = i;
	for(int j = i+1; j < mat.size(); j++){
		if(abs(mat[j][i]) > pivo){
			pivo = abs(mat[j][i]);
			r = i;
		}
	}

	if(pivo == 0)
		return false;

	if(r != i){
		aux2 = mat[i];
		mat[i] = mat[r];
		mat[r] = aux2;

		aux1 = p[i];
		p[i] = p[r];
		p[r] = aux1;
	}
	
	return true;
}

std::vector<std::vector<double> > SisLinear::lu(std::vector<std::vector<double> > a){
	double mult;
	std::vector<double> p;

	for(int i = 0; i < a.size(); i++)
		p.push_back(i);

	for(int i = 0; i < a.size()-1; i++){
		
		pivotear(a, p, i);

		for(int j = i+1; j < a.size(); j++){
			mult = a[j][i]/a[i][i];
			for(int k = i; k < a.size(); k++)
				a[j][k] = a[j][k] - mult*a[i][k];
			a[j][i] = mult;
		}
	}

	return a;
}