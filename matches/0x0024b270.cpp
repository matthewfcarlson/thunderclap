#include "gen/owners.h"
class Obj_24b270 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
};
int owners::Target_24b270::FUN_0024b270() {
    Obj_24b270* o = ((Obj_24b270**)this)[index * 3];
    if (o)
        o->f12();
    int v = (int)index + 1;
    int d = (int)divisor;
    int q = v / d;
    index = (unsigned char)(v % d);
    count--;
    return q;
}
