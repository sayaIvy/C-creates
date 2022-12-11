// #include <iostream>
// #include <stdlib.h>
// #include "field.h"

// #define FIELD_WIDTH 12
// #define FIELD_HEIGHT 24

// // char field[FIELD_HEIGHT][FIELD_WIDTH];

// using namespace std;

// int main()
// {
//     Field a;
//     a.initBored();
//     return 0;
// }

#include <stdio.h>
#define clearScreen() printf("/033[2]")
#define setPosition(x, y) printf("/033[%d;%dH", (y), (x))
#define setCharColor(n) printf("/033[3%dm", (n))
#define setBackColor(n) printf("/033[4%dm", (n))
#define BLACK 0
#define RED 1
#define GREEN 2
#define YELLOW 3
#define BLUE 4
#define MAGENTA 5
#define CYAN 6
#define WHITE 7
#define DEFAULT 9

int main(int argc, char *argv[])
{
    clearScreen();
    setBackColor(BLUE);
    setCharColor(YELLOW);
    setPosition(5, 10);
    printf("hello!");
    fflush(stdout);
    setBackColor(DEFAULT);
    setCharColor(DEFAULT);
}