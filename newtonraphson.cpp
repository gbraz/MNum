#include "newtonraphson.h"

NewtonRaphson::NewtonRaphson(){

}

double NewtonRaphson::fun(double c, std::vector<double>& a, std::vector<double>& h){
	h.push_back(a[0]);   //Método de Horner
	h.push_back(h[0]*c + a[1]);
	h.push_back(h[1]*c + a[2]);
	h.push_back(h[2]*c + a[3]);
	h.push_back(h[3]*c + a[4]);

	return h[4];
}

double NewtonRaphson::funD(double c, std::vector<double> h){
	return ((h[0]*c + h[1])*c + h[2])*c + h[3];
}

double NewtonRaphson::passoIterativo(double x, std::vector<double> a){
	std::vector<double> h;
	double fx, fdx;

	fx = fun(x, a, h);
	fdx = funD(x, h);

	return x - fx/fdx;
}

double NewtonRaphson::calcularRaiz(double x, std::vector<double> a, double e1, double e2){
	double xk;
	std::vector<double> h;

	do{
		xk = x;
		x = passoIterativo(xk, a);
		h.clear();

	}while (std::abs(x - xk) > e1 || std::abs(fun(x, a, h)) > e2);
	
	return x;
}