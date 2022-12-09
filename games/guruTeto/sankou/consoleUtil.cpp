//----------------------------------------------------------------------
//			consoleUtil ver 0.001
//			Copyright (C) 2014 by N.Tsuda
//			Description: コンソール用オレオレライブラリ for Win32
//			License: CDDL 1.0 (http://opensource.org/licenses/CDDL-1.0)
//----------------------------------------------------------------------

#include "consoleUtil.h"

#define CONS_WD 80
#define CONS_HT 25
#define BD_WIDTH 10 // 盤面サイズ（外枠を除く）
#define BD_HEIGHT 20
#define N_TETRIS 7    //  テトリス種類数
#define EMPTY 0       //  空
#define FIXED_BLOCK 1 //  固定ブロック
#define WALL 0xff     // 外枠
#define TR_WIDTH 4    // 落下テトリス最大幅
#define TR_HEIGHT 4   // 落下テトリス最大高
#define BD_ORG_X 2    //  盤面表示位置
#define BD_ORG_Y 1
#define SCORE_X (BD_ORG_X + (BD_WIDTH + 2) * 2 + 4)
#define SCORE_Y BD_ORG_Y

#define FALL_INTERVAL 30 // 落下間隔
#define MOVE_INTERVAL 15 //  左右移動間隔
#define ROT_INTERVAL 15  // 回転間隔
//----------------------------------------------------------------------
void coutW(wchar_t ch)
{
    HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD len = 1;
    WriteConsoleW(hCons, &ch, len, &len, 0);
}
void coutW(const wchar_t *ptr)
{
    HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD len = wcslen(ptr);
    WriteConsoleW(hCons, ptr, len, &len, 0);
}
void coutW(const wchar_t *ptr, int len)
{
    HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
    WriteConsoleW(hCons, ptr, len, (DWORD *)&len, 0);
}
void coutW(const std::wstring &str)
{
    coutW((const wchar_t *)str.c_str(), (int)str.size());
}
//----------------------------------------------------------------------
//	文字色指定 for Windows Console
void setColor(int col)
{
    HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD attr = 0;
    if (col & COL_INTENSITY)
        attr |= FOREGROUND_INTENSITY;
    if (col & COL_RED_MASK)
        attr |= FOREGROUND_RED;
    if (col & COL_GREEN_MASK)
        attr |= FOREGROUND_GREEN;
    if (col & COL_BLUE_MASK)
        attr |= FOREGROUND_BLUE;
    SetConsoleTextAttribute(hCons, attr);
}
void setColor(int fg, int bg)
{
    HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD attr = 0;
    if (fg & COL_INTENSITY)
        attr |= FOREGROUND_INTENSITY;
    if (fg & COL_RED_MASK)
        attr |= FOREGROUND_RED;
    if (fg & COL_GREEN_MASK)
        attr |= FOREGROUND_GREEN;
    if (fg & COL_BLUE_MASK)
        attr |= FOREGROUND_BLUE;

    if (bg & COL_INTENSITY)
        attr |= BACKGROUND_INTENSITY;
    if (bg & COL_RED_MASK)
        attr |= BACKGROUND_RED;
    if (bg & COL_GREEN_MASK)
        attr |= BACKGROUND_GREEN;
    if (bg & COL_BLUE_MASK)
        attr |= BACKGROUND_BLUE;
    SetConsoleTextAttribute(hCons, attr);
}
//	カーソル位置指定 for Windows Console
void setCursorPos(int x, int y)
{
    HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(hCons, pos);
}
//	キー押下チェック
bool isKeyPressed(int vKey)
{
    return (GetAsyncKeyState(vKey) & 0x8000) != 0;
}
//----------------------------------------------------------------------