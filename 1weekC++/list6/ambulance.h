#ifndef _AMBULANCE_H_
#define _AMBULANCE_H_

#include "car.h"

class Ambulance : public Car //継承
{
public:
    //コンストラクタ
    Ambulance();
    virtual ~Ambulance(); //サブクラスのデストラクタにはvirtualつける
    //救急救命活動
    void savePeople();

private:
    int m_number;
};

#endif // _AMBULANCE_H_