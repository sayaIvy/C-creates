#include "field.h"
#include <iostream>
#include <cstring>

#define BOARD_WIDTH 10
#define BOARD_HIGHT 10

using namespace std;

// コンストラクタ
Field::Field()
{
    cout << "Fieldコンストラクタ" << endl;
}
// デストラクタ
Field::~Field()
{
    cout << "Fieldデストラクタ" << endl;
}

void Field::createWall(char *position)
{
    if (position == "top" || position == "bottom") // top or bottom
    {
        for (int i = 0; i < BOARD_WIDTH + 2; i++)
        {
            cout << "-";
        }
        cout << endl;
    }
    else if (position == "right") // right
    {
        cout << "|" << endl;
    }
    else if (position == "left") // left
    {
        cout << "|";
    }
    else
    {
        cout << "引数をsideまたはtop,bottomでかいて" << endl;
    }
}
void Field::initBored()
{
    createWall(wallPosition = "top");
    for (int i = 0; i < BOARD_HIGHT; i++)
    {
        createWall(wallPosition = "left");
        for (int j = 0; j < BOARD_WIDTH; j++)
        {
            bored[i][j] = 0;
            cout << bored[i][j];
        }
        createWall(wallPosition = "right");
    }
    createWall(wallPosition = "bottom");
}