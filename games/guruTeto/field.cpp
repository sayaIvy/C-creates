#include "field.h"
#include <iostream>
#include <string.h>

#define BOARD_WIDTH 10
#define BOARD_HIGHT 10

using namespace std;

// コンストラクタ
Field::Field() : wallRight(0), wallLeft(1), wallTop(2), wallBottom(3)
{
    cout << "Fieldコンストラクタ" << endl;
}
// デストラクタ
Field::~Field()
{
    cout << "Fieldデストラクタ" << endl;
}

void Field::createWall(int position)
{
    if (position == 2 || position == 3) // top or bottom
    {
        for (int i = 0; i < BOARD_WIDTH + 2; i++)
        {
            cout << "-";
        }
        cout << endl;
    }
    else if (position == 0) // right
    {
        cout << "|" << endl;
    }
    else if (position == 1) // left
    {
        cout << "|";
    }
    else
    {
        cout << "引数をsideまたはtop,bottomでかいて" << endl;
    }
}
void Field::createBored()
{
    createWall(wallTop);
    for (int i = 0; i < BOARD_HIGHT; i++)
    {
        createWall(wallLeft);
        for (int j = 0; j < BOARD_WIDTH; j++)
        {
            bored[i][j] = 0;
            cout << bored[i][j];
        }
        createWall(wallRight);
    }
    createWall(wallBottom);
}