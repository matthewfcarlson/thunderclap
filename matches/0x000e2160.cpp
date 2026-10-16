#include "gen/global.h"

class FELayout_e2160 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    char pad[0x18];
};
class Helper_e2160 {
  public:
    void call(int);
};

int SingleLayout::vfunc_14(int a, int b) {
    ((Helper_e2160*)((char*)this + 0x18))->call(a);
    return a;
}
