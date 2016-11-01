#include <vector>
#include <cmath>

class NewtonRaphson{

public:
	NewtonRaphson();
	double fun(double c, std::vector<double>& a, std::vector<double>& h);
	double funD(double c, std::vector<double> h);
	double passoIterativo(double x, std::vector<double> a);
	double calcularRaiz(double x, std::vector<double> a, double e1, double e2);
	double calcularRaizSec(double x, std::vector<double> a, double e1, double e2);
};