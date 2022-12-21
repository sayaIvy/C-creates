#include <stdio.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 20

#define clearScreen() printf("\e[2J")
#define setPosition(x, y) printf("\e[%d;%dH", (y) + 1, (x)*2 + 1) // 座標を(0,0)からにする
#define cursorOn() printf("\e[?25h")                              // カーソルを表示
#define cursorOff() printf("\e[?25i")                             // 　カーソルを非表示
#define FEILD_WIDTH 10
#define FEILD_HIGHT 20
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

#define BLOCK_SIZE 4
#define BLOCK_NUM 7

typedef struct cell
{
    char c; // 表示文字
    int charColor;
    int backColor;
    int attribute; // 文字属性
} Cell;

Cell block_type[BLOCK_NUM][BLOCK_SIZE][BLOCK_SIZE] = {
    '\0', RED, BLACK, NORMAL,
    '\0', RED, BLACK, NORMAL,
    ' ', RED, BLACK, REVERSE,
    '\0', RED, BLACK, NORMAL,
    '\0', RED, BLACK, NORMAL,
    ' ', RED, BLACK, REVERSE,
    ' ', RED, BLACK, REVERSE,
    '\0', RED, BLACK, NORMAL,
    '\0', RED, BLACK, NORMAL,
    ' ', RED, BLACK, REVERSE,
    '\0', RED, BLACK, NORMAL,
    '\0', RED, BLACK, NORMAL,
    '\0', RED, BLACK, NORMAL,
    '\0', RED, BLACK, NORMAL,
    '\0', RED, BLACK, NORMAL,
    '\0', RED, BLACK, NORMAL,

    '\0', RED, BLACK, NORMAL,
    ' ', RED, BLACK, REVERSE,
    ' ', RED, BLACK, REVERSE,
    '\0', RED, BLACK, NORMAL,
    '\0', RED, BLACK, NORMAL,
    ' ', RED, BLACK, REVERSE,
    '\0', RED, BLACK, NORMAL,
    '\0', RED, BLACK, NORMAL,
    '\0', RED, BLACK, NORMAL,
    ' ', RED, BLACK, REVERSE,
    '\0', RED, BLACK, NORMAL,
    '\0', RED, BLACK, NORMAL,
    '\0', RED, BLACK, NORMAL,
    '\0', RED, BLACK, NORMAL,
    '\0', RED, BLACK, NORMAL,
    '\0', RED, BLACK, NORMAL,

    '\0', RED, BLACK, NORMAL,
    '\0', RED, BLACK, NORMAL,
    '\0', RED, BLACK, NORMAL,
    '\0', RED, BLACK, NORMAL,
    '\0', RED, BLACK, NORMAL,
    ' ', RED, BLACK, REVERSE,
    ' ', RED, BLACK, REVERSE,
    '\0', RED, BLACK, NORMAL,
    ' ', RED, BLACK, REVERSE,
    ' ', RED, BLACK, REVERSE,
    '\0', RED, BLACK, NORMAL,
    '\0', RED, BLACK, NORMAL,
    '\0', RED, BLACK, NORMAL,
    '\0', RED, BLACK, NORMAL,
    '\0', RED, BLACK, NORMAL,
    '\0', RED, BLACK, NORMAL,

    '\0', RED, BLACK, NORMAL,
    '\0', RED, BLACK, NORMAL,
    '\0', RED, BLACK, NORMAL,
    '\0', RED, BLACK, NORMAL,
    '\0', RED, BLACK, NORMAL,
    ' ', RED, BLACK, REVERSE,
    ' ', RED, BLACK, REVERSE,
    '\0', RED, BLACK, NORMAL,
    '\0', RED, BLACK, NORMAL,
    ' ', RED, BLACK, REVERSE,
    ' ', RED, BLACK, REVERSE,
    '\0', RED, BLACK, NORMAL,
    '\0', RED, BLACK, NORMAL,
    '\0', RED, BLACK, NORMAL,
    '\0', RED, BLACK, NORMAL,
    '\0', RED, BLACK, NORMAL,

    '\0', RED, BLACK, NORMAL,
    ' ', RED, BLACK, REVERSE,
    '\0', RED, BLACK, NORMAL,
    '\0', RED, BLACK, NORMAL,
    '\0', RED, BLACK, NORMAL,
    ' ', RED, BLACK, REVERSE,
    '\0', RED, BLACK, NORMAL,
    '\0', RED, BLACK, NORMAL,
    '\0', RED, BLACK, NORMAL,
    ' ', RED, BLACK, REVERSE,
    '\0', RED, BLACK, NORMAL,
    '\0', RED, BLACK, NORMAL,
    '\0', RED, BLACK, NORMAL,
    ' ', RED, BLACK, REVERSE,
    '\0', RED, BLACK, NORMAL,
    '\0', RED, BLACK, NORMAL,

    '\0', RED, BLACK, NORMAL,
    '\0', RED, BLACK, NORMAL,
    '\0', RED, BLACK, NORMAL,
    '\0', RED, BLACK, NORMAL,
    ' ', RED, BLACK, REVERSE,
    ' ', RED, BLACK, REVERSE,
    ' ', RED, BLACK, REVERSE,
    '\0', RED, BLACK, NORMAL,
    '\0', RED, BLACK, NORMAL,
    ' ', RED, BLACK, REVERSE,
    '\0', RED, BLACK, NORMAL,
    '\0', RED, BLACK, NORMAL,
    '\0', RED, BLACK, NORMAL,
    '\0', RED, BLACK, NORMAL,
    '\0', RED, BLACK, NORMAL,
    '\0', RED, BLACK, NORMAL,

    '\0', RED, BLACK, NORMAL,
    ' ', RED, BLACK, REVERSE,
    '\0', RED, BLACK, NORMAL,
    '\0', RED, BLACK, NORMAL,
    '\0', RED, BLACK, NORMAL,
    ' ', RED, BLACK, REVERSE,
    '\0', RED, BLACK, NORMAL,
    '\0', RED, BLACK, NORMAL,
    '\0', RED, BLACK, NORMAL,
    ' ', RED, BLACK, REVERSE,
    ' ', RED, BLACK, REVERSE,
    '\0', RED, BLACK, NORMAL,
    '\0', RED, BLACK, NORMAL,
    '\0', RED, BLACK, NORMAL,
    '\0', RED, BLACK, NORMAL,
    '\0', RED, BLACK, NORMAL,
};

int wait(int msec);
void initialize(void); // 画面初期化
void reset(void);      // 画面の復元
int checkRange(Cell a, int x, int y);
int printCell(Cell c, int x, int y);
int clearCell(Cell c, int x, int y);
void copyBlock(Cell src[BLOCK_SIZE][BLOCK_SIZE], Cell dst[BLOCK_SIZE][BLOCK_SIZE]);
int printBlock(Cell block[BLOCK_SIZE][BLOCK_SIZE], int x, int y);
int clearBlock(Cell block[BLOCK_SIZE][BLOCK_SIZE], int x, int y);

int main(int argc, char *argv[])
{
    int y;
    Cell a = {' ', WHITE, BLACK, REVERSE};
    initialize();
    for (y = 1; y < HEIGHT; y++)
    {
        printCell(a, 5, y);
        wait(500);
        clearCell(a, 5, y);
    }
    reset();
}

int wait(int msec)
{
    struct timespec r = {0, msec * 1000L * 1000L};
    return nanosleep(&r, NULL);
}

void initialize(void)
{
    setBackColor(BLACK);
    setCharColor(WHITE);
    setAttribute(NORMAL);
    clearScreen();
    cursorOff();
}

void reset(void)
{
    setBackColor(BLACK);
    setCharColor(WHITE);
    setAttribute(NORMAL);
    clearScreen();
    cursorOn();
}

int checkRange(Cell a, int x, int y)
{
    if (a.c == '\0' || x < 0 || y < 0 || x >= FEILD_WIDTH || y >= FEILD_HIGHT)
        return -1; // 失敗
    else
        return 0; // 成功
}

int printCell(Cell c, int x, int y)
{
    if (checkRange(c, x, y) == -1)
        return -1;
    setPosition(x, y);
    setAttribute(c.attribute);
    setBackColor(c.backColor);
    setCharColor(c.charColor);
    printf("%c%c", c.c, c.c);
    fflush(stdout);
    return 0;
}

int clearCell(Cell c, int x, int y)
{
    if (checkRange(c, x, y) == -1)
        return -1;
    setPosition(x, y);
    setAttribute(NORMAL);
    setBackColor(BLACK);
    setCharColor(BLACK);
    printf("  ");
    fflush(stdout);
    return 0;
}

void copyBlock(Cell src[BLOCK_SIZE][BLOCK_SIZE], Cell dst[BLOCK_SIZE][BLOCK_SIZE])
{
    int i, j;
    for (j = 0; j < BLOCK_SIZE; j++)
        for (i = 0; i < BLOCK_SIZE; i++)
            dst[j][i] = src[j][i];
}

int printBlock(Cell block[BLOCK_SIZE][BLOCK_SIZE], int x, int y);
{
    int i, j;
    for (j = 0; j < BLOCK_SIZE; j++)
        for (i = 0; i < BLOCK_SIZE; i++)
            printCell(block[j][i], i + x, j + y);
    return 0;
}

int clearBlock(Cell block[BLOCK_SIZE][BLOCK_SIZE], int x, int y);
{
    int i, jj;
    for (j = 0; j < BLOCK_SIZE; j++)
        for (i = 0; i < BLOCK_SIZE; i++)
            clearCell(block[j][i], i + x, j + y);
    return 0;
}
