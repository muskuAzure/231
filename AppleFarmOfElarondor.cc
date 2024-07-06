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

    //std::cout << '\n'; //frefvaefaevdfs

    // pick step size and the size will not excess the row limit or mana
    // pick column 
    // walk row (walk only one time) 
    // check if mana left enough for next walk in new column
    // check if pick more than 1 column then 
    // go to that column and walk row


    for(int startColumn = 0; column > startColumn; startColumn++){
        for(int startRow = 0; row > startRow; startRow++){
            // std::cout << startColumn << " " << startRow << '\n'; // wefdcjarefjkwjkaerjnk
            for(int useSpellInRow = 1; availableSpell >= useSpellInRow && row >= useSpellInRow; useSpellInRow++) {
                long int temp = 0;
                int columnLimit = (availableSpell/useSpellInRow);
                if (columnLimit > column) { columnLimit = column; }
                // std::cout << "col limit = " << columnLimit << '\n';   //rf/wvafedreavsdvra
                // std::cout << "useSpellInRow = " << useSpellInRow << '\n'; //wevavrseafervfrfeda
                // std::cout << '\n'; //wevavrseafervfrfeda
                for(int i = startColumn; (columnLimit+startColumn) > i;i++){

                    //std::cout <<"col enter \n"; // test
                    

                    for(int j = startRow; (useSpellInRow+startRow) > j;j++){
                        //std::cout <<"row enter \n"; // refcvkmefmkofvkomef
                        temp += buffer[i][j];
                        if(temp > appleYield) {appleYield = temp;}
                    }
                    //std::cout << '\n'; //wevavrseafervfrfeda

                }
                //std::cout << "\n"; //fwdfvdfvsvdfs
            }
        }
    }

    std::cout << appleYield;

    return 0;

}

