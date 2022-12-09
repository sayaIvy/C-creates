#ifndef _FIELD_H_
#define _FIELD_H_

class Field
{
public:
    // コンストラクタ
    Field();
    // デストラクタ
    virtual ~Field();
    int bored[10][10];
    void createBored();

private:
    int wallRight;
    int wallLeft;
    int wallTop;
    int wallBottom;
    void createWall(int position);
};

#endif // _FIELD_H_