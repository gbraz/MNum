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

double Newton::passoIter(double x, std::vector<double> a){
	std::vector<double> f;

	f = horner(x, a);

	return x - f[0]/f[1];
}


double Newton::calcularRaiz(double x, std::vector<double> a, double e1, double e2){
	double xk, fk;

	do{
		xk = x;
		x = passoIter(xk, a);

	}while (std::abs(x - xk) > e1 || std::abs(fun(x, a)) > e2);
	
	return x;
}


double Newton::calcularRaizSec(double x0, double x1, std::vector<double> a, double e1, double e2){
	double f0, f1, temp;

	f0 = fun(x0, a);
	f1 = fun(x1, a);
	
	do{
		temp = x1;
		x1 = x1 - f1*(x1 - x0)/(f1 - f0);
		x0 = temp;
		f0 = f1;
		f1 = fun(x1, a);
	}while(std::abs(x0 - x1) > e1 || std::abs(f1) > e2);
	
	return x1;
}
