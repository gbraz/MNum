#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

void escreveMatriz(vector < vector <double> > L){
     for(int i = 0; i < L[0].size(); i++){

        for(int j = 0; j < L.size(); j++){

           cout << "        " << L[j][i];
        }
        cout << endl;
    }

    cout <<L[0].size() << "x" << L.size() << endl;
}

void escreveVector(vector <double> L){
     for(int i = 0; i < L.size(); i++){

           cout << "    " << L[i] << endl;
    }
}

void  dooli(vector < vector <double> > A, vector <double> b){
    vector < vector <double> > L;
    vector < vector <double> > U;

    int m = A[0].size();
    int n = A.size();

    //! inicializando L U

    for(int i = 0; i < n; i++){
        vector <double> l;
        vector <double> u;
        for(int j = 0; j < m; j++){
            l.push_back(0);
            u.push_back(0);

            if(i == j){
               l[i] = 1;

            }
        }
        L.push_back(l);
        U.push_back(u);

    }
    cout << "inicializou U" << endl;
    escreveMatriz(U);

    double somaU = 0;
    double somaL = 0;



    //! metodo doolitle

    //! col, li

    for(int i = 0; i < n; i++){
        U[i][0] = A[0][i];
    }

    for(int i = 1; i < m; i++){
        L[0][i] = A[i][0]/U[0][0];
    }

    for(int i = 1; i < n-1; i++){
        for(int j = i+1; j < n; j++){

                cout << "       loop " << endl;
             somaU = 0;
             somaL = 0;
            for(int t = 0; t < i ; t++){
                somaU = somaU + L[t][i] * U[j][t];
                somaL = somaL + L[t][j] * U[i][t];
            }

            if(std::abs((long) somaL) <= 0.00001)
                somaL = 0;
            if(std::abs((long) somaU) <= 0.00001)
                somaU = 0;

            cout << "somaU = " << somaU << " em " << i << j << endl;
            cout << "somaL = " << somaL << " em " << j << i << endl;

            U[j][i] = A[j][i] - somaU;

            somaU = 0;
            for(int t = 0; t < i ; t++){
                somaU = somaU + L[t][i] * U[j - 1][t];

            }
             U[i][i] = A[i][i] - somaU;


             cout << "somaU = " << somaU << " em " << i << j-1 << endl;

              L[i][j] = (A[i][j] - somaL)/U[i][i];

                cout << "modificou U" << endl;
                escreveMatriz(U);
                cout << "modificou L" << endl;
                escreveMatriz(L);
        }

    }
    somaU = 0;
    for(int t = 0; t < n - 1;t++){
        somaU = somaU + L[t][n-1] * U[n-1][t];
    }

    U[n-1][n-1] = A[n-1][n-1] - somaU;

    cout << "modificou U" << endl;
    escreveMatriz(U);
cout << "modificou L" << endl;
    escreveMatriz(L);

    //! achado L U, achar L^-1, b* e depois solucionar o sistema

    //L^-1
    for(int i = 1; i < L.size(); i++){
        for(int j = 0; j < i; j++){

            L[i][j] = -L[i][j];

        }
    }
    //b*
    for(int i = 0; i < L.size(); i++){
        double ac = 0;
        for(int j = 0; j <= i; j++){

            ac = ac + L[i][j]*b[j];
        }
        b[i] = ac;
    }
    cout << "modificou b" << endl;
    escreveVector(b);
}

int main(int * narg, char ** argv){

    cout << "Start" << endl;

    vector < vector <double> > A;
    vector <double>  b;
    vector <double>  c1;

    c1.push_back(20);
    c1.push_back(7);
    c1.push_back(9);
    c1.push_back(2);

    A.push_back(c1);

    vector <double>  c2;

    c2.push_back(7);
    c2.push_back(30);
    c2.push_back(8);
    c2.push_back(1);

    A.push_back(c2);

    vector <double>  c3;

    c3.push_back(9);
    c3.push_back(8);
    c3.push_back(30);
    c3.push_back(33);

    A.push_back(c3);

    vector <double>  c4;

    c4.push_back(1);
    c4.push_back(8);
    c4.push_back(2);
    c4.push_back(7);

    A.push_back(c4);

    cout << "       escrevendo A..." << endl;
    escreveMatriz(A);

    b.push_back(16);
    b.push_back(5);
    b.push_back(38);
    b.push_back(2);

    cout << "       escrevendo B..." << endl;
    escreveVector(b);

    dooli(A, b);

    cout << " Saiu de dool" << endl;

    return 0;
}
