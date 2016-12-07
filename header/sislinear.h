#include <vector>
#include <stdlib.h>

class SisLinear {

public:
	SisLinear();
	bool pivotear (std::vector<std::vector<double> >, std::vector<double>, int);
	std::vector<std::vector<double> > lu(std::vector<std::vector<double> >);
};