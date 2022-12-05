#include <iostream>
#include "sample.h"

using namespace std;

int main()
{
    SampleClass s; // SampleClassをインスタンス化

    s.setNum(5);
    cout << s.getNum() << endl;
}