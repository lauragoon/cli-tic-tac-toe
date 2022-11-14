#include <cstdlib>
#include <iostream>
using namespace std;


void draw()
{
    system("clear");
    cout << "Let's play Tic-Tac-Toe!\n\n" << endl;

    for (int i = 0; i < 8; i++)
    {
        if ((i+1) % 3 == 0)
        {
            cout << "-----|-----|-----" << endl;
        }
        else
        {
            cout << "     |     |     " << endl;
        }
    }

    cout << "\n\n";
}

int main()
{
    draw();

    // while (1)
    // {
    //     draw();
    // }

    return 0;
}