#include <vector>
#include <cmath> //abs()
#include <iostream>

class Newton{
private:
	Newton();
	static double fun(double c, std::vector<double> a);
	static std::vector<double> horner(double c, std::vector<double> a);
	static double passoIter(double x, std::vector<double> a, std::vector<std::vector<double> >& res, int p);
	static void salvarResSec(double x, double fx, std::vector<std::vector<double> >& res);

public:
	static std::vector<std::vector<double> > calcularRaiz(double x, std::vector<double> a, double e1, double e2, int p = 1);
	static std::vector<std::vector<double> > calcularRaizSec(double x0, double x1, std::vector<double> a, double e1, double e2, int p = 1);
	
	double circulo(std::vector<double> a);
	std::vector<double> divisaoPolinomio(std::vector<double> a, std::vector<double> b);
	int Sturn(std::vector<double> a, double alpha, double betha);
	std::vector<double> nZeros(std::vector<double> I, std::vector<double> a, int i);
};