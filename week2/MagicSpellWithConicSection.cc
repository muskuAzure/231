#include <iostream>
#include <string>

struct Point {
    int x,y,sum;
};

int main(void){
    std::string spellArea,buffer;
    short int numEnemyPosition;
    bool isNegative,isPower,isY,isX,isOtherSide;

    std::cin >> numEnemyPosition;
    Point *allEnemyPosition = new Point[numEnemyPosition];

    for(int i = 0;numEnemyPosition > i;i++){
        std::cin >> allEnemyPosition[i].x;
        std::cin >> allEnemyPosition[i].y;
    }

    std::cin >> spellArea;
    spellArea += '+';

    for ( std::string::iterator it = spellArea.begin(); it != spellArea.end(); ++it){

        if(*it == '-' && buffer.empty()) {
            isNegative = true;
            continue;
        } 

        if( *it == '-' || *it == '+' || *it == '=' ){

            int holdNum = stoi(buffer); //stoi(buffer)
            int temp = 0;

            for(int i = 0; numEnemyPosition > i; i++){
 
                if(isY) {
                    if(isPower) temp = holdNum * pow(allEnemyPosition[i].y, 2); 
                    else temp = holdNum * allEnemyPosition[i].y;
                } else if(isX) {
                    if(isPower) temp = holdNum * pow(allEnemyPosition[i].x, 2); 
                    else temp = holdNum * allEnemyPosition[i].x;
                } else {
                    temp += holdNum;
                }

                if(!isOtherSide){
                    if(isNegative) allEnemyPosition[i].sum -= temp;
                    else  allEnemyPosition[i].sum += temp; 
                } else {
                    if(isNegative) allEnemyPosition[i].sum += temp;
                    else  allEnemyPosition[i].sum -= temp; 
                }
            } 

            if(*it == '-')  isNegative = true;
            else    isNegative = false;
            
            isY = false;
            isX = false;
            isPower = false;
            buffer.clear();
        }


        if(*it == '^'){
            isPower = true;
            continue;
        }

        if(*it != '-' && *it != '+' && !isPower) {
            if(*it != 'x' && *it != 'y' && *it != '=') buffer += *it;
            else if (*it == 'y') {
                isY = true;
                if(buffer.empty()) buffer += '1';
            }
            else if (*it == 'x') {
                isX = true;
                if(buffer.empty()) buffer += '1';
            }
            else if (*it == '=') isOtherSide = true;

        }

    }

    for(int i = 0;numEnemyPosition > i;i++){
        std::cout << "("<< allEnemyPosition[i].x << " ,"<<allEnemyPosition[i].y<< ") ";
        if(allEnemyPosition[i].sum) std::cout << "FALSE\n";
        else std::cout << "TRUE\n";
    }
} 