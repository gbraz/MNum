#include "newton.h"
#include <iostream>
Newton::Newton(){

}


double Newton::fun(double c, std::vector<double> a){
	double b;

	for(int i = 1; i < a.size(); i++) //Método de Horner
		b = b*c + a[i];

	return b;
}

std::vector<double> Newton::horner(double c, std::vector<double> a){
	double b = a[0], d = b;
	std::vector<double> f;
	
	for(int i = 1; i < a.size(); i++){ //Método de Horner
		b = b*c + a[i];
		d = d*c + b;
	}

	f.push_back(b);
	f.push_back(d);
	return f;
}

double Newton::passoIterativo(double x, std::vector<double> a){
	std::vector<double> f;

	f = horner(x, a);

	return x - f[0]/f[1];
}


double Newton::calcularRaiz(double x, std::vector<double> a, double e1, double e2){
	double xk, fk;

	do{
		xk = x;
		x = passoIterativo(xk, a);

	}while (std::abs(x - xk) > e1 || std::abs(fun(x, a)) > e2);
	
	return x;
}


/*double NewtonRaphson::calcularRaizSec(double x, std::vector<double> a, double e1, double e2){
	double  s, xk, fx, fxk = 999;
	std::vector<double> h;
	xk = x;
	x = 0;
	while (std::abs(x - xk) > e1 || std::abs(fxk) > e2){
		fx = fun(x, a, h);
		h.clear();
		fxk = fun(xk, a, h);
		h.clear();
		std::cout << "fk " << fxk << " fx " << fx << std::endl;
		s = xk;
		xk = xk - fxk*(xk - x)/(fxk - fx);
		x = s;
	}
	
	return xk;
}
*/