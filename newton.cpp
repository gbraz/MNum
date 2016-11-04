#include "newton.h"


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

double Newton::passoIter(double x, std::vector<double> a, std::vector<std::vector<double> >& res, int p){
	std::vector<double> f, iteracao;

	f = horner(x, a);

	iteracao.push_back(x);	//Armazenando os resultados da iteração
	iteracao.push_back(f[0]);
	iteracao.push_back(f[1]);
	res.push_back(iteracao);

	return x - p*f[0]/f[1];
}



std::vector<std::vector<double> > Newton::calcularRaiz(double x, std::vector<double> a, double e1, double e2, int p){ //p é um parâmetro opcional, default 1
	double xk, f;
	std::vector<std::vector<double> > res;

	do{
		xk = x;
		x = passoIter(xk, a, res, p);

	}while (std::abs(x - xk) > e1 && std::abs(fun(x, a)) > e2);
	
	passoIter(x, a, res, p);

	return res;
}

void Newton::salvarResSec(double x, double fx, std::vector<std::vector<double> >& res){ //Armazena os resultados da iteração
	std::vector<double> iteracao;

	iteracao.push_back(x);
	iteracao.push_back(fx);
	res.push_back(iteracao);
}


std::vector<std::vector<double> > Newton::calcularRaizSec(double x0, double x1, std::vector<double> a, double e1, double e2, int p){
	double f0, f1, temp;
	std::vector<std::vector<double> > res;
	
	f0 = fun(x0, a);
	salvarResSec(x0, f0, res); //Armazenando os resultados no vetor res
	f1 = fun(x1, a);
	salvarResSec(x1, f1, res); 
	
	do{
		temp = x1;
		x1 = x1 - p*f1*(x1 - x0)/(f1 - f0);
		x0 = temp;
		f0 = f1;
		f1 = fun(x1, a);
		salvarResSec(x1, f1, res);
	}while(std::abs(x0 - x1) > e1 && std::abs(f1) > e2);
	
	return res;
}