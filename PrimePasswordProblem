#include <iostream>
#include <cmath>
#include <vector>

void checkIfHaveNum(int const&, std::vector<int>&, std::vector<int>&);

int main(void) {
	std::vector<int> haveNum{};
	std::vector<int> muchNum{};

	int inputNum;
	std::cin >> inputNum;

	int num = sqrt(inputNum);

	for (int i = 2; num >= i  ; i++) {
		std::cout << "hi ";
		while (!(inputNum % i)) {
			std::cout << "hi2 " << '\n';
			inputNum /= i;
			checkIfHaveNum(i,haveNum ,muchNum);
		}
	}

	haveNum.push_back(inputNum);
	muchNum.push_back(1);


	for (int i : haveNum) {
		std::cout << i << '\n';
	}

	for (int i : muchNum) {
		std::cout << i << '\n';
	}

		 
	return 0;
}

void checkIfHaveNum(int const& n,std::vector<int> &haveNum , std::vector<int>& muchNum) {
	static int muchNumIndex = -1;
	for(int i: haveNum) { 
		if ( i == n) {
			++muchNum[muchNumIndex];
			std::cout << "number increass" << '\n';
		}
		else { 
			std::cout << "number add" << '\n'; ;
			haveNum.push_back(i);
			muchNumIndex++;
		}
	} 


}