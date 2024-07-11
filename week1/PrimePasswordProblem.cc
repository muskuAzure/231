// this code is o(sqrt(n))

#include <iostream>
#include <cmath>

int main(void) {

	unsigned int inputNum;
	std::cin >> inputNum;

	unsigned int rootNum = sqrt(inputNum);

	std::cout << inputNum << " = ";

	for ( unsigned int i = 2; rootNum >= i  ; ++i) {
		unsigned int numTime = 0;
		while(! (inputNum % i) ) {
			inputNum /= i;
			numTime++;

		}

		if(numTime) { 
			std::cout << i;
			if(--numTime){
				std::cout << "^" << ++numTime;
			}
		} else { continue; }

		if ( inputNum > i ) {		
		std::cout << " x ";
		}
	}

	if(inputNum > 1) {
		std::cout << inputNum;
	}

	return 0;
}

