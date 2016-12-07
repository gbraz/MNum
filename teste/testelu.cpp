#include <iostream>
#include "../header/sislinear.h"

int main(){
	
	std::vector<double> s1;
	std::vector< std::vector<double> > r, mat; 
	
	s1.push_back(20);
	s1.push_back(7);
	s1.push_back(9);
	mat.push_back(s1);
	s1.clear();
	s1.push_back(7);
	s1.push_back(30);
	s1.push_back(8);
	mat.push_back(s1);
	s1.clear();
	s1.push_back(9);
	s1.push_back(8);
	s1.push_back(30);
	mat.push_back(s1);
	s1.clear();

	SisLinear sl;
	r = sl.lu(mat);

	for(int i = 0; i < mat.size(); i++){
		std::cout << "|";
		for(int j = 0; j < mat.size(); j++)
			std::cout << mat[i][j] << " ";
		std::cout << "|" << std::endl;
	}
	std::cout << std::endl;

	for(int i = 0; i < r.size(); i++){
		std::cout << "|";
		for(int j = 0; j < r.size(); j++)
			std::cout << r[i][j] << " ";
		std::cout << "|" << std::endl;
	}

}