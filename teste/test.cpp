#include "../header/newton.h"
#include "../header/tabela.h"


int main(){
	double k;
	std::vector<double> a, interv;
	std::vector<std::vector<double> > resNr, resSec;

	/*
	a.push_back(1);
	a.push_back(-5);
	a.push_back(6);
	a.push_back(4);
	a.push_back(-8);
	std::cout << Newton::fun(-1, a) << std::endl;
	a.push_back(0);
	a.push_back(0);
	a.push_back(1);
	a.push_back(-1);
	a.push_back(1);
	a.push_back(-1);

	std::cout << Newton::calcularMult(a) << std::endl;
	Tabela::receberPolinomio();
	a.push_back(1);
	a.push_back(0);
	a.push_back(-9);
	a.push_back(3);

	//teste nZeros
	k = Newton::circulo(a);
	interv.push_back(-k);
	interv.push_back(k);
	interv = Newton::nZeros(interv, a, 0);
	//teste calcularRaiz
	resNr = Newton::calcularRaiz(0.5, a, 0.0001, 0.0001);
	resSec = Newton::calcularRaizSec(0, 0.5, a, 0.0001, 0.0001);
	Tabela::imprimirResultados(a, resNr, resSec);


	resNr = Newton::calcularRaiz((interv[0]+interv[1])/2, a, 0.0001, 0.0001);
	resSec = Newton::calcularRaizSec(interv[0], (interv[0]+interv[1])/2, a, 0.0001, 0.0001);
	Tabela::imprimirResultados(a, resNr, resSec);	
	std::cin >> k;
	a.clear();

	resNr.clear();
	resSec.clear();
	resNr = Newton::calcularRaiz(0.5, a, 0.0001, 0.0001);
	resSec = Newton::calcularRaizSec(1, 1.5, a, 0.0001, 0.0001);
*/
}