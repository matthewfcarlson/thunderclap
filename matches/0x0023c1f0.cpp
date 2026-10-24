#include "gen/fight.h"

class Stream_23c1f0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Read(void*, int);
};
struct BinReader_nv_23c1f0 {
    void Update();
};

void fight::BinReader::FUN_0023c1f0() {
    int x;
    (*(Stream_23c1f0 * *)&this->f_08)->Read(&x, 4);
    char y[4] = {0, 0, 0, 0};
    (*(Stream_23c1f0 * *)&this->f_08)->Read(y, 4);
    signed char k = y[0];
    this->f_0c = k & 1;
    int t = k;
    (*(unsigned char *)&this->f_0d) = ((unsigned int)t >> 1) & 1;
    (*(unsigned char *)&this->f_0e) = ((unsigned int)t >> 2) & 1;
    ((BinReader_nv_23c1f0*)this)->Update();
}
