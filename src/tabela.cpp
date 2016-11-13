#include "../header/tabela.h"
#include "../header/newton.h"

Tabela::Tabela(){

}
/*Interface simples para entrada de coeficientes
  Autor:    Geraldo Braz*/
void Tabela::receberPolinomio(){
	int p, n = 0;
	double coef, e1 = 0.0001, e2 = 0.0001;
	std::vector<int> mult;
	std::vector<double> a;
	std::vector< std::vector<double> > reac;
	std::vector<std::vector<std::vector<double> > > res;

	while(n < 1){
		system("clear");
		std::cout << "+----------------Newton-Raphson---------------------+" << std::endl; 
		std::cout << std::endl << std::endl;
		std::cout << "Insira o número de reações:"; 
		std::cin >> n;
	}
	for(int i = 0; i < n; i++){
		system("clear");
		std::cout << "+----------------Newton-Raphson---------------------+" << std::endl; 
		std::cout << "a4:";
		std::cin >> coef;
		a.push_back(coef);
		std::cout << "a3:";
		std::cin >> coef;
		a.push_back(coef);
		std::cout << "a2:";
		std::cin >> coef;
		a.push_back(coef);
		std::cout << "a1:";
		std::cin >> coef;
		a.push_back(coef);
		std::cout << "a0:";
		std::cin >> coef;
		a.push_back(coef);
		reac.push_back(a);	
		std::cout << "Multiplicidade:";
		std::cin >> p;
		mult.push_back(p);
	}
	system("clear");
	
	for(int i = 0; i < n; i++){
		std::cout << "+----------------Reação " << i+1  << "---------------------+"<< std::endl; 
		p = mult[i];
		a = reac[i];
		if(Newton::calcularMult(a, res, e1, e2, p))
			Tabela::imprimirResultados(a, res[0], res[1]);
		else
			std::cout << "Não converge" << std::endl;
		std::cout << std::endl << std::endl; 
	}

}

/*Imprime uma tabela para as iterações de Newton-Raphson e outra para Secante
  Entradas: std::vector<std::vector<double> > m1 - matriz dos resultados de Newton-Raphson
  			std::vector<std::vector<double> > m2 - matriz dos resultados do método da Secante*
  Autor:    Geraldo Braz*/
void Tabela::imprimirResultados(std::vector<double> a, std::vector<std::vector<double> > m1, std::vector<std::vector<double> > m2){
	
	std::cout << "Polinômio: ";
	for(int i = 0; i < a.size()-1; i++)	
		if((i == 0) || (a[i] < 0))
			std::cout << a[i] << "x^" << a.size()-i-1 << " ";
		else
			if(a[i] > 0)
				std::cout << "+" << a[i] << "x^" << a.size() -i-1 << " "; 
				
	if(a[a.size()-1] < 0)
		std::cout << a[a.size()-1];
	else
		if(a[a.size()-1] > 0)
			std::cout << "+" << a[a.size()-1];
	std::cout << std::endl;


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