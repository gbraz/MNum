#include "tabela.h"
#include <iomanip>
#include <stdio.h>

Tabela::Tabela(){

}

void Tabela::imprimirResultados(std::vector<std::vector<double> > v1, std::vector<std::vector<double> > v2){
	
	std::cout << "+----------------Newton-Raphson---------------------+" << std::endl; //Imprime tabela pro método de NR
	std::cout << "+---+---------------+---------------+---------------+" << std::endl;
	std::cout << "| k |      xk       |      f(xk)    |      f'(xk)   |" << std::endl;
	std::cout << "+---+---------------+---------------+---------------+" << std::endl;
	for(int i = 0; i < v1.size(); i++)	
		printf("|%3d|%15.10f|%15.10f|%15.10f|\n", i, v1[i][0], v1[i][1], v1[i][2]);
	std::cout << "+---+---------------+---------------+---------------+" << std::endl;
	std::cout << std::endl << std::endl;;
	
	std::cout << "+-------------Secante---------------+" << std::endl; //Imprime tabela pro método de Sec
	std::cout << "+---+---------------+---------------+" << std::endl;
	std::cout << "| k |      xk       |     f(xk)     |" << std::endl;
	std::cout << "+---+---------------+---------------+" << std::endl;
	for(int i = 0; i < v2.size(); i++)	
		printf("|%3d|%15.10f|%15.10f|\n", i, v2[i][0], v2[i][1]);
	std::cout << "+---+---------------+---------------+" << std::endl;
}