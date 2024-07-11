// this code is o(n^5)
// could be n^4 just use 1 d array
// this is v1 

#include <iostream>

int main(void){ 
    int buffer[257][257], mostFarmYield;
    long int appleYield = 0;
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

    // get step size and how many columna it can walk with that step
    for(int startColumn = 0; column > startColumn; startColumn++){
        for(int startRow = 0; row > startRow; startRow++){
            for(int useSpellInRow = 1; availableSpell >= useSpellInRow && row >= useSpellInRow; useSpellInRow++) {
                long int temp = 0;
                int columnLimit = (availableSpell/useSpellInRow);
                if (columnLimit > column) { columnLimit = column; }
                for(int i = startColumn; (columnLimit+startColumn) > i;i++){                    
                    for(int j = startRow; (useSpellInRow+startRow) > j;j++){
                        temp += buffer[i][j];
                        if(temp > appleYield) {appleYield = temp;}
                    }

                }
            }
        }
    }

    std::cout << appleYield;

    return 0;

}

