#ifndef NEWTON_H
#define NEWTON_H
#include <vector>
#include <cmath> //abs()
#include <iostream>

class Newton{
private:
	Newton();
	static std::vector<double> horner(double c, std::vector<double> a);
	static double passoIter(double x, std::vector<double> a, std::vector<std::vector<double> >& res, int p);
	static void salvarResSec(double x, double fx, std::vector<std::vector<double> >& res);

public:
	static double fun(double c, std::vector<double> a);

    static void escrevePolinomio(std::vector<double> a);
	static std::vector<std::vector<double> > calcularRaiz(double x, std::vector<double> a, double e1, double e2, int maxIter, int p = 1);
	static std::vector<std::vector<double> > calcularRaizSec(double x0, double x1, std::vector<double> a, double e1, double e2, int maxIter, int p = 1);
    static bool calcularMult(std::vector<double> a, std::vector<std::vector<std::vector<double> > >& res,double e1, double e2, int p);

	static double circulo(std::vector<double> a);
	static std::vector<double> divisaoPolinomio(std::vector<double> a, std::vector<double> b);
	static int Sturn(std::vector<double> a, double alpha, double betha);
	static std::vector<double> nZeros(std::vector<double> I, std::vector<double> a, int i);
};

#endif // NEWTON_H
