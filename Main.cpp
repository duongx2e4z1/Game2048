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

    if (vt != 0)
        exit(0);
}

void changeLR()
{
    for (int i=0; i<sizeOfBoard; ++i)
        for (int j=0;j<sizeOfBoard/2; ++j)
            swap(a[i][j], a[i][sizeOfBoard-j-1]);
}

void changeLU()
{
    for (int i=0; i<sizeOfBoard; ++i)
        for (int j=i+1; j<sizeOfBoard; ++j)
            swap(a[i][j], a[j][i]);
}

void lef()
{
    for (int i=0; i<sizeOfBoard; ++i)
    {
        deque <int> dq;
        for (int j=0; j<sizeOfBoard; ++j)
        {
            if (a[i][j] == 0)
                continue;
            if (!dq.empty() && dq.back() == a[i][j])
            {
                dq.pop_back();
                dq.push_back(a[i][j] * 2);
            }
            else
                dq.push_back(a[i][j]);
        }
        for (int j=0; j<sizeOfBoard; ++j)
            if (!dq.empty())
            {
                a[i][j] = dq.front();
                dq.pop_front();
            }
            else
                a[i][j] = 0;
    }
}

void rig()
{
    changeLR();
    lef();
    changeLR();
}

void up()
{
    changeLU();
    lef();
    changeLU();
}

void down()
{
    changeLU();
    rig();
    changeLU();
}

void getmove(char c)
{
    if (c == 'a')
        lef();
    if (c == 'd')
        rig();
    if (c == 'w')
        up();
    if (c == 's')
        down();
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
        getmove(c);
    }
}

int main()
{
    intro();
    gameplay();
}
