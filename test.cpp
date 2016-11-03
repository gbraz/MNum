#include "newton.h"
#include "tabela.h"


int main(){
	Newton n;

	std::vector<double> a;
	std::vector<std::vector<double> > resNr, resSec;
	a.push_back(1);
	a.push_back(0);
	a.push_back(-9);
	a.push_back(3);

	resNr = n.calcularRaiz(0.5, a, 0.0001, 0.0001);
	resSec = n.calcularRaizSec(0, 0.5, a, 0.0001, 0.0001);
	
	Tabela t;
	t.imprimirResultados(resNr, resSec);

	a.clear();
	a.push_back(1);
	a.push_back(-5);
	a.push_back(6);
	a.push_back(4);
	a.push_back(-8);

	resNr.clear();
	resSec.clear();
	resNr = n.calcularRaiz(0.5, a, 0.0001, 0.0001, 3);
	resSec = n.calcularRaizSec(1, 1.5, a, 0.0001, 0.0001, 3);
	t.imprimirResultados(resNr, resSec);

}