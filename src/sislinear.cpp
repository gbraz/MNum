#include "../header/sislinear.h"

SisLinear::SisLinear(){

}


/*Faz o pivoteamento de uma matriz 'mat', a partir da linha i 
  Entradas: vector<std::vector<double> >& mat- matriz dos coeficientes, passada por referência
            std::vector<double>& p - vetor com as posições trocadas das linhas da matriz 'mat'
            int i - linha que deve ser pivoteada
  Saída:    bool - false se a matriz é singular, true caso contrário
  Autor:    Geraldo Braz*/
bool SisLinear::pivotear(std::vector<std::vector<double> >& mat, std::vector<double>& p, int i){
	int r;
	double pivo, aux1;
	std::vector<double> aux2;

	pivo = abs(mat[i][i]);
	r = i;
	for(int j = i+1; j < mat.size(); j++){
		if(abs(mat[j][i]) > pivo){
			pivo = abs(mat[j][i]);
			r = j;
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


/*Gera uma matriz com os valores das matrizes L e U mais o vetor de pivoteamento na última linha
  Entradas: vector<std::vector<double> > a- matriz dos coeficientes do sistema linear
  Saída:    vector<std::vector<double> > - matriz com LU, a última linha corresponde às permutações feitas
  Autor:    Geraldo Braz*/
std::vector<std::vector<double> > SisLinear::gerarLU(std::vector<std::vector<double> > a){
	double mult;
	std::vector<double> p;

	for(int i = 0; i < a.size(); i++)
		p.push_back(i);

	for(int i = 0; i < a.size()-1; i++){
		if(!pivotear(a, p, i))
			throw std::runtime_error("Matriz é singular");

		for(int j = i+1; j < a.size(); j++){
			mult = a[j][i]/a[i][i];
			for(int k = i; k < a.size(); k++)
				a[j][k] = a[j][k] - mult*a[i][k];
			a[j][i] = mult;
		}
	}

	a.push_back(p);

	return a;
}