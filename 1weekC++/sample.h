#ifndef _SAMPLE_H_
#define _SAMPLE_H_

//クラス宣言
class SampleClass
{
public:
    // void set(int num); //実装：Sample::set(int num)
    // int get();         //実装：int Sample::get()
    int a;

private:
    int b;

public:
    void func1();

private:
    void func2();
};

#endif //_SAMPLE_H_

// sample.cpp, main.cpp
//#なんちゃらは二重インクルードの防止