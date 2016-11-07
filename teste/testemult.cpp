#include "../header/newton.h"
#include "../header/tabela.h"


int main(){
	double k;
	std::vector<double> a, interv;
	std::vector<std::vector<double> > resNr, resSec;
	 std::vector<std::vector<std::vector<double> > > res;
	int chute1, chute2, f1,f2, iterMax = 200, p;
	double e1 = 0.0001, e2 =0.0001;

	a.push_back(1);
	a.push_back(0);
	a.push_back(-9);
	a.push_back(3);
	p = 1;
	/*
	a.push_back(1);
	a.push_back(-5);
	a.push_back(6);
	a.push_back(4);
	a.push_back(-8);
	p = 3
	*/
	/*
	k = Newton::circulo(a);
	interv.clear();
	interv.push_back(-k);
	interv.push_back(k);
	interv = Newton::nZeros(interv, a, 0);
	std::cout << std::endl;
	std::cout << "size:" << interv.size();
	for(int i = 0; i<interv.size(); i++)
		std::cout <<"; i:" << interv[i];
	std::cout << std::endl;
	std::cin >> k;
	bool flag = false;
	std::cout << "flag:" << flag << std::endl;
	std::cin >> k;
	for(int i = 0; i < interv.size() - 1; i++){
        chute1 =(interv[i]+interv[i+1])/2;
        chute2 = (chute1 + interv[i+1])/2;
        resNr = Newton::calcularRaiz(chute1, a, e1, e2, iterMax, 1);
        f1 = Newton::fun(chute1, a);
        f2 = Newton::fun(chute2, a);
        if(std::abs(f1) > std::abs(f2))
            resSec = Newton::calcularRaizSec(chute1, chute2, a, e1, e2, iterMax, 1);
        else 
            resSec = Newton::calcularRaizSec(chute2, chute1, a, e1, e2, iterMax, 1);
        if((resNr.size() < iterMax) && (resSec.size() < iterMax) && (std::abs(resNr[resNr.size() - 1][1]) < e2)){
            i = interv.size() + 5;
            flag = true;
        }
    }
    std::cout << "flag:" << flag << std::endl;
	std::cin >> k;
	Tabela::imprimirResultados(a, resNr, resSec);
	*/
	/*
		*/
	if(Newton::calcularMult(a, res, e1, e2, p))
		Tabela::imprimirResultados(a, res[0], res[1]);
	else
		std::cout << "Não converge" << std::endl;
}