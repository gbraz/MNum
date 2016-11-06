#include "../header/tabela.h"

Tabela::Tabela(){

}

/*Imprime uma tabela para as iterações de Newton-Raphson e outra para Secante
  Entradas: std::vector<std::vector<double> > m1 - matriz dos resultados de Newton-Raphson
  			std::vector<std::vector<double> > m2 - matriz dos resultados do método da Secante*/
void Tabela::imprimirResultados(std::vector<std::vector<double> > m1, std::vector<std::vector<double> > m2){
	
	system("clear");
	std::cout << "+----------------Newton-Raphson---------------------+" << std::endl; //Imprime tabela pro método de NR
	std::cout << "+---+---------------+---------------+---------------+" << std::endl;
	std::cout << "| k |      xk       |      f(xk)    |      f'(xk)   |" << std::endl;
	std::cout << "+---+---------------+---------------+---------------+" << std::endl;
	for(int i = 0; i < m1.size(); i++)	
		printf("|%3d|%15.10f|%15.10f|%15.10f|\n", i, m1[i][0], m1[i][1], m1[i][2]);
	std::cout << "+---+---------------+---------------+---------------+" << std::endl;
	std::cout << std::endl << std::endl;;
	
	std::cout << "+-------------Secante---------------+" << std::endl; //Imprime tabela pro método de Sec
	std::cout << "+---+---------------+---------------+" << std::endl;
	std::cout << "| k |      xk       |     f(xk)     |" << std::endl;
	std::cout << "+---+---------------+---------------+" << std::endl;
	for(int i = 0; i < m2.size(); i++)	
		printf("|%3d|%15.10f|%15.10f|\n", i, m2[i][0], m2[i][1]);
	std::cout << "+---+---------------+---------------+" << std::endl;
}