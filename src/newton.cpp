#include "../header/newton.h"


Newton::Newton(){

}

/*Retorna o resultado de um polinômio por método de horner
  Entradas: double c - valor da abscissa
  			std::vector<double> a - coeficientes do polinômio
  Saída:	double - valor de P(c)*/
double Newton::fun(double c, std::vector<double> a){
	double b = a[0];

	for(int i = 1; i < a.size(); i++) //Método de Horner
		b = b*c + a[i];

	return b;
}

/*Retorna o resultado de um polinômio e sua derivada por método de horner
  Entradas: double c - valor da abscissa
  			std::vector<double> a - coeficientes do polinômio
  Saída:	std::vector<double> - valor de P(c) e P'(c)*/
std::vector<double> Newton::horner(double c, std::vector<double> a){
	double b = a[0], d = a[0];
	std::vector<double> f;

	for(int i = 1; i < a.size(); i++){ //Método de Horner
		b = b*c + a[i];
		if(i < a.size() - 1)
			d = d*c + b;
	}

	f.push_back(b);
	f.push_back(d);
	return f;
}

/*Executa um passo iteratico do método de Newton-Raphson
  Entradas: double c - valor da abscissa
  			std::vector<double> a - coeficientes do polinômio
  			std::vector<std::vector<double> >& res - matriz onde serão armazenadas os resultados da iteração
  Saída:	double - valor x do resultado da iteração realizada*/
double Newton::passoIter(double x, std::vector<double> a, std::vector<std::vector<double> >& res, int p){
	std::vector<double> f, iteracao;

	f = horner(x, a);

	iteracao.push_back(x);	//Armazenando os resultados da iteração
	iteracao.push_back(f[0]);
	iteracao.push_back(f[1]);
	res.push_back(iteracao);

	return x - p*f[0]/f[1];
}


/*Calcula a raiz via método de Newton-Raphson
  Entradas: double c - valor da abscissa
  			std::vector<double> a - coeficientes do polinômio
  			double e1 - critério de parada 1
			double e2 - critério de parada 2
  			int p - multiplicidade da raiz a ser encontrada. Parâmetro opcional, default 1
  Saída:	std::vector<std::vector<double> > - matriz com os resultados de cada iteração*/
std::vector<std::vector<double> > Newton::calcularRaiz(double x, std::vector<double> a, double e1, double e2, int p){
	double xk, f;
	std::vector<std::vector<double> > res;

	do{
		xk = x;
		x = passoIter(xk, a, res, p);

	}while (std::abs(x - xk) > e1 && std::abs(fun(x, a)) > e2);

	passoIter(x, a, res, p);

	return res;
}

/*Armazena o resultado de uma iteração do método da Secante
  Entradas: double x - valor da abscissa
  			double fx - valor da coordenada para x
  			std::vector<std::vector<double> >& res - matriz de armazenamento dos resultados*/
void Newton::salvarResSec(double x, double fx, std::vector<std::vector<double> >& res){ //Armazena os resultados da iteração
	std::vector<double> iteracao;

	iteracao.push_back(x);
	iteracao.push_back(fx);
	res.push_back(iteracao);
}

/*Calcula a raiz via método da Secante
  Entradas: double x0 - valor da abscissa do primeiro chute
  			double x1 - valor da abscissa do segundo chute
  			std::vector<double> a - coeficientes do polinômio
  			double e1 - critério de parada 1
			double e2 - critério de parada 2
  			int p - multiplicidade da raiz a ser encontrada. Parâmetro opcional, default 1
  Saída:	std::vector<std::vector<double> > - matriz com os resultados de cada iteração*/
std::vector<std::vector<double> > Newton::calcularRaizSec(double x0, double x1, std::vector<double> a, double e1, double e2, int p){
	double f0, f1, temp;
	std::vector<std::vector<double> > res;

	f0 = fun(x0, a);
	salvarResSec(x0, f0, res); //Armazenando os resultados no vetor res
	f1 = fun(x1, a);
	salvarResSec(x1, f1, res);

	do{
		temp = x1;
		x1 = x1 - p*f1*(x1 - x0)/(f1 - f0);
		x0 = temp;
		f0 = f1;
		f1 = fun(x1, a);
		salvarResSec(x1, f1, res);
	}while(std::abs(x0 - x1) > e1 && std::abs(f1) > e2);

	return res;
}




//*************Autor: Rubens **********************


/* 	primeiro, usa a do circulo para ter o intervalo de tamanho K
	depois passa -k e K para nZeros
	isto retorna O intervalo e e todos os vertices dos subintervalos com exatamente uma raiz entre eles

*/
void Newton::escrevePolinomio(std::vector<double> a){
    int k = 0;

    for(k; k < a.size(); k++){
        std::cout << a[k] << " ";

    }
    std::cout << std::endl;
}

double Newton::circulo(std::vector<double> a){

    int i = 0;
    int inicioA = 0;

    while(a[i] == 0 && i < a.size()){
        inicioA++;
        i++;
    }
    i = inicioA + 1;

    if(inicioA == a.size())
        return 1;

    double maxi = 0;
    for(i; i < a.size(); i++){
        if(std::abs(a[i]/a[inicioA]) > maxi){
            maxi = std::abs(a[i]/a[inicioA]);

        }
    }

    return 1 + maxi;
}

std::vector<double> Newton::divisaoPolinomio(std::vector<double> a, std::vector<double> b){

    std::cout << "começo de divisao polinomio" << std::endl << std::endl;
    // ideia: dar um shift em b ate a primeira posição util de a.
    // termina quando a primeira posição de a for menor que a primeira posição de b
    std::vector<double> bb;

    std::cout << " originais, a = ";
    Newton::escrevePolinomio(a);
    std::cout << " originais, b = ";
    Newton::escrevePolinomio(b);

    double coef = 1;
    int inicioB = 0;
    int i;

    if(a.size() > b.size()){
        b.insert(b.begin(), a.size() - b.size(), 0);
        std::cout << " agora, b = ";
        Newton::escrevePolinomio(b);

    }

    i = 0;
    while(a[0] == 0 && i < a.size()){
        a.erase(a.begin());
        b.erase(b.begin());
    	i++;
    	std::cout << i;

    }

    std::cout << " a tambem precisa de shift! apos shift, a = ";
    Newton::escrevePolinomio(a);

    if(a.size() == 0){
    	return a;
    }

    if(b.size() == 0){
    	return b;
    }

    i = 0;

    /*while(b[i] == 0 && i < b.size()){
        //,std::cout << "loop" << std::endl;
    	inicioB++;
    	i++;
    }
    if(i == b.size())
        return b;
    */
    std::cout << "vetores parametro validos? inicioB = " << inicioB <<std::endl << std::endl;
    std::cout << "a = ";
    Newton::escrevePolinomio(a);
    std::cout << "b = ";
    Newton::escrevePolinomio(b);

    // shift no b
    /*for(i = inicioB; i <= a.size(); i++){
    	if(i >= b.size()){
    		bb.push_back(0);
    	}else{

    		bb.push_back(b[i]);
    	}
        //std::cout << "i = " << i <<std::endl;
    }*/
    int maxi = b.size();
    i = 0;
    while(b[0] == 0 && i < maxi){
        inicioB++;
        b.erase(b.begin());
        b.push_back(0);
        i++;
    }

    if(b.size() == 0)
        return a;
    std::cout << "deu o shift em b" << std::endl;
    std::cout << "b = ";
    Newton::escrevePolinomio(b);

    bb = b;


    int k = 0;

    int j = 0;
    std::cout << "inicio do loop problema " << std::endl << std::endl;
    while(j <= inicioB){
        std::cout << "a = ";
        Newton::escrevePolinomio(a);
    	if(a[j] != 0){
    	    std::cout << "      bb[0] = " << bb[0] << std::endl;
    	    std::cout << "      a[j] = " << a[j] << std::endl;

	        coef = -a[j]/bb[0];
            std::cout << "      tem o coeficiente " << coef << std::endl;

            std::cout << "      inicio do loop de atribuicao" << std::endl;
            for(i = 0; i < bb.size() - j; i++){
                std::cout << " i = "<< i << std::endl;
                Newton::escrevePolinomio(a);

                 std::cout << " a[i+j] = " << a[i+j] << std::endl;


                a[j + i] = coef * bb[i] + a[j + i];

                if(std::abs(a[i + j]) < 1.0*10e-6)
                    a[i+j] = 0;
            }

	    }
	    j++;
    }

    std::cout << "terminou a divisao, coef= " << coef << std::endl;
    std::cout << "  fim do loop; a = ";
    Newton::escrevePolinomio(a);
    // testando se o resultado da divisão é de fato um vetor (pro caso de dividir polinomios de grau zero)

    bool naonulo = false;
    i = 0;
    for(i = 0; i < a.size(); i++){
    	if(a[i] != 0)
    		naonulo = true;
    }

    if(naonulo){
        std::cout << "nao nulo" << std::endl;
    	return a;
    }
    std::vector<double> vetorNulo;
    std::cout << "nulo" << std::endl;
    return vetorNulo;
}


// inicio nZeros(std:: vector<> I = [-k, k],  vetor de coeficientes a, i = 0)
// retorna o intervalo com n > 1 vertices ou n=1 para o caso de nao existir raiz real
// espera receber um vector com as coordenadas retornadas pelo circulo e retorna os vertices cujos intervalos tem exatamente uma raiz
// I ja contem dois valores (ou um intervalo) [-k, k] vindos do circulo

std::vector<double> Newton::nZeros(std::vector<double> I, std::vector<double> a, int i){

    /*
    	 ideia: I = [x0, x1] inicialmente.
        se i == I.size() - 1 entao nao ha raizes neste intervalo
        insiro a media do intervalo. I = [x0, xm, x1]
        vejo quantas raizes existem entre x0 e xm
        se existirem 0 raizes então procura em xm, x1 = [ I[i+1], I[i+2] ]
        se existir mais de uma raiz entao subdivide I = [x0, xm1, xm, x1] e chama para x0, xm1

    */
    int nz = Newton::Sturn(a, I[i], I[i+1]);

    if(nz == 0){
    	I.erase(I.begin() + i);
    			// queer dizer que o intervalo inicial nao possui raizes reais. se falhar entao possui pelo menos uma e esta eh encontrada
        return I;

    }
    if(nz > 1){
    	I.insert(I.begin() + i + 1, (I[i] + I[i+1])/2);
    	I = Newton::nZeros(I, a, i);
    	I = Newton::nZeros(I, a, i+1);
    }

    return I;

}

int Newton::Sturn(std::vector<double> a, double alpha, double betha){

    std::cout << "começo de Sturn" << std::endl;

    std::vector<std::vector<double> > G;
    std::vector<double> deriv;

    // calculando a descrição da derivada
    int i = 0;
    std::cout<< "a = ";
    Newton::escrevePolinomio(a);

    deriv.push_back(0);
    std::cout << "derivada = ";

    int l = 0;

    for(i = a.size() - 1; i > 0; i = i - 1){
        deriv.push_back((i)*a[l]);
        l++;
    }
    Newton::escrevePolinomio(deriv);


    // gerando a sequencia de sturn. G guarda todos os polinomios gerados pela divisao de pol

    G.push_back(a);
    G.push_back(deriv);

    std::vector<double> holder (3, 0);


    bool valido = true;
    i = 0;

    std::cout << "          começo do loop em Sturn para as sequencias de polinomio" << std::endl;

    while(valido){
        holder = std::vector <double>() ;
        holder = Newton::divisaoPolinomio(G[i], G[i+1]);
        std::cout << "em Sturn, holder = " << std::endl;

        Newton::escrevePolinomio(holder);

        if(holder.size() != 0){
            G.push_back(holder);
            i++;
        }else{
            valido = false;
        }

    }

// obtida a sequencia de Sturn, basta verificar o valor de v(alpha) e v(betha)
// sao os v(alpha) - v(betha) de sturn

    std::cout << "fim do loop em Sturn" << std::endl;

    int z = 0;

    for(z; z < G.size(); z++){
        std::cout << "G[" << z << "] = " << std::endl;
        Newton::escrevePolinomio(G[z]);
    }

    int v1 = 0, v2 = 0;

    double h1, h2;
    double l1, l2;

// ignorando os coe
    std::cout << "      gerando os valores das funções sequencia" << std::endl;
    std::cout << "  aqui esta o que procura: I = [ "<< alpha << ", " << betha << "]" << std::endl;
    h1 = Newton::fun(alpha, G[0]);
    l1 = Newton::fun(betha, G[0]);

    for(i = 1; i < G.size();  i++){
        std::cout << "        g(alpha, i),   g(betha, i) = " << h1 << ", " << l1 << std::endl;

        h2 = Newton::fun(alpha, G[i]);

        l2 = Newton::fun(betha, G[i]);

        std::cout << "      g(alpha, i+1), g(betha, i+1) = " << h2 << ", " << l2 << std::endl << std::endl;
        if(h1*h2 < 0){
            std::cout << " v1++ "<< i << std::endl;
            v1++;
        }
        if(l1*l2 < 0){
            std::cout << " v2++ "<< i << std::endl;
            v2++;
        }
        h1 = h2;
        l1 = l2;
    }
    std::cout << "fim de Sturn " << std::endl << std::endl;
    std::cout << " existem "<< v1 - v2 << " raizes neste intervalo [" << alpha << ", " << betha <<  std::endl << std::endl;
    return v1 - v2;

}