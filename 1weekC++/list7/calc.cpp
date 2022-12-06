#include "calc.h"
//デフォルトコンストラクタ
Calc::Calc() : m_a(0), m_b(0)
{
}
//コンストラクタ（引数）
Calc::Calc(int a, int b) : m_a(a), m_b(b)
{
}
//足し算処理
int Calc::add()
{
    return m_a + m_b;
}
//足し算処理２
int Calc::add(int a, int b)
{
    return a + b;
}
//値の設定
void Calc::setValue(int a, int b)
{
    m_a = a;
    m_b = b;
}
//値の取得(m_a)
int Calc::getA()
{
    return m_a;
}
//値の取得（m_b)
int Calc::getB()
{
    return m_b;
}

//同じ名前のクラスを複数定義＝オーバーロード
//引数の型の違いで使い分ける