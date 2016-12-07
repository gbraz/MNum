#include "../header/sislinear.h"

int main(){
	
	std::vector<double> s1, aux;
	std::vector< std::vector<double> > r, mat; 
/*	
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

*/


	aux.push_back(30);
	aux.push_back(30);
	aux.push_back(30);
	aux.push_back(30);

	s1.push_back(2);
	s1.push_back(2);
	s1.push_back(1);
	s1.push_back(1);
	mat.push_back(s1);
	s1.clear();
	s1.push_back(1);
	s1.push_back(-1);
	s1.push_back(2);
	s1.push_back(-1);
	mat.push_back(s1);
	s1.clear();
	s1.push_back(3);
	s1.push_back(2);
	s1.push_back(-3);
	s1.push_back(-2);
	mat.push_back(s1);
	s1.clear();
	s1.push_back(4);
	s1.push_back(3);
	s1.push_back(2);
	s1.push_back(1);
	mat.push_back(s1);


	aux = s1;
	for(int j = 0; j < mat.size(); j++)
			std::cout << aux[j] << " ";
	std::cout << std::endl;

	SisLinear sl;
	r = sl.gerarLU(mat);

	for(int i = 0; i < mat.size(); i++){
		std::cout << "|";
		for(int j = 0; j < mat.size(); j++)
			std::cout << mat[i][j] << " ";
		std::cout << "|" << std::endl;
	}
	std::cout << std::endl;

	for(int i = 0; i < r.size(); i++){
		std::cout << "|";
		for(int j = 0; j < r[0].size(); j++)
			std::cout << r[i][j] << " ";
		std::cout << "|" << std::endl;
	}

}