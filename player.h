//name: Codi Uhouse
//class: CSCI340 - Game Programming

//Holds actions related to players

#include <iostream>
#include <cmath>
#include <string>


class Player {
    private:
        int numPlayers;

    public:
        void AskPlayerCount();
        int AskPosition();
        int AIChoice();
        bool UpdateChoiceArray(int num);
        int SmartChoice();

        static const char PLAYER_1_VALUE = 'O';
        static const char PLAYER_2_VALUE = 'X';
        int turn;
        bool reroll;
        bool secondPlayer;
        bool aI;
        int playerArr[5];
        int aIArray[5];
        bool smartCheck;
        char firstVal;
        char secondVal;
};
