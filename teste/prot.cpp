#include<iostream>
#include "../header/newton.h"

double fun(double c, std::vector<double> a){
	double b;

	for(int i = 0; i < a.size(); i++) //Método de Horner
		b = b*c + a[i];

	return b;
}

double circulo(std::vector<double> a){

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

std::vector<double> divisaoPolinomio(std::vector<double> a, std::vector<double> b){
    // ideia: dar um shift em b ate a primeira posição util de a.
    // termina quando a primeira posição de a for menor que a primeira posição de b
    std::vector<double> bb;

    double coef = 1;
    int inicioB = 0;
    int i = 0;

    if(a.size() == 0){
    	return a;
    }

    if(b.size() == 0){
    	return b;
    }

    std::cout << "inicio" << std::endl;

    while(b[i] == 0 && i < b.size()){
        std::cout << "loop" << std::endl;
    	inicioB++;
    	i++;
    }
    if(i == b.size())
        return b;

    std::cout << "tem o inicio de b inicioB = " << inicioB << std::endl;


    // shift no b
    for(i = inicioB; i < a.size(); i++){
    	if(i >= b.size()){
    		bb.push_back(0);
    	}else{

    		bb.push_back(b[i]);
    	}
    }

    std::cout << "deu o shift em b" << std::endl;
    // a = [2 2 2 2 2]
    // b = [1 2 3 0 0] depois do shift
    // coef = -2/1
    //a = [0 -2 -4 2 2]

    // por hipotese, b[0] != 0

    int j = 0;

    while(j <= inicioB){

    	if(a[j] != 0){
    	    std::cout << "bb[0] = " << bb[0] << std::endl;
    	    std::cout << "-a[j] = " << -a[j] << std::endl;
	        coef = -a[j]/bb[0];
            std::cout << "tem o coeficiente " << coef << std::endl;

	        for(i = j; i <= a.size(); i++){
	               a[i] = coef * bb[i] + a[i];
	        }
	    }
	    j++;
    }

    std::cout << "terminou a divisao " << coef << std::endl;
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

int Sturn(std::vector<double> a, double alpha, double betha){
    std::vector<std::vector<double> > G;
    std::vector<double> deriv;

    // calculando a descrição da derivada
    int i = 0;
    deriv.push_back(0);

    for(i; i < a.size() - 1; i++){
        deriv.push_back((i-1)*a[i]);
    }

    // gerando a sequencia de sturn. G guarda todos os polinomios gerados pela divisao de pol

    G.push_back(a);
    G.push_back(deriv);

    std::vector<double> holder;


    bool valido = true;
    i = 0;
    /*while(valido){
        holder = divisaoPolinomio(G[i], G[i+1]);
    std::cout << "TESTE" << std::endl;
        if(holder.size() != 0){
            G.push_back(holder);
            i++;
        }else{
            valido = false;
        }

    }*/

    while(valido){
        G.push_back(divisaoPolinomio(G[i], G[i+1]));
        if(G[i+1].size() == 0){
            valido = false;
        }else{
            i++;
        }
    }
// obtida a sequencia de Sturn, basta verificar o valor de v(alpha) e v(betha)
// sao os v(alpha) - v(betha) de sturn
    int v1 = 0, v2 = 0;

    double h1, h2;
    double l1, l2;

// ignorando os coe
    h1 = fun(alpha, G[0]);
    l1 = fun(betha, G[0]);

    for(i = 1; i < G.size();  i++){

        h2 = fun(alpha, G[i]);
        l2 = fun(betha, G[i]);

        if(h1*h2 < 0){
            v1++;
        }
        if(l1*l2 < 0){
            v2++;
        }
        h1 = h2;
        l1 = l2;
    }

    return v1 - v2;

}


// inicio nZeros(std:: vector<> I = [-k, k],  vetor de coeficientes a, i = 0)
// retorna o intervalo com n > 1 vertices ou n=1 para o caso de nao existir raiz real
// espera receber um vector com as coordenadas retornadas pelo circulo e retorna os vertices cujos intervalos tem exatamente uma raiz
// I ja contem dois valores (ou um intervalo) [-k, k] vindos do circulo

std::vector<double> nZeros(std::vector<double> I, std::vector<double> a, int i){

    /*
    	 ideia: I = [x0, x1] inicialmente.
        se i == I.size() - 1 entao nao ha raizes neste intervalo
        insiro a media do intervalo. I = [x0, xm, x1]
        vejo quantas raizes existem entre x0 e xm
        se existirem 0 raizes então procura em xm, x1 = [ I[i+1], I[i+2] ]
        se existir mais de uma raiz entao subdivide I = [x0, xm1, xm, x1] e chama para x0, xm1

    */
    int nz = Sturn(a, I[i], I[i+1]);

    if(nz == 0){
    	I.erase(I.begin() + i);
    			// queer dizer que o intervalo inicial nao possui raizes reais. se falhar entao possui pelo menos uma e esta eh encontrada
        return I;

    }
    if(nz > 1){
    	I.insert(I.begin() + i + 1, (I[i] + I[i+1])/2);
    	I = nZeros(I, a, i);
    	I = nZeros(I, a, i+1);
    }

    return I;

}



int main(){
    std::vector<double> vazio;
    std::cout << vazio.size() ;

    vazio.push_back(0);
    vazio.push_back(3);
    vazio.push_back(0);
    vazio.push_back(1);

    std::vector <double> P;
    P.push_back(2);
    P.push_back(1);
    P.push_back(0);
    P.push_back(1);



    // testando os intervalos

    double k = circulo(P);
    std::vector<double> I;
    I.push_back(-k);
    I.push_back(k);

    std::cout << "tamanho de I: " << I.size() <<std::endl;

   std::vector <double> intervalos = nZeros(I, P, 0);
   std::cout << "tamanho de Intervalos: " << intervalos.size() <<std::endl;

   return 0;
}
