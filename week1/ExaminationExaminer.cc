
// this code is o(e*s^2)

// if the range of the mutiple choice is more than 9 (decimal) this code will not not work probably 
// in that case you should switch to using numeric type to hold data but again the range may be excess in that case you should store data in string of char by spliting the white space

#include <iostream>

int main(void) {

    int rightAnswer[1001];
    int studentScore[10001];
    int studentNum, examNum; 

    std::cin >> studentNum >> examNum;

    std::cin.ignore();

    // get the right answer 
    for(int i = 0; examNum > i; i++){
        std::cin >> rightAnswer[i];
    }

    std::cin.ignore();

    // std::cin.getline(rightAnswer, 2000);

    //get 1 answer from student and check it and then put score in array studentScore
    for(int i = 0; studentNum > i ; i++){
        int studentAnswer[1001];
        for(int j = 0; examNum > j; j++){
        std::cin >> studentAnswer[j];
            if ( studentAnswer[j] == rightAnswer[j] ){
                studentScore[i]++;
            }
        }
    }

    for(int i = 0; studentNum > i ; i++) {
        std::cout << studentScore[i] << " ";
    }

}

//v2
// 


// v1
// i could use int but that would take more byte and there is't gurantee that shot int is avalible in target machine 
// my first thought is i want this program to be dynmic but i have concern about the runtime so i will set this progra to be static *_*

// i can do while(cin) and it will only use 1000 byte but it will waste run time so i choose to so getline instend because cin is "VERY S L O W" compare to other method in this case getline 

// test 
