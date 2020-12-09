#include "pch.h"
#include <fstream>
#include <iomanip>

bool test1()
{
	struct Testcase{
		std::string calculation;
		brb::Calc num1, num2;
		brb::Calc answer;
	};
	std::ifstream data_in;
	Testcase testcase;
	std::vector<Testcase> vtest;
	std::string s, n, r, d;

	//load testfile
	data_in.open("test1.data", std::ios::in);
	if (data_in) {
		while (data_in.peek() != EOF) {
			data_in >> testcase.calculation 
			>> s >> n >> r >> d;
			testcase.num1 = brb::Calc{n,s,r,d};

			data_in >> s >> n >> r >> d;
			testcase.num2 = brb::Calc{n,s,r,d};

			data_in >> s >> n >> r >> d;
			testcase.answer = brb::Calc{n,s,r,d};

			vtest.emplace_back(testcase);
		}
	}
	else{
		brb::err("test1.data","file not found");
		return false;
	}
	data_in.close();

	//run tests
	for(auto&& i: vtest){
		i.num1.getValue();
		if(i.calculation == "+"){
			std::cout << " + ";
			i.num1 += i.num2;
		}
		if(i.calculation == "-"){
			std::cout << " - ";
			i.num1 -= i.num2;
		}
		if(i.calculation == "*"){
			std::cout << " * ";
			i.num1 *= i.num2;
		}
		if(i.calculation == "/"){
			std::cout << " / ";
			i.num1 /= i.num2;
		}
		i.num2.getValue();
		std::cout << "\t= ";
		i.answer.getValue();

		if(i.answer != i.num1){
			brb::err("test1 failed", "");
			return false;
		}
		std::cout << std::endl;
	}
	std::cout << "----------------\ntest1 successful\n";
	return true;
}
