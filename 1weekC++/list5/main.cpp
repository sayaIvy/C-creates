#include "rat.h"
#include <iostream>

using namespace std;

int main()
{
    Rat *r1, *r2, *r3;
    r1 = new Rat(); //  一匹目のネズミ生成
    r1->squeak();
    Rat::showNum(); //  ネズミの数を表示
    r2 = new Rat(); //  二匹目のネズミ生成
    r3 = new Rat(); //  三匹目のネズミ生成
    r2->squeak();
    r3->squeak();
    delete r1;      //  一匹目のネズミ消去
    delete r2;      //  二匹目のネズミ消去
    Rat::showNum(); //  ネズミの数を表示
    delete r3;      //  三匹目のネズミ消去
    Rat::showNum(); //  ネズミの数を表示
    // showNumは静的メンバだからインスタンスがなくても使えちゃう
    return 0;
}
//静的メンバからインスタンスメンバは使えない。
//インスタンスメンバから静的メンバは使える
//インスタンスメンバはインスタンスを生成しないと利用できないから