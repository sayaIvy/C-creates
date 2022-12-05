#include "rat.h"
#include <iostream>

using namespace std;

//ネズミの数の初期値を0に設定
int Rat::m_count = 0;
//静的メンバの初期化はソースファイルで行う
//プログラム起動時にm_count = 0 として使える。
//静的メンバはインスタンスを生成しなくても呼び出せる

//コンストラクタ
Rat::Rat() : m_id(0)
{
    m_id = m_count; //ネズミの数をidとする
    m_count++;
}
//デストラクタ
Rat::~Rat()
{
    cout << "ネズミ：" << m_id << "消去" << endl;
    m_count--;
}
//ネズミの数の出力
void Rat::showNum()
{
    cout << "ネズミの数" << m_count << "匹です" << endl;
}
//ネズミが鳴く
void Rat::squeak()
{
    cout << m_id << ": チューチュー" << endl;
}