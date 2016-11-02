#include <vector>
#include <cmath>

class Newton{

public:
	Newton();
	double fun(double c, std::vector<double> a);
	std::vector<double> horner(double c, std::vector<double> a);
	double passoIter(double x, std::vector<double> a);
	double calcularRaiz(double x, std::vector<double> a, double e1, double e2);
	double calcularRaizS(double x0, double x1, std::vector<double>& a, double e1, double e2);
};