#ifndef _SAMPLE_H_
#define _SAMPLE_H_

//クラス宣言
class SampleClass
{
public:
    // void set(int num); //実装：Sample::set(int num)
    // int get();         //実装：int Sample::get()
    void setNum(int num);
    int getNum();

private:
    int m_num;
};

#endif //_SAMPLE_H_

// sample.cpp, main.cpp
//#なんちゃらは二重インクルードの防止