#ifndef _FIELD_H_
#define _FIELD_H_

#include <string>

class Field
{
public:
    // コンストラクタ
    Field();
    // デストラクタ
    virtual ~Field();
    int bored[10][10];
    void initBored();

private:
    // int wallRight;
    // int wallLeft;
    // int wallTop;
    // int wallBottom;
    char *wallPosition;
    void createWall(char *position);
};

#endif // _FIELD_H_