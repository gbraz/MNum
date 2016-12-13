#ifndef TABELA_H
#define TABELA_H
#include <iostream>
#include <vector>
#include <stdio.h>	//printf 
#include <stdlib.h> //system
#include "../header/newton.h"
#include "../header/sislinear.h"
#include "../header/doolittle.h"



class Tabela{
private:
	Tabela();
public:
	static void receberAb();
	static void receberPolinomio();
	static void imprimirResultados(std::vector<double>, std::vector<std::vector<double> >, std::vector<std::vector<double> >);
};

#endif // TABELA_H