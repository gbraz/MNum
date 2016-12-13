#ifndef DOOLITTLE_H
#define DOOLITTLE_H

#include <iostream>
#include <cmath>
#include <vector>

class Doolittle{
public:

Doolittle();
static void escreveMatriz(std::vector < std::vector <double> > L);
static void escreveVector(std::vector <double> L);
static std::vector < std::vector <double> >  dooli(std::vector < std::vector <double> > A, std::vector <double> b);

};

#endif 