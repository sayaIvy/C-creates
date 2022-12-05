#include "car.h"
#include <iostream>

using namespace std;
int main()
{
    // new,deleteを使えばコンストラクタ、デストラクタの
    //タイミングを任意にできる
    Car *pC = 0;    //ポインタは０かNULL
    pC = new Car(); //インスタンス生成
    pC->supply(10); //燃料補給
    pC->move();     //移動
    pC->move();     //移動
    delete pC;      //インスタンスの削除
    cout << "インスタンスの消去完了" << endl;
    return 0;
}
// mallocやfreeはコンストラクタを呼び出せないから使わない