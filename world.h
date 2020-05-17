//name: Codi Uhouse
//class: CSCI340 - Game Programming

//Holds game world class functions

#include <iostream>
#include <cmath>
#include <string>


class World {
    private:
       static const int MAX_LENGTH = 5;
       static const int MAX_HEIGHT = 5;

    public:
       //Initializes board
       void Begin();
       //Puts player's marker in selected space.
       bool PlacePlayer(int space, char marker, bool ai, int tur);
       //Outputs current state of board
       void PrintMap();
       //Checks to see if a player has won
       bool CheckWin();

       char board[MAX_LENGTH][MAX_HEIGHT];
       char choice;
};

