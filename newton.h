#include <vector>
#include <cmath>

class Newton{

public:
	Newton();
	double fun(double c, std::vector<double> a);
	std::vector<double> horner(double c, std::vector<double> a);
	double passoIterativo(double x, std::vector<double> a);
	double calcularRaiz(double x, std::vector<double> a, double e1, double e2);
	double calcularRaizSec(double x, std::vector<double> a, double e1, double e2);
};