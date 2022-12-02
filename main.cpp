#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// https://stackoverflow.com/a/5590404
#define SSTR(x) static_cast<std::ostringstream &>( \
        (std::ostringstream() << std::dec << x)).str()


char gameMatrix[3][3] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
char currPlayer = 'X';

void draw()
{
    system("clear");
    cout << "Let's play Tic-Tac-Toe!\n\n" << endl;

    cout << "     A     B     C  " << endl;

    for (int i = 0; i < 7; i++)
    {
        if (i == 2 || i == 4)
        {
            cout << "   -----|-----|-----" << endl;
        }
        else if (i%2 == 1)
        {
            string outStr("");

            int idxNum = i==1 ? 1 : i==3 ? 2 : 3;
            ostringstream tempIdxNum;
            tempIdxNum << idxNum;
            outStr.append(tempIdxNum.str()).append("  ");

            for (int j = 0; j < 3; j++)
            {
                if (j > 0) outStr.append("|");
                outStr.append("  ");
                outStr += gameMatrix[i==1 ? 0 : i==3 ? 1 : 2][j];
                outStr.append("  ");
            }
            cout << outStr << endl;
        }
        else
        {
            cout << "        |     |     " << endl;
        }
    }

    cout << "\n\n";
}

void input()
{
    string userInp("");
    
    string userInpQuery("[Player ");
    userInpQuery += currPlayer;
    userInpQuery.append("] What's your next move? (ex. A1 or B3) ");

    cout << userInpQuery;
    cin >> userInp;
    
    int inpRow = -1;
    int inpCol = -1;

    if (userInp == "A1")
    {
        inpRow = 0;
        inpCol = 0;
    }
    else if (userInp == "B1")
    {
        inpRow = 0;
        inpCol = 1;
    }
    else if (userInp == "C1")
    {
        inpRow = 0;
        inpCol = 2;
    }
    else if (userInp == "A2")
    {
        inpRow = 1;
        inpCol = 0;
    }
    else if (userInp == "B2")
    {
        inpRow = 1;
        inpCol = 1;
    }
    else if (userInp == "C2")
    {
        inpRow = 1;
        inpCol = 2;
    }
    else if (userInp == "A3")
    {
        inpRow = 2;
        inpCol = 0;
    }
    else if (userInp == "B3")
    {
        inpRow = 2;
        inpCol = 1;
    }
    else if (userInp == "C3")
    {
        inpRow = 2;
        inpCol = 2;
    }
    else
    {
        cout << "You've entered an invalid input." << endl;
        input();
        return;
    }

    if (gameMatrix[inpRow][inpCol] != ' ')
    {
        cout << "You can't choose a square already written in." << endl;
        input();
        return;
    }
    
    gameMatrix[inpRow][inpCol] = currPlayer;
}

char gameWon()
{
    if ((gameMatrix[0][0] == gameMatrix[0][1] && gameMatrix[0][1] == gameMatrix[0][2]) || \
        (gameMatrix[0][0] == gameMatrix[1][0] && gameMatrix[1][0] == gameMatrix[2][0]) || \
        (gameMatrix[0][0] == gameMatrix[1][1] && gameMatrix[1][1] == gameMatrix[2][2]))
        return gameMatrix[0][0];
    if ((gameMatrix[1][0] == gameMatrix[1][1] && gameMatrix[1][1] == gameMatrix[1][2]) || \
        (gameMatrix[0][1] == gameMatrix[1][1] && gameMatrix[1][1] == gameMatrix[2][1]) || \
        (gameMatrix[2][0] == gameMatrix[1][1] && gameMatrix[1][1] == gameMatrix[0][2]))
        return gameMatrix[1][1];
    if ((gameMatrix[2][0] == gameMatrix[2][1] && gameMatrix[2][1] == gameMatrix[2][2]) || \
        (gameMatrix[0][2] == gameMatrix[1][2] && gameMatrix[1][2] == gameMatrix[2][2]))
        return gameMatrix[2][2];

    bool foundEmpty = false;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (gameMatrix[i][j] == ' ')
            {
                foundEmpty = true;
                break;
            }
        }
    }
    if (foundEmpty == false) return '-';

    return ' ';
}

void switchPlayer()
{
    if (currPlayer == 'X') currPlayer = 'O';
    else currPlayer = 'X';
}

int main()
{
    draw();

    while (1)
    {
        input();
        draw();

        if (gameWon() == 'X')
        {
            cout << "We have a WINNER! Congrats Player X" << endl;
            break;
        }
        else if (gameWon() == 'O')
        {
            cout << "We have a WINNER! Congrats Player O" << endl;
            break;
        }
        else if (gameWon() == '-')
        {
            cout << "We have a TIE!" << endl;
            break;
        }
        
        switchPlayer();
    }

    return 0;
}