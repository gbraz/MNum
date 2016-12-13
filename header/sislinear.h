#ifndef SISLINEAR_H
#define SISLINEAR_H
#include <vector>
#include <iostream>
#include <stdlib.h>

class SisLinear {

public:
	SisLinear();
	static bool pivotear (std::vector<std::vector<double> >&, std::vector<double>&, int);
	static std::vector<std::vector<double> > gerarLU(std::vector<std::vector<double> >);
	static std::vector<double> usarLU(std::vector<std::vector<double> >, std::vector<double>);
	static std::vector<double> calcularLU(std::vector<std::vector<double> >, std::vector<double>);
};

#endif // SISLINEAR_H