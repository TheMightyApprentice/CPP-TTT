//name: Codi Uhouse
//class: CSCI340 - Game Programming

//Defines actions that can be made by players.

#include <iostream>
#include <cmath>
#include <string>
#include "player.h"
#include "world.h"
#include <cstdlib>

using namespace std;


void Player::AskPlayerCount()
{
    cout << endl << "Enter player count (1 or 2): ";
    cin >> numPlayers;
    cout << endl;

    if (numPlayers == 1)
    {
        secondPlayer = false;
        aI = true;
    }
    else
    {
        secondPlayer = true;
        aI = false;
    }

    return;
}


int Player::AskPosition()
{
    int spaceWanted;
    char marker;

    if (!secondPlayer || turn % 2 != 0)
    {
        cout << "Player 1 which space would you like (1-9)? ";        
    }    
    else
    {
        cout << "Player 2 which space would you like (1-9)? ";
    }

    cin >> spaceWanted;
    cout << endl;

    return spaceWanted;
}


int Player::AIChoice()
{
    int choice;
    int rng = 0;

    smartCheck = true;

    int smart = SmartChoice();

    smartCheck = false;

    if (reroll)
    {
        rng ++;

        srand (time(0)); 
        choice = rand() % 10 + 1;
    }
    else
    {
       if (smart == 0)
       {
           cout << "AI is choosing." << endl << endl;

           srand (time(0));
           choice = rand() % 10;
       }
       else
       {
           cout << "AI is choosing." << endl << endl;

           choice = smart;
       }
    }

    return choice;
}


int Player::SmartChoice()
{
    int horzCheck = 2;
    int vertCheck = 4;
    int diagCheck = 5;
    int chvalue = 0;

    firstVal = ' ';
    secondVal = ' ';

    bool sameVal = ((firstVal == secondVal) && (firstVal != ' ' && secondVal != ' '));

    if (((!UpdateChoiceArray(horzCheck) && !UpdateChoiceArray(horzCheck + 1)) || (!UpdateChoiceArray(vertCheck) && !UpdateChoiceArray(vertCheck + 3))) || (!UpdateChoiceArray(diagCheck) && !UpdateChoiceArray(diagCheck + 4)))
    {
        sameVal = ((firstVal == secondVal) && (firstVal != ' ' && secondVal != ' '));

        if (sameVal)
        {
            chvalue = 1;
        }
    }
    else if ((!UpdateChoiceArray(horzCheck - 1) && !UpdateChoiceArray(horzCheck + 1)) || (!UpdateChoiceArray(vertCheck + 1) && !UpdateChoiceArray(vertCheck + 4)))
    {
        sameVal = ((firstVal == secondVal) && (firstVal != ' ' && secondVal != ' '));

        if (sameVal)
        {
            chvalue = 2;
        }
    }
    else if (((!UpdateChoiceArray(horzCheck) && !UpdateChoiceArray(horzCheck - 1)) || (!UpdateChoiceArray(vertCheck + 2) && !UpdateChoiceArray(vertCheck + 5))) || (!UpdateChoiceArray(vertCheck) && !UpdateChoiceArray(vertCheck + 2)))
    {
        sameVal = ((firstVal == secondVal) && (firstVal != ' ' && secondVal != ' '));

        cout << "3";

        if (sameVal)
        {
            chvalue = 3;
        }
    }
    else if ((!UpdateChoiceArray(horzCheck + 3) && !UpdateChoiceArray(horzCheck + 4)) || (!UpdateChoiceArray(vertCheck - 3) && !UpdateChoiceArray(vertCheck + 3)))
    {
        sameVal = ((firstVal == secondVal) && (firstVal != ' ' && secondVal != ' '));

        if (sameVal)
        {
            chvalue = 4;
        }
    }
    else if (((!UpdateChoiceArray(horzCheck + 2) && !UpdateChoiceArray(horzCheck + 4)) || (!UpdateChoiceArray(vertCheck - 2) && !UpdateChoiceArray(vertCheck + 4))) || ((!UpdateChoiceArray(diagCheck - 4) && !UpdateChoiceArray(diagCheck + 4)) || (!UpdateChoiceArray(diagCheck - 2) && !UpdateChoiceArray(diagCheck + 2))))
    {
        sameVal = ((firstVal == secondVal) && (firstVal != ' ' && secondVal != ' '));

        if (sameVal)
        {
            chvalue = 5;
        }
    }
    else if ((!UpdateChoiceArray(horzCheck + 3) && !UpdateChoiceArray(horzCheck + 2)) || (!UpdateChoiceArray(vertCheck - 1) && !UpdateChoiceArray(vertCheck + 5)))
    {
        sameVal = ((firstVal == secondVal) && (firstVal != ' ' && secondVal != ' '));

        if (sameVal)
        {
            chvalue = 6;
        }
    }
    else if (((!UpdateChoiceArray(horzCheck + 6) && !UpdateChoiceArray(horzCheck + 7)) || (!UpdateChoiceArray(vertCheck - 1) && !UpdateChoiceArray(vertCheck))) || (!UpdateChoiceArray(diagCheck - 2) && !UpdateChoiceArray(diagCheck)))
    {
        sameVal = ((firstVal == secondVal) && (firstVal != ' ' && secondVal != ' '));

        if (sameVal)
        { 
            chvalue = 7;
        }
    }
    else if (!UpdateChoiceArray(horzCheck + 5) && !UpdateChoiceArray(horzCheck + 7))
    {
        sameVal = ((firstVal == secondVal) && (firstVal != ' ' && secondVal != ' '));

        if (sameVal)
        {
            chvalue = 8;
        }
    }
    else if (((!UpdateChoiceArray(horzCheck +6) && !UpdateChoiceArray(horzCheck + 5)) || (!UpdateChoiceArray(vertCheck - 1) && !UpdateChoiceArray(vertCheck + 2))) || (!UpdateChoiceArray(diagCheck - 4) && !UpdateChoiceArray(horzCheck + 4)))
    {
        sameVal = ((firstVal == secondVal) && (firstVal != ' ' && secondVal != ' '));

        if (sameVal)
        {
            chvalue = 9;
        }
    }

    firstVal = ' ';
    secondVal = ' ';

    return chvalue;
}


bool Player::UpdateChoiceArray(int num)
{
    int index = 0;
    int value;
    bool updated = false;


    if (turn % 2 != 0 || smartCheck)
    {
        while (index <= 5)
        {
            value = playerArr[index];

            if (value == num && firstVal != secondVal)
            {
                if (firstVal != ' ')
                {
                    secondVal = 'X';
                }
                else
                {
                    firstVal = 'X';
                }
            }
            else if (value == ' ')
            {
                playerArr[index] = num;
                updated = true;

                return updated;
            }

            index++;
        }
    }


    if (turn % 2 == 0 || smartCheck)
    {
        while (index <= 5)
        {
            value = aIArray[index];

            if (value == num && firstVal != secondVal)
            {
                if (firstVal != ' ')
                {
                    secondVal = 'O';
                }
                else
                {
                    firstVal = 'O';
                }
            }
            else if (value == ' ')
            {
                aIArray[index] = num;
                updated = true;

                return updated;
            }
        
            index++;
        }
    }

    return updated;
}


