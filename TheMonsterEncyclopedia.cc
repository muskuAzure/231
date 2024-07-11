#include <iostream>
#include <string>
#include <limits>

struct Monster {
    std::string name;
    long hp;
    long att;
    long def;

    long power;

    void setMonsterInfo() {
        std::cin >> name >> hp >> att >> def;
        power = hp + (att * def);

    }

    void getMonsterInfo(){
        std::cout << name << ": (HP " << hp << " | " << att << "/" << def << ") - EVAL " << power;

    }
};

int main(void) {
    unsigned short int monNum;
    std::cin >> monNum;

    long min = LONG_MAX,max = LONG_MIN;
    int bookmarkForWeak, bookmarkForStrong;

    Monster *monsterBook = new Monster[monNum];

    for(int i = 0; monNum > i; i++){
        monsterBook[i].setMonsterInfo();

        if (monsterBook[i].power >= max) {
            max = monsterBook[i].power;
            bookmarkForStrong = i;

        }

        if (monsterBook[i].power <= min) {
            min = monsterBook[i].power;
            bookmarkForWeak = i;

        }
    }

    for(int i = 0; monNum > i ; i++) {
        monsterBook[i].getMonsterInfo();
        std::cout << "\n";
    }
    
    std::cout << "The weakest monster is " << monsterBook[bookmarkForWeak].name << " with evaluation of " << monsterBook[bookmarkForWeak].power << "\n";
    std::cout << "The strongest monster is " << monsterBook[bookmarkForStrong].name << " with evaluation of " << monsterBook[bookmarkForStrong].power;

    delete []monsterBook;

    return 0;
}