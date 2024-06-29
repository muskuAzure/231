// this code is o(n)

#include <iostream>

int main(void) {

	unsigned int inputNum;
	std::cin >> inputNum;

	std::cout << inputNum << " = ";

	for ( unsigned int i = 2; inputNum >= i  ; ++i) {
		unsigned int numTime = 0;
		while(! (inputNum % i)) {
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
 
	return 0;
}

