#ifndef _CALC_H_
#define _CALC_H_

class Calc
{
private:
    int m_a;
    int m_b;

public:
    // デフォルトコンストラクタ
    Calc();
    // コンストラクタ（引数）
    Calc(int a, int b);
    //足し算処理
    int add();
    //足し算処理２
    int add(int a, int b);
    //値の設定
    void setValue(int a, int b);
    //値の取得（m_a)
    int getA();
    //値の取得（m_b）
    int getB();
};

#endif //_CALC_H_