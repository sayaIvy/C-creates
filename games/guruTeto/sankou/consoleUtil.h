//----------------------------------------------------------------------
//			consoleUtil ver 0.001
//			Copyright (C) 2014 by N.Tsuda
//			Description: コンソール用オレオレライブラリ for Win32
//			License: CDDL 1.0 (http://opensource.org/licenses/CDDL-1.0)
//----------------------------------------------------------------------
#include <iostream>
#include <stdio.h>
#include <string>

void coutW(wchar_t ch);
void coutW(const wchar_t *ptr);
void coutW(const wchar_t *ptr, int len);
void coutW(const std::wstring &str);

//----------------------------------------------------------------------
//		色定義
#define COL_BLACK 0x00
#define COL_DARK_BLUE 0x01
#define COL_DARK_GREEN 0x02
#define COL_DARK_CYAN 0x03
#define COL_DARK_RED 0x04
#define COL_DARK_VIOLET 0x05
#define COL_DARK_YELLOW 0x06
#define COL_GRAY 0x07
#define COL_LIGHT_GRAY 0x08
#define COL_BLUE 0x09
#define COL_GREEN 0x0a
#define COL_CYAN 0x0b
#define COL_RED 0x0c
#define COL_VIOLET 0x0d
#define COL_YELLOW 0x0e
#define COL_WHITE 0x0f
#define COL_INTENSITY 0x08 //	高輝度マスク
#define COL_RED_MASK 0x04
#define COL_GREEN_MASK 0x02
#define COL_BLUE_MASK 0x01

void setColor(int col);
void setColor(int fg, int bg);
void setCursorPos(int x, int y);
bool isKeyPressed(int vKey);