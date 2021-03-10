#include <bits/stdc++.h>

using namespace std;

const int sizeOfBoard = 4;
int a[sizeOfBoard][sizeOfBoard];

void intro()
{

}

void srcClear()
{
    const int numberRow = 30;
    for (int i=0; i<numberRow; ++i)
        cout << "\n";
}

void outBoard()
{
    for (int i=0; i<sizeOfBoard; ++i)
    {
        for (int j=0; j<sizeOfBoard; ++j)
            cout << "\t" << a[i][j];
        cout << "\n";
    }
}

void spawnNumber()
{
    int number = rand() % 2048 + 1;
    int vt = rand() % 16;
    number /= 128;
    if (number != 16 && number != 8 && number != 4)
        number = 2;

    for (int t=0; t<16; ++t)
        for (int i=0; i<sizeOfBoard; ++i)
            for (int j=0; j<sizeOfBoard; ++j)
            {
                if (a[i][j] != 0)
                    continue;
                if (vt == 0)
                {
                    a[i][j] = number;
                    return;
                }
                --vt;
            }
}

void gameplay()
{

    fill_n(&a[0][0], sizeOfBoard * sizeOfBoard, 0);
    srand(time(0));
    char c;
    while (cin >> c)
    {
        srcClear();
        spawnNumber();
        outBoard();

    }
}

int main()
{
    intro();
    gameplay();
}
