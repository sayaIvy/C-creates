#include "ambulance.h"
#include <iostream>

using namespace std;

//コンストラクタ
Ambulance::Ambulance() : m_number(119)
{
    cout << "Ambulanceオブジェクト生成" << endl;
}
//デストラクタ
Ambulance::~Ambulance()
{
    cout << "Ambulanceオブジェクト破棄" << endl;
}
//救急救命活動
void Ambulance::savePeople()
{
    cout << "救急救命活動" << endl
         << "呼び出しは" << m_number << "番" << endl;
}