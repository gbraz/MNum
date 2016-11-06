#include<iostream>
#include "../header/newton.h"

double fun(double c, std::vector<double> a){
	double b;

	for(int i = 0; i < a.size(); i++) //Método de Horner
		b = b*c + a[i];

	return b;
}

void escrevePolinomio(std::vector<double> a){
    int k = 0;

    for(k; k < a.size(); k++){
        std::cout << a[k] << " ";

    }
    std::cout << std::endl;
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

    std::cout << "começo de divisao polinomio" << std::endl << std::endl;
    // ideia: dar um shift em b ate a primeira posição util de a.
    // termina quando a primeira posição de a for menor que a primeira posição de b
    std::vector<double> bb;

    std::cout << " originais, a = ";
    escrevePolinomio(a);
    std::cout << " originais, b = ";
    escrevePolinomio(b);

    double coef = 1;
    int inicioB = 0;
    int i;

    if(a.size() > b.size()){
        b.insert(b.begin(), a.size() - b.size(), 0);
        std::cout << " agora, b = ";
        escrevePolinomio(b);

    }

    i = 0;
    while(a[0] == 0 && i < a.size()){
        a.erase(a.begin());
        b.erase(b.begin());
    	i++;
    	std::cout << i;

    }

    std::cout << " a tambem precisa de shift! apos shift, a = ";
    escrevePolinomio(a);

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
    escrevePolinomio(a);
    std::cout << "b = ";
    escrevePolinomio(b);

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
    escrevePolinomio(b);

    bb = b;


    int k = 0;

    int j = 0;
    std::cout << "inicio do loop problema " << std::endl << std::endl;
    while(j <= inicioB){
        std::cout << "a = ";
        escrevePolinomio(a);
    	if(a[j] != 0){
    	    std::cout << "      bb[0] = " << bb[0] << std::endl;
    	    std::cout << "      a[j] = " << a[j] << std::endl;

	        coef = -a[j]/bb[0];
            std::cout << "      tem o coeficiente " << coef << std::endl;

            std::cout << "      inicio do loop de atribuicao" << std::endl;
            for(i = 0; i < bb.size() - j; i++){
                std::cout << " i = "<< i << std::endl;
                escrevePolinomio(a);

                 std::cout << " a[i+j] = " << a[i+j] << std::endl;


                a[j + i] = coef * bb[i] + a[j + i];

                if(std::abs(a[i + j]) < 1.0*10e-6)
                    a[i+j] = 0;
            }


	        /*for(i = j; i <= a.size(); i++){
	               a[i] = coef * bb[i] + a[i];
	        }*/
	    }
	    j++;
    }

    std::cout << "terminou a divisao, coef= " << coef << std::endl;
    std::cout << "  fim do loop; a = ";
    escrevePolinomio(a);
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

    std::cout << "começo de Sturn" << std::endl;

    std::vector<std::vector<double> > G;
    std::vector<double> deriv;

    // calculando a descrição da derivada
    int i = 0;
    std::cout<< "a = ";
    escrevePolinomio(a);

    deriv.push_back(0);
    std::cout << "derivada = ";

    int l = 0;

    for(i = a.size() - 1; i > 0; i = i - 1){
        deriv.push_back((i)*a[l]);
        l++;
    }
    escrevePolinomio(deriv);


    // gerando a sequencia de sturn. G guarda todos os polinomios gerados pela divisao de pol

    G.push_back(a);
    G.push_back(deriv);

    std::vector<double> holder (3, 0);


    bool valido = true;
    i = 0;

    std::cout << "          começo do loop em Sturn para as sequencias de polinomio" << std::endl;

    while(valido){
        holder = std::vector <double>() ;
        holder = divisaoPolinomio(G[i], G[i+1]);
        std::cout << "em Sturn, holder = " << std::endl;

        escrevePolinomio(holder);

        if(holder.size() != 0){
            G.push_back(holder);
            i++;
        }else{
            valido = false;
        }

    }

    /*while(valido){
        G.push_back(divisaoPolinomio(G[i], G[i+1]));
        escrevePolinomio(G[G.size() - 1]);
        if(G[G.size() - 1].size() == 0){
            valido = false;
        }else{
            i++;
        }
    }*/
// obtida a sequencia de Sturn, basta verificar o valor de v(alpha) e v(betha)
// sao os v(alpha) - v(betha) de sturn

    std::cout << "fim do loop em Sturn" << std::endl;

    int z = 0;

    for(z; z < G.size(); z++){
        std::cout << "G[" << z << "] = " << std::endl;
        escrevePolinomio(G[z]);
    }

    int v1 = 0, v2 = 0;

    double h1, h2;
    double l1, l2;

// ignorando os coe
    std::cout << "      gerando os valores das funções sequencia" << std::endl;
    std::cout << "  aqui esta o que procura: I = [ "<< alpha << ", " << betha << "]" << std::endl;
    h1 = fun(alpha, G[0]);
    l1 = fun(betha, G[0]);

    for(i = 1; i < G.size();  i++){
        std::cout << "        g(alpha, i),   g(betha, i) = " << h1 << ", " << l1 << std::endl;

        h2 = fun(alpha, G[i]);

        l2 = fun(betha, G[i]);

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
    std::cout << " I = [ "<< I[i] << ", " << I[i+1] << "]" << std::endl;
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
    P.push_back(-4);
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
