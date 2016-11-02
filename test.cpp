#include <iostream>
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

	std::cout<< "f(0.5) = " << n.fun(0.5, a) << std::endl;

	resNr = n.calcularRaiz(0.5, a, 0.0001, 0.0001);
	resSec = n.calcularRaizSec(0, 0.5, a, 0.0001, 0.0001);
	
	Tabela t;
	t.imprimirResultados(resNr, resSec);
}