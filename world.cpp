//name: Codi Uhouse
//class: CSCI340 - Game Programming

//Defines game world class functions

#include <iostream>
#include <cmath>
#include <string>
#include "world.h"
#include "player.h"

using namespace std;

void World::Begin()
{
    for (int i = 0; i < MAX_LENGTH; i++)
    {
        for (int j = 0; j < MAX_HEIGHT; j++)
        {
             if (i % 2 == 0) {
                 board[i][j] = ' ';
             }
             else {
                 board[i][j] = '-';
             }

             board[i][j+1] = '|';
             j++;
        }
    }    

    return;
}

bool World::PlacePlayer(int space, char marker, bool ai, int tur)
{
    bool redo;

    bool condition = (!ai || (ai && tur % 2 != 0));

    switch (space)
    {
        case 9: if (board[4][4] != ' ')
                {
                    if (condition)
                        cout << "That space is already filled!" << endl << endl;
                    redo = true;
                    choice = ' ';
                }
                else
                {
                    board[4][4] = marker;
                    redo = false;
                    choice = 9;
                }
                break;
        case 8: if (board[4][2] != ' ')
                {
                    if (condition)
                        cout << "That space is already filled!" << endl << endl;
                    redo = true;
                    choice = ' ';
                }
                else
                {
                    board[4][2] = marker;
                    redo = false;
                    choice = 8;
                }
                break;
        case 7: if (board[4][0] != ' ')
                {
                    if (condition)
                        cout << "That space is already filled!" << endl << endl;
                    redo = true;
                    choice = ' ';
                }
                else
                {
                    board[4][0] = marker;
                    redo = false;
                    choice = 7;
                }
                break;
        case 6: if (board[2][4] != ' ')
                {
                    if (condition)
                        cout << "That space is already filled!" << endl << endl;
                    redo = true;
                    choice = ' ';
                }
                else
                {
                    board[2][4] = marker;
                    redo = false;
                    choice = 6;
                }
                break;
        case 5: if (board[2][2] != ' ')
                {
                    if (condition)
                        cout << "That space is already filled!" << endl << endl;
                    redo = true;
                    choice = ' ';
                }
                else
                {
                    board[2][2] = marker;
                    redo = false;
                    choice = 5;
                }
                break;
        case 4: if (board[2][0] != ' ')
                {
                    if (condition)
                        cout << "That space is already filled!" << endl << endl;
                    redo = true;
                    choice = ' ';
                }
                else
                {
                    board[2][0] = marker;
                    redo = false;
                    choice = 4;
                }
                break;
        case 3: if (board[0][4] != ' ')
                {
                    if (condition)
                        cout << "That space is already filled!" << endl << endl;
                    redo = true;
                    choice = ' ';
                }
                else
                {
                    board[0][4] = marker;
                    redo = false;
                    choice = 3;
                }
                break;
        case 2: if (board[0][2] != ' ')
                {
                    if (condition)
                        cout << "That space is already filled!" << endl << endl;
                    redo = true;
                    choice = ' ';
                }
                else
                {
                    board[0][2] = marker;
                    redo = false;
                    choice = 2;
                }
                break;
        case 1: if (board[0][0] != ' ')
                {
                    if (condition)
                        cout << "That space is already filled!" << endl << endl;
                    redo = true;
                    choice = ' ';
                }
                else
                {
                    board[0][0] = marker;
                    redo = false;
                    choice = 1;
                }
                break;
        default: return true;
    }

    return redo;
}


void World::PrintMap()
{
    for (int i = 0; i < MAX_LENGTH; i++)
    {
        for (int j = 0; j < MAX_HEIGHT; j++)
        {
             cout << board[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    return;
}


bool World::CheckWin()
{
    bool win = false;
    int checkStart = 0;
    char mark;

    bool equalOne = (board[checkStart][checkStart] == board[checkStart][checkStart + 2]);
    bool equalTwo = (board[checkStart][checkStart] == board[checkStart][checkStart + 4]);
    bool nonZeroOne = ((board[checkStart][checkStart] != ' ' && board[checkStart][checkStart + 2] != ' ') && board[checkStart][checkStart + 4] != ' ');
    bool equalThree = (board[checkStart + 2][checkStart] == board[checkStart + 2][checkStart + 2]);
    bool equalFour = (board[checkStart + 2][checkStart] == board[checkStart + 2][checkStart + 4]);
    bool nonZeroTwo = ((board[checkStart + 2][checkStart] != ' ' && board[checkStart + 2][checkStart + 2] != ' ') && board[checkStart + 2][checkStart + 4] != ' ');
    bool equalFive = (board[checkStart + 4][checkStart] == board[checkStart + 4][checkStart + 2]);
    bool equalSix = (board[checkStart + 4][checkStart] == board[checkStart + 4][checkStart + 4]);
    bool nonZeroThree = ((board[checkStart + 4][checkStart] != ' ' && board[checkStart + 4][checkStart + 2] != ' ') && board[checkStart + 4][checkStart + 4] != ' ');
    //-------------------------------------------------------------------------------------------------------
    bool equalSeven = (board[checkStart][checkStart] == board[checkStart + 2][checkStart + 2]);
    bool equalEight = (board[checkStart][checkStart] == board[checkStart + 4][checkStart + 4]);
    bool nonZeroFour = ((board[checkStart][checkStart] != ' ' && board[checkStart + 2][checkStart + 2] != ' ') && board[checkStart + 4][checkStart + 4] != ' '); 
    bool equalNine = (board[checkStart + 4][checkStart] == board[checkStart + 2][checkStart + 2]);
    bool equalTen = (board[checkStart + 4][checkStart] == board[checkStart][checkStart + 4]);
    bool nonZeroFive = ((board[checkStart + 4][checkStart] != ' ' && board[checkStart + 2][checkStart + 2] != ' ') && board[checkStart][checkStart + 4] != ' ');
    bool equalEleven = (board[checkStart][checkStart] == board[checkStart + 2][checkStart]);
    bool equalTwelve = (board[checkStart][checkStart] == board[checkStart + 4][checkStart]);
    bool nonZeroSix = ((board[checkStart][checkStart] != ' ' && board[checkStart + 2][checkStart] != ' ') && board[checkStart + 4][checkStart] != ' ');
    //-------------------------------------------------------------------------------------------------------
    bool equalThirteen = (board[checkStart][checkStart + 2] == board[checkStart + 2][checkStart + 2]);
    bool equalFourteen = (board[checkStart][checkStart + 2] == board[checkStart + 4][checkStart + 2]);
    bool nonZeroSeven = ((board[checkStart][checkStart + 2] != ' ' && board[checkStart + 2][checkStart + 2] != ' ') && board[checkStart + 4][checkStart + 2] != ' ');
    bool equalFifteen = (board[checkStart][checkStart + 4] == board[checkStart + 2][checkStart + 4]);
    bool equalSixteen = (board[checkStart + 2][checkStart + 4] == board[checkStart + 4][checkStart + 4]);
    bool nonZeroEight = ((board[checkStart][checkStart + 4] != ' ' && board[checkStart + 2][checkStart + 4] != ' ') && board[checkStart + 4][checkStart + 4] != ' ');

    if ((equalOne && equalTwo) && nonZeroOne)
    {
        mark = board[checkStart][checkStart];
    }
    else if ((equalThree && equalFour) && nonZeroTwo)
    {
        mark = board[checkStart + 2][checkStart + 2];
    }
    else if ((equalFive && equalSix) && nonZeroThree)
    {
        mark = board[checkStart + 4][checkStart + 2];
    }
    else if ((equalSeven && equalEight) && nonZeroFour)
    {
        mark = board[checkStart][checkStart];
    }
    else if ((equalNine && equalTen) && nonZeroFive)
    {
        mark = board[checkStart + 4][checkStart];
    }
    else if ((equalEleven && equalTwelve) && nonZeroSix)
    {
        mark = board[checkStart][checkStart];
    }
    else if ((equalThirteen && equalFourteen) && nonZeroSeven)
    {
        mark = board[checkStart][checkStart + 2];
    }
    else if ((equalFifteen && equalSixteen) && nonZeroEight)
    {
        mark = board[checkStart][checkStart + 4];
    }
    else
    {
        mark = ' ';
    }

    if (mark == 'X')
    {
        win = true;
        cout << "Player 1 Wins!" << endl << endl;
    }
    else if (mark == 'O')
    {
        win = true;
        cout << "Player 2 Wins!" << endl << endl;
    }
    else if ((nonZeroOne && nonZeroTwo) && nonZeroThree)
    {
        win = true;
        cout << "Draw!" << endl << endl;
    }


    return win;
}
