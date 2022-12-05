#include "car.h"
#include <iostream>

using namespace std;

//コンストラクタ
Car::Car() : m_fuel(0), m_migration(0)
{
    cout << "Carオブジェクト生成" << endl;
}
//デコンストラクタ
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
    cout << "燃料：" << m_fuel << endl;
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