#include "newton.h"


Newton::Newton(){

}


double Newton::fun(double c, std::vector<double> a){
	double b;

	for(int i = 0; i < a.size(); i++) //Método de Horner
		b = b*c + a[i];

	return b;
}

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

double Newton::passoIter(double x, std::vector<double> a, std::vector<std::vector<double> >& res, int p){
	std::vector<double> f, iteracao;

	f = horner(x, a);

	iteracao.push_back(x);	//Armazenando os resultados da iteração
	iteracao.push_back(f[0]);
	iteracao.push_back(f[1]);
	res.push_back(iteracao);

	return x - p*f[0]/f[1];
}



std::vector<std::vector<double> > Newton::calcularRaiz(double x, std::vector<double> a, double e1, double e2, int p){ //p é um parâmetro opcional, default 1
	double xk, f;
	std::vector<std::vector<double> > res;

	do{
		xk = x;
		x = passoIter(xk, a, res, p);

	}while (std::abs(x - xk) > e1 && std::abs(fun(x, a)) > e2);
	
	passoIter(x, a, res, p);

	return res;
}

void Newton::salvarResSec(double x, double fx, std::vector<std::vector<double> >& res){ //Armazena os resultados da iteração
	std::vector<double> iteracao;

	iteracao.push_back(x);
	iteracao.push_back(fx);
	res.push_back(iteracao);
}


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

	double Newton::circulo(std::vector<double> a){
    int i = 0; double maxi = 0;
    for(i; i < a.size()-1; i++){
        if(abs(a[i]/a[a.size() - 1]) > maxi){
            maxi = a[i];
        }
    }

    return 1 + maxi;
}

std::vector<double> Newton::divisaoPolinomio(std::vector<double> a, std::vector<double> b){
    // ideia: dar um shift em b ate a primeira posição util de a.
    // termina quando a primeira posição de a for menor que a primeira posição de b
    std::vector<double> aa;

    double coef;
    int inicioB = 0;
    int i;
    while(inicioB < b.size() && b[i] == 0){
        inicioB++;
        i++;
    }
    if(inicioB >= b.size())
        return aa;
        // supondo que a tem maior grau que b
        //shift em b
    int j = 0;

    while(j <= inicioB){

        i = j;
        while(i < a.size()){
            if(a.size() - inicioB < i){
                aa.insert(aa.begin() + i, 0.0);
            }
            else{
                aa.insert(aa.begin() + i, b[j - i + inicioB]);
            }
            i++;
        }

        coef = -a[i]/b[inicioB];

        for(i = 0; i <= a.size(); i++){
               a[i] = coef * aa[i] + a[i];
        }
        j++;
    }
}

std::vector<double> nZeros(std::vector<double> I, std::vector<double> a, int i){
    /* ideia: I = [x0, x1] inicialmente.
        se i == I.size() - 1 entao nao ha raizes neste intervalo
        insiro a media do intervalo. I = [x0, xm, x1]
        vejo quantas raizes existem entre x0 e xm
        se existirem 0 raizes então procura em xm, x1 = [ I[i+1], I[i+2] ]
        se existir mais de uma raiz entao subdivide I = [x0, xm1, xm, x1] e chama para x0, xm1

    */
    if(i == I.size() - 1)
        return I;
    int nz = Sturn(a, I[i], I[i+1]);
    if(nz == 0){
        return nZeros(I, a, i+1);
    }
    if(nz > 1){
        I.insert(i+1, (I[i] + I[i+1])/2);
        return nZeros(I, a, i);
    }

    return I;
}

int Newton::Sturn(std::vector<double> a, double alpha, double betha){
    std::vector<std::vector<double>> G;
    std::vector<double> deriv;

    // calculando a descrição da derivada
    int i = 0;
    deriv.push_back(0);

    for(i; i < a.size - 1; i++){
        deriv.push_back((i-1)*a[i]);
    }

    // gerando a sequencia de sturn. G guarda todos os polinomios gerados pela divisao de pol

    G.push_back(a);
    G.push_back(deriv);

    std::vector<double> holder;

    bool valido = true;
    i = 0;
    while(valido){
        holder = Newton::divisaoPolinomio(G[i], G[i+1]);
        if(holder.size() != 0){
            G.push_back(holder);
            i++;
        }else{
            valido = false;
        }

    }

// sao os v(alpha) - v(betha) de sturn
    double v1 = 0, v2 = 0;

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


double Newton::fun(double c, std::vector<double> a){
	double b;

	for(int i = 1; i < a.size(); i++) //Método de Horner
		b = b*c + a[i];

	return b;
}

}