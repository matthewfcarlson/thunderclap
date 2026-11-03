#include "gen/owners.h"
class Inner_264270 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3(int, int, int);
};
class Obj_264270 {
  public:
    char p[8];
    Inner_264270* mInner;
    char q[8];
    int mCount;
    char r[4];
    void FUN_002640f0();
    bool fnB(int, int, int, int);
};
bool Obj_264270::fnB(int a, int b, int c, int d) {
    int n = b * c;
    mInner->f3(a, n, d);
    mCount += n;
    FUN_002640f0();
    ((owners::Converter_264140 *)this)->FUN_00264140((unsigned char *)(hulk_uintptr)(int)a, (unsigned int)b, (unsigned int)c);
    return true;
}
