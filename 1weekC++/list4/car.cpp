#include "car.h"
#include <iostream>

using namespace std;

//コンストラクタ
//クラス生成時、自動的に実行
//初期化処理：定数や外部からコンストラクタの引数として渡される時
Car::Car() : m_fuel(0), m_migration(0) //メンバ変数の初期化処理
{
    cout << "Carオブジェクト生成" << endl;
}
//デストラクタ
//クラスのインスタンス解放時、解放の直前に自動的に実行
//終了処理：メモリ解放、ファイルクローズなど
Car::~Car()
{
    cout << "Carオブジェクト破棄" << endl;
}
void Car::move()
{
    //燃料があるなら移動
    if (m_fuel >= 0)
    {
        m_migration++; //距離移動
        m_fuel--;      //燃料消費
    }
    cout << "移動距離：" << m_migration << endl;
    cout << "燃料" << m_fuel << endl;
}
//燃料補給メソッド
void Car::supply(int fuel)
{
    if (fuel > 0)
    {
        m_fuel += fuel; //燃料補給
    }
    cout << "燃料" << m_fuel << endl;
}