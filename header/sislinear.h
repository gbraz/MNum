#include <vector>
#include <iostream>
#include <stdlib.h>

class SisLinear {

public:
	SisLinear();
	bool pivotear (std::vector<std::vector<double> >&, std::vector<double>&, int);
	std::vector<std::vector<double> > gerarLU(std::vector<std::vector<double> >);
	std::vector<double> usarLU(std::vector<std::vector<double> >, std::vector<double>);
	std::vector<double> calcularLU(std::vector<std::vector<double> >, std::vector<double>);
};