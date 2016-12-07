#include <vector>

class SisLinear {

public:
	SisLinear();
	std::vector<std::vector<double> > pivotear (std::vector<std::vector<double> >);
	std::vector<std::vector<double> > lu(std::vector<std::vector<double> >);
};