#include "../header/newton.h"
#include "../header/tabela.h"


int main(){
	double k;
	std::vector<double> a, interv;
	std::vector<std::vector<double> > resNr, resSec;
	std::vector<std::vector<std::vector<double> > > res;
	int iterMax = 200, p;
	double chute1= -1, chute2 = -1, f1,f2, e1 = 0.0001, e2 =0.0001;

	Tabela::receberPolinomio();
	/*
	a.push_back(1);
	a.push_back(0);
	a.push_back(-9);
	a.push_back(3);
	p = 1;
	a.push_back(1);
	a.push_back(-5);
	a.push_back(6);
	a.push_back(4);
	a.push_back(-8);
	p = 3;
	a.push_back(1);
	a.push_back(-8);
	a.push_back(16);
	a.push_back(-16);
	a.push_back(16);
	p=1;
	*/
	/*
	a.push_back(1);
	a.push_back(-.5);
	a.push_back(-.5);
	a.push_back(0);
	a.push_back(0);
	p=2;
	a.push_back(1);
	a.push_back(-8);
	a.push_back(24);
	a.push_back(-32);
	a.push_back(16);
	p=4;
	*/
	/*
	k = Newton::circulo(a);
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
	for(int i = 0; i < interv.size() - 1; i++){
    	std::cout << "chute1:" << chute1 << std::endl;
        chute1 =(interv[i]+interv[i+1])/2;
        std::cout <<"interv "<< i << ":" << interv[i] << std::endl;;
        std::cout <<"interv i+1:" << interv[i+1] << std::endl;
        std::cout <<"interv 2:" << (interv[i] + interv[i+1])/2 << std::endl;
        chute2 = (chute1 + interv[i+1])/2;
    
        resNr = Newton::calcularRaiz(chute1, a, e1, e2, iterMax, 1);
        f1 = Newton::fun(chute1, a);
        f2 = Newton::fun(chute2, a);
        std::cout << "chute1:" << chute1 << std::endl;
        std::cout << "chute2:" << chute2 << std::endl;
		std::cin >> k;
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
	if(Newton::calcularMult(a, res, e1, e2, p))
		Tabela::imprimirResultados(a, res[0], res[1]);
	else
		std::cout << "Não converge" << std::endl;
		*/
}