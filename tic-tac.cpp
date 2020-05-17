//name: Codi Uhouse
//class: CSCI340 - Game Programming

#include <string>
#include <cmath>
#include <iostream>
#include "world.h"
#include "player.h"

using namespace std;


int main() {
    World tic;
    Player playerRep;
    bool gameWon = false;
    bool playAgain = true;
    bool redoTurn;
    bool play;
    int spaceVal, marker;

    playerRep.AskPlayerCount();

    playerRep.turn = 1;

    tic.Begin();
    tic.PrintMap();

    while(playAgain)
    {
        while(!gameWon)
        {
            if (!playerRep.aI || playerRep.turn % 2 != 0)
            {
                spaceVal = playerRep.AskPosition();
            }
            else
            {
                spaceVal = playerRep.AIChoice();
            }

            if (playerRep.secondPlayer == true)
            {
                if (playerRep.turn % 2 == 0)
                {
                    marker = playerRep.PLAYER_1_VALUE;
                }
                else
                {
                    marker = playerRep.PLAYER_2_VALUE;
                }
            }
            else if (!playerRep.secondPlayer && playerRep.turn % 2 != 0)
            {
                marker = playerRep.PLAYER_2_VALUE;
            }
            else
            {
                marker = playerRep.PLAYER_1_VALUE;
            }


            redoTurn = tic.PlacePlayer(spaceVal, marker, playerRep.aI, playerRep.turn);

            playerRep.UpdateChoiceArray(tic.choice);                       

            while (redoTurn)
            {
                if (playerRep.aI && playerRep.turn % 2 == 0)
                {
                    playerRep.reroll = true;
                    spaceVal = playerRep.AIChoice();
                    redoTurn = tic.PlacePlayer(spaceVal, marker, playerRep.aI, playerRep.turn);

                    playerRep.UpdateChoiceArray(tic.choice);
                }
                else
                {
                    spaceVal = playerRep.AskPosition();
                    redoTurn = tic.PlacePlayer(spaceVal, marker, playerRep.aI, playerRep.turn);

                    playerRep.UpdateChoiceArray(tic.choice);
                }
            }

            playerRep.reroll = false;
    
            tic.PrintMap();
            
            gameWon = tic.CheckWin();
    
            playerRep.turn++;
        }

        cout << endl << "Play Again (1 or 0)? ";
        cin >> play;
        cout << endl;

        playAgain = play;

        if (!playAgain)
        {
            return 0;
        }

        gameWon = false;
        
        playerRep.AskPlayerCount();
        tic.Begin();
        tic.PrintMap();

        playerRep.turn = 1;
    }

    return 0;
}
