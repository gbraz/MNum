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
	static void imprimirResultados(std::vector<std::vector<double> > v1, std::vector<std::vector<double> > v2);
};

#endif // TABELA_H