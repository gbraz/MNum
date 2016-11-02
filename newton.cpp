#include "newton.h"
#include <iostream>

Newton::Newton(){

}


double Newton::fun(double c, std::vector<double> a){
	double b;

	for(int i = 0; i < a.size(); i++) //Método de Horner
		b = b*c + a[i];

	return b;
}

std::vector<double> Newton::horner(double c, std::vector<double> a){
	double b = a[0], d = a[0];
	std::vector<double> f;
	
	for(int i = 1; i < a.size(); i++){ //Método de Horner
		b = b*c + a[i];
		if(i < a.size() - 1)
			d = d*c + b;
	}

	f.push_back(b);
	f.push_back(d);
	return f;
}

double Newton::passoIter(double x, std::vector<double> a, std::vector<std::vector<double> >& res){
	std::vector<double> f, iteracao;

	f = horner(x, a);

	iteracao.push_back(x);	//armazenando os resultados da iteração
	iteracao.push_back(f[0]);
	iteracao.push_back(f[1]);
	res.push_back(iteracao);

	return x - f[0]/f[1];
}

std::vector<std::vector<double> > Newton::calcularRaiz(double x, std::vector<double> a, double e1, double e2){
	double xk, fk;
	std::vector<std::vector<double> > res;

	do{
		xk = x;
		x = passoIter(xk, a, res);

	}while (std::abs(x - xk) > e1 || std::abs(fun(x, a)) > e2);
	std::cout << "test" << x << std::endl;
	return res;
}


std::vector<std::vector<double> > Newton::calcularRaizSec(double x0, double x1, std::vector<double> a, double e1, double e2){
	double f0, f1, temp;
	//std::vector<std::vector<double> > res;
	std::vector<double> linha;
	std::vector<std::vector<double> > res;
	f0 = fun(x0, a);
	f1 = fun(x1, a);
	
	linha.push_back(x0); //armazenando os resultados para o vetor res
	linha.push_back(f0);
	res.push_back(linha);
	linha.clear();
	linha.push_back(x1);
	linha.push_back(f1);
	res.push_back(linha);
	linha.clear();

	do{
		temp = x1;
		x1 = x1 - f1*(x1 - x0)/(f1 - f0);
		x0 = temp;
		f0 = f1;
		f1 = fun(x1, a);
		linha.push_back(x1);
		linha.push_back(f1);
		res.push_back(linha);
		linha.clear();
	}while(std::abs(x0 - x1) > e1 || std::abs(f1) > e2);
	
	return res;
}