// this code is o((r*c) * ())

#include <iostream>

int main(void){ 
    int buffer[257][257], mostFarmYield;
    unsigned int row, column, manaHave, manaUse, availableSpell;

    std::cin >> row >> column;
    std::cin >> manaHave >> manaUse;

    availableSpell = manaHave/manaUse;

    // get num and put num in buffer
    for(unsigned int i = 0; column > i; i++ ){
        for(unsigned int j = 0; row > j; j++ ) {
            std::cin >> buffer[i][j];
        }
    }

    










    // gen blueprint for possible layout and loop in buffer to find the most number
    for(int startRow = 0; row > startRow; startRow++){
        for(int startColumn = 0; column > startColumn; startColumn++){
            

        }
    }
}

