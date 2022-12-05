#include <iostream>
#include "sample.h"

using namespace std;

int main()
{
    string s;

    s = "This is a";
    s.append(" pen. "); //文字列の追加
    cout << s << endl;
    cout << "文字列の長さ：" << s.length() << endl;
    printf("cher*:%s\n", s.c_str()); // char型に変換
    return 0;
}