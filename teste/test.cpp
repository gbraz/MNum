#include "../header/newton.h"
#include "../header/tabela.h"


int main(){
	double k;
	std::vector<double> a, interv;
	std::vector<std::vector<double> > resNr, resSec;
	a.push_back(1);
	a.push_back(0);
	a.push_back(-9);
	a.push_back(3);
	
	//teste nZeros
	k = Newton::circulo(a);
	interv.push_back(-k);
	interv.push_back(k);
	std::cout << "interv[0]: " << interv[0] << "; interv[1]: " << interv[1] << std::endl;
	interv = Newton::nZeros(interv, a, 0);
	std::cout << "K:" << k << std::endl;
	std::cin >> k;

	//teste calcularRaiz
	resNr = Newton::calcularRaiz(0.5, a, 0.0001, 0.0001);
	resSec = Newton::calcularRaizSec(0, 0.5, a, 0.0001, 0.0001);
	
	Tabela::imprimirResultados(resNr, resSec);

	a.clear();
	a.push_back(1);
	a.push_back(-5);
	a.push_back(6);
	a.push_back(4);
	a.push_back(-8);

	resNr.clear();
	resSec.clear();
	resNr = Newton::calcularRaiz(0.5, a, 0.0001, 0.0001);
	resSec = Newton::calcularRaizSec(1, 1.5, a, 0.0001, 0.0001);
	Tabela::imprimirResultados(resNr, resSec);

}