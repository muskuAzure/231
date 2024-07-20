#include <cctype>
#include <iostream>
#include <string>


int main(void){
    std::string input;
    std::cin >> input;

    std::string allWord[10],buffer;
    int i = 0,j = 1;
    bool isDigit = false, isUpper = false, isLower = false;

    for ( std::string::iterator it = input.begin(); it != input.end(); ++it){

        if(!j){
            if(isLower) {
                if(islower(*it)){
                    buffer += *it;
                } else {
                    allWord[i] += buffer;
                    buffer.clear();
                    j++;
                    i++;
                    isLower = false;

                }
            }else if(isUpper){

                if(isupper(*it)) {

                    if(islower(*(--buffer.end()))){
                        allWord[i] += buffer;
                        buffer.clear();
                        i++;
                        j++;
                        isUpper = false;
                    } else {
                        buffer += *it;
                    }

                } else if(islower(*it)) {
                    if (buffer.length() > 1 && !islower(*(--buffer.end()))){
                        std::string temp;
                        temp += *(--buffer.end());
                        buffer.erase(--buffer.end());
                        allWord[i] += buffer;
                        buffer.clear();
                        buffer += temp;
                        i++;
                        j++;
                        isUpper = false;                    
                    } else {
                        buffer += *it;
                    }
                } else { 
                    allWord[i] += buffer;
                    buffer.clear();
                    j++;
                    i++;
                    isUpper = false;                    
                }

            }else if(isDigit){
                if(isdigit(*it)){
                    buffer += *it;
                } else{                    
                    allWord[i] += buffer;
                    buffer.clear();
                    j++;
                    i++;
                    isDigit = false;
                }
            }
        }

        if(j){
            if(islower(*it)) {
                isLower = true;
            } else if(isdigit(*it)) {
                isDigit = true;
            } else if(isupper(*it)) {
                isUpper = true;
            }
            buffer += *it;
            j--;
        }


        if(it == --input.end() ) {
            allWord[i] += buffer;
        } 
    }

    for (int j = 0 ; i >= j; j++){
        bool flag = true;
        for ( std::string::iterator it = allWord[j].begin(); it != allWord[j].end(); ++it){
            if(flag) {
                std::cout << (char)toupper(*it);
                flag = false;
            } else {
                std::cout << *it;
            }
        }
        std::cout << " ";
    }

    return 0;
}