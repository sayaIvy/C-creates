#include "car.h"
#include "ambulance.h"

int main()
{
    Car c;
    c.supply(10);
    c.move();
    c.move();
    Ambulance a;
    a.supply(10);
    a.move();
    a.savePeople();
    return 0;
}
// Ambulanceインスタンス
// Carコンストラクタ
// Ambulanceコンストラクタ
// Ambulanceデストラクタ
// Carデストラクタ