// this code is o(n*s)

// i could use int but that would take more byte and there is't gurantee that shot int is avalible in target machine 
// my first thought is i want this program to be dynmic but i have concern about the runtime so i will set this progra to be static 

// i can do while(cin) and it will only use 1000 byte but it will waste run time so i choose to so getline instend because cin is "VERY S L O W" compare to other method in this case getline 

#include <iostream>

int main(void) {

    char rightAnswer[1001];
    short int studentScore[10001];
    short int studentNum, examNum; 

    std::cin >> studentNum >> examNum;

    short int examNumTime2 = (examNum - 1 ) * 2;

    std::cin.ignore();

    std::cin.getline(rightAnswer, 2000);

    //get 1 answer from atudent and check it and then put score in array studentScore
    for(int i = 0; studentNum > i ; i++){
        char studentAnswer[2001];
        std::cin.getline(studentAnswer, 2000);
        for(int j = 0;examNumTime2 >= j;j += 2){
            if(rightAnswer[j] == studentAnswer[j]) {
                studentScore[i]++;
            }
        }
    }

    for(int i = 0; studentNum > i ; i++) {
        std::cout << studentScore[i] << " ";
    }

}
