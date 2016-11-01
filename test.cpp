#include <iostream>
#include "newton.h"


int main(){
	Newton n;

	std::vector<double> a, h;
	a.push_back(0);
	a.push_back(1);
	a.push_back(0);
	a.push_back(-9);
	a.push_back(3);

	std::cout<< "f(0.5) = " << n.fun(0.5, a) << std::endl;
	//std::cout<< h[0] << h[1] << h[2] << h[3] << std::endl;
	//std::cout<< "f'(0.5) = " << n.funD(0.5, h) << std::endl;
	std::cout<< "x1 = " << n.passoIterativo(0.5, a) << std::endl;
	std::cout<< "raiz = " << n.calcularRaiz(0.5, a, 0.0001, 0.0001) << std::endl;
	//std::cout<< "raiz = " << n.calcularRaizSec(0.5, a, 0.0001, 0.0001) << std::endl;
}