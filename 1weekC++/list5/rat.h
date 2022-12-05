#ifndef _RAT_H_
#define _RAT_H_

class Rat
{
public:
    //コンストラクタ
    Rat();
    //デストラクタ
    ~Rat();
    //ネズミの数の出力
    static void showNum();
    //ネズミが鳴く
    void squeak();

private:
    //ネズミの番号
    int m_id;
    //ネズミの数
    static int m_count;
};

#endif /* _RAT_H_*/
       // staticはヘッダファイルで行う