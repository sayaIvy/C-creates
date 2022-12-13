#include <stdio.h>
#include <time.h>
#define clearScreen() printf("\e[2J")
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

#define setAttribute(n) printf("\e[%dm", (n))
#define NORMAL 0   // 通常
#define BLIGHT 1   // 明るく
#define DIM 2      // 暗く
#define UNDERBAR 4 // 下線
#define BLINK 5    // 点滅
#define REVERSE 7  // 明暗反転
#define HIDE 8     // 隠す
#define STRIKE 9   // 取り消し線

int wait(int msec);
int main(int argc, char *argv[])
{
    int y;
    clearScreen();
    for (y = 1; y < 23; y++)
    {
        setPosition(5, y);
        setCharColor(WHITE);
        setBackColor(BLACK);
        setAttribute(REVERSE);
        printf("  ");
        fflush(stdout);

        wait(500);

        setPosition(5, y);
        setCharColor(WHITE);
        setBackColor(BLACK);
        setAttribute(NORMAL);
        printf("  ");
        fflush(stdout);
    }
    setBackColor(DEFAULT);
    setCharColor(DEFAULT);
    clearScreen();
}

int wait(int msec)
{
    struct timespec r = {0, msec * 1000L * 1000L};
    return nanosleep(&r, NULL);
    {
        /* data */
    };
}
