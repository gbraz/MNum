#include "../header/tabela.h"

Tabela::Tabela(){

}

void Tabela::receberPolinomio(){
	int n = 0;
	char c;
	std::vector<double> a;

	while(n < 1){
		system("clear");
		std::cout << "+----------------Newton-Raphson---------------------+" << std::endl; 
		std::cout << std::endl << std::endl;
		std::cout << "Insira o número de reações:"; 
		std::cin >> n;
		if(n < 1){
			std::cout<< "Quantidade inválida de reações. Pressione qualquer tecla para continuar:";
			//a = getchar();
		}
		else{
			std::cout << n;
			if(n > 1) 
				std::cout<< " reações. Confirmar?(s/n):";
			else 
				std::cout<< " reação. Confirmar?(s/n):";
			std::cin >> n;
		}
	}

}

/*Imprime uma tabela para as iterações de Newton-Raphson e outra para Secante
  Entradas: std::vector<std::vector<double> > m1 - matriz dos resultados de Newton-Raphson
  			std::vector<std::vector<double> > m2 - matriz dos resultados do método da Secante*/
void Tabela::imprimirResultados(std::vector<double> a, std::vector<std::vector<double> > m1, std::vector<std::vector<double> > m2){
	
	system("clear");
	std::cout << "Polinômio: ";
	for(int i = 0; i < a.size()-1; i++)	
		if((i == 0) || (a[i] < 0))
			std::cout << a[i] << "x^" << a.size()-i-1 << " ";
		else
			if(a[i] > 0)
				std::cout << "+" << a[i] << "x^" << a.size() -i-1 << " "; 
				
	if(a[a.size()-1] < 0)
		std::cout << a[a.size()-1] << std::endl;
	else
		std::cout << "+" << a[a.size()-1] << std::endl;

	std::cout << "+----------------Newton-Raphson---------------------+" << std::endl; //Imprime tabela pro método de NR
	std::cout << "+---+---------------+---------------+---------------+" << std::endl;
	std::cout << "| k |      xk       |      f(xk)    |      f'(xk)   |" << std::endl;
	std::cout << "+---+---------------+---------------+---------------+" << std::endl;
	for(int i = 0; i < m1.size(); i++)	
		printf("|%3d|%15.10f|%15.10f|%15.10f|\n", i, m1[i][0], m1[i][1], m1[i][2]);
	std::cout << "+---+---------------+---------------+---------------+" << std::endl;
	std::cout << "+-------------Secante---------------+" << std::endl; //Imprime tabela pro método de Sec
	std::cout << "+---+---------------+---------------+" << std::endl;
	std::cout << "| k |      xk       |     f(xk)     |" << std::endl;
	std::cout << "+---+---------------+---------------+" << std::endl;
	for(int i = 0; i < m2.size(); i++)	
		printf("|%3d|%15.10f|%15.10f|\n", i, m2[i][0], m2[i][1]);
	std::cout << "+---+---------------+---------------+" << std::endl;
	
	std::cout << std::endl << std::endl;;

}