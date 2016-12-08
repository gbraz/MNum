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


/*Calcula o resultado de um sistema linear a partir de uma matriz LU e um vetor b
  Entradas: vector<std::vector<double> > lu - matriz com os resultados de LU e o vetor de permutações na última linha
  Saída:    vector<double> - resultado das variáveis
  Autor:    Geraldo Braz*/
std::vector<double> SisLinear::usarLU(std::vector<std::vector<double> > lu, std::vector<double> b){
	int r, tamanho;
	double soma;
	std::vector<double> c, y, x;

	tamanho = lu.size() - 1;

	for(int i = 0; i < tamanho; i++){
		r = lu[lu.size() - 1][i];
		c.push_back(b[r]);
	}

	for(int i = 0; i < tamanho; i++){
		soma = 0;
		for(int j = 0; j < i; j++)
			soma = soma + y[j]*lu[i][j];
		y.push_back(c[i] - soma);
	}

	x.resize(tamanho);
	for(int i = tamanho-1; i >= 0; i--){
		soma = 0;
		for(int j = i+1; j < tamanho; j++)
			soma = soma + x[j]*lu[i][j];
		x[i] = (y[i] - soma)/lu[i][i];
	}

	return x;
}