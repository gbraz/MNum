#ifndef TABELA_H
#define TABELA_H
#include <iostream>
#include <vector>
#include <stdio.h>	//printf 
#include <stdlib.h> //system

class Tabela{
private:
	Tabela();
public:
	static void imprimirResultados(std::vector<double>, std::vector<std::vector<double> >, std::vector<std::vector<double> >);
};

#endif // TABELA_H