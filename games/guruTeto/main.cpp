#include <iostream>
#include <stdlib.h>
#include "field.h"

#define FIELD_WIDTH 12
#define FIELD_HEIGHT 24

// char field[FIELD_HEIGHT][FIELD_WIDTH];

using namespace std;

int main()
{
    // ミノを親クラスとしていろんな形のミノを子クラスにしたいけど百年後
    //  memset(field, 0, sizeof(field));
    //  for (int i = 0; i < FIELD_HEIGHT; i++)
    //  {
    //      field[i][0] = 1;
    //  }
    //  int getch()
    Field a;
    a.createBored();
    return 0;
}