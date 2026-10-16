#include "gen/core.h"

class Inner_273e60 {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual int k(int, int);
    int m();
};
class Sub_273e60 {
  public:
    virtual void a();
    virtual void b();
};
struct Data_273e60 {
    char pad0[4];
    Sub_273e60 sub;
    char pad8[4];
    Inner_273e60* inner;
    char pad10[4];
    int y;
    char pad18[0x15c - 0x18];
    int field;
};

int core::FileCommitRequest::vfunc_1() {
    Data_273e60* d = (*(Data_273e60 *volatile *)&this->f_08);
    Inner_273e60* i = d->inner;
    int x = i->k(d->field, (int)((char*)d + 0x1e));
    int z = i->m();
    (*(Data_273e60 *volatile *)&this->f_08)->sub.a();
    (*(Data_273e60 *volatile *)&this->f_08)->y = z;
    (*(Data_273e60 *volatile *)&this->f_08)->sub.b();
    return x;
}
