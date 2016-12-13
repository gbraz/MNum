#include "../header/tabela.h"

Tabela::Tabela(){

}

void Tabela::receberAb(){
	int n, aux;
	bool flag = false;
	char car;
	std::vector< std::vector<double> > A, LU, dl;
	std::vector<double> d, resultado1, resultado2;

	while(flag == false){
		system("clear");
		std::cout << "+----------------LU/Doolittle---------------------+" << std::endl;
		std::cout << "Entre com a ordem da matriz A:";
		std::cin >> n;
		std::cout << "Entre com a matriz A:";
		std::cout << std::endl;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				std::cout << "A[" << i << "][" << j << "]:";
				std::cin >> aux;
				d.push_back(aux);
			}
			A.push_back(d);
			d.clear();
		}
		
		std::cout << std::endl;
		std::cout << "Entre com o vetor d:" << std::endl;
		for(int i = 0; i < n; i++){
			std::cout << "d[" << i << "]:";
			std::cin >> aux;
			d.push_back(aux);
		}

		system("clear");
		std::cout << "+----------------LU/Doolittle---------------------+" << std::endl;
		
		std::cout << "Matriz A:" << std::endl;;
		for(int i = 0; i < n; i++){
			std::cout << "|";
			for(int j = 0; j < n-1; j++)
				std::cout << A[i][j] << " ";
			std::cout << A[i][n-1] << "|" << std::endl;
		}

		std::cout << std::endl;
		std::cout << "Vetor d:" << std::endl;
		std::cout << "[";
		for(int i = 0; i < n - 1; i++)
			std::cout << d[i] << " " ;
		std::cout << d[n-1] << "]" << std::endl;
		
		std::cout << std::endl;
		std::cout << "Confirmar?(S/N)" << std::endl;
		std::cin >> car;
		if(car == 'S' || car == 's')
			flag = true;
	}

		
	system("clear");	
	std::cout << "+----------------LU/Doolittle---------------------+" << std::endl;
	
	std::cout << "Matriz A:" << std::endl;;
	for(int i = 0; i < n; i++){
		std::cout << "|";
		for(int j = 0; j < n-1; j++)
			std::cout << A[i][j] << " ";
		std::cout << A[i][n-1] << "|" << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Vetor d:" << std::endl;
	std::cout << "[";
	for(int i = 0; i < n - 1; i++)
		std::cout << d[i] << " " ;
	std::cout << d[n-1] << "]" << std::endl;
	
	std::cout << std::endl;
	std::cout << "1 - LU" << std::endl;
	std::cout << "2 - Doolittle" << std::endl;
	std::cout << "3 - Comparar" << std::endl;
	std::cout << "Aplicar:";
	std::cin >> aux;

	switch(aux){
		case 1:
			resultado1 = SisLinear::calcularLU(A, d);
			break;
		case 2:
			dl = Doolittle::dooli(A, d);
			break;
		case 3:
			LU = SisLinear::gerarLU(A);
			dl = Doolittle::dooli(A, d);
			resultado1 = SisLinear::usarLU(LU, d);
			resultado2 = SisLinear::usarLU(dl, d);
			break;
	}


	system("clear");
	std::cout << "+----------------LU/Doolittle---------------------+" << std::endl;
	if(aux == 3){
		
		std::cout << std::endl;
		std::cout << "+-------------------Método LU--------------------+" << std::endl;
		
		std::cout << "Matriz LU:" << std::endl;;
		for(int i = 0; i < n; i++){
			std::cout << "|";
			for(int j = 0; j < n-1; j++)
				printf("%15.10f ", LU[i][j]);
				//std::cout << LU[i][j] << " ";
			printf("%15.10f|\n", LU[i][n-1]);
			//std::cout << LU[i][n-1] << "|" << std::endl;
		}
		
		std::cout << "Resultado: ";
		std::cout << "[";
		for(int i = 0; i < n - 1; i++)
			std::cout << resultado1[i] << " " ;
		std::cout << d[n-1] << "]" << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		
		std::cout << "+-------------------Método Doolittle-------------+" << std::endl;
		
		std::cout << "Matriz LU:" << std::endl;;
		for(int i = 0; i < n; i++){
			std::cout << "|";
			for(int j = 0; j < n-1; j++)
				printf("%15.10f ", dl[i][j]);
				//std::cout << LU[i][j] << " ";
			printf("%15.10f\n|", dl[i][n-1]);
			//std::cout << LU[i][n-1] << "|" << std::endl;
		}
		
		std::cout << "Resultado: ";
		std::cout << "[";
		for(int i = 0; i < n - 1; i++)
			std::cout << resultado2[i] << " " ;
		std::cout << d[n-1] << "]" << std::endl;
		std::cout << std::endl;
	}
	



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