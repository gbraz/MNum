#include <vector>
#include <cmath>

class Newton{
private:
	double fun(double c, std::vector<double> a);
	std::vector<double> horner(double c, std::vector<double> a);
	double passoIter(double x, std::vector<double> a, std::vector<std::vector<double> >& res, int p);
	void salvarResSec(double x, double fx, std::vector<std::vector<double> >& res);

public:
	Newton();
	std::vector<std::vector<double> > calcularRaiz(double x, std::vector<double> a, double e1, double e2, int p = 1);
	std::vector<std::vector<double> > calcularRaizSec(double x0, double x1, std::vector<double> a, double e1, double e2, int p = 1);
};