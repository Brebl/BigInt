#include "calc.h"
#include <fstream>

static void helper(std::string pos_eka, std::string eka, std::string pos_toka, std::string toka, int i);

void test_1()
{
	//
	std::ifstream data_in;
	std::string temp;
	std::vector<std::string> vs;

	data_in.open("test1.data", std::ios::in);
	if (data_in) {
		while (data_in.peek() != EOF) {
			data_in >> temp;
			vs.emplace_back(temp);
		}
	}
	data_in.close();

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			helper(vs[0 + (j * 4)], vs[1 + (j * 4)], vs[2 + (j * 4)], vs[3 + (j * 4)], i);
		}
	}

	std::cout << "\n\n"
	"--------------------------------------------------TEST_1 END-----------------------------------------------\n\n\n";
}

static void helper(std::string pos_eka, std::string eka, std::string pos_toka, std::string toka, int i)
{
	brb::Calc a{ eka, pos_eka };
	brb::Calc b{ toka, pos_toka };

	switch (i) {
	case 0:
		std::cout << pos_eka << eka << " + " << pos_toka << toka << " = ";
		a += b;
		break;
	case 1:
		std::cout << pos_eka << eka << " - " << pos_toka << toka << " = ";
		a -= b;
		break;
	case 2:
		std::cout << pos_eka << eka << " * " << pos_toka << toka << " = ";
		a *= b;
		break;
	case 3:
		std::cout << pos_eka << eka << " / " << pos_toka << toka << " = ";
		a /= b;
		break;
	default:
		assert(false);
		break;
	}
	a.getValue(0, true);
}