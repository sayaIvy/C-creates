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
#include <time.h>
#define clearScreen() printf("\e[2]")
#define setPosition(x, y) printf("\e[%d;%dH", (y), (x))
#define setCharColor(n) printf("\e[3%dm", (n))
#define setBackColor(n) printf("\e[4%dm", (n))
#define BLACK 0
#define RED 1
#define GREEN 2
#define YELLOW 3
#define BLUE 4
#define MAGENTA 5
#define CYAN 6
#define WHITE 7
#define DEFAULT 9

int wait(int msec);
int wait(int msec)
{
    struct timespec r = {0, msec * 1000L * 1000L};
    return nanosleep(&r, NULL);
    {
        /* data */
    };
}
int main(int argc, char *argv[])
{
    int y;
    clearScreen();
    setBackColor(BLUE);
    setCharColor(YELLOW);
    for (y = 1; y < 23; y++)
    {
        setPosition(5, y);
        printf("$");
        fflush(stdout);
        wait(500);
    }
    setBackColor(DEFAULT);
    setCharColor(DEFAULT);
}