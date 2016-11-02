#include <vector>
#include <cmath>

class Newton{

public:
	Newton();
	double fun(double c, std::vector<double> a);
	std::vector<double> horner(double c, std::vector<double> a);
	double passoIter(double x, std::vector<double> a, std::vector<std::vector<double> >& res);
	void salvarResSec(double x, double fx, std::vector<std::vector<double> >& res);
	std::vector<std::vector<double> > calcularRaiz(double x, std::vector<double> a, double e1, double e2);
	std::vector<std::vector<double> > calcularRaizSec(double x0, double x1, std::vector<double> a, double e1, double e2);
};