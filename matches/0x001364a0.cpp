#include "compat/ptr.h"
extern "C" char DAT_00411e18[];
class Ref_1364a0 {
  public:
    virtual void Fn();
    virtual void Release();
};
struct Ctor_00232660 {
    Ctor_00232660();
};
class BounceAction : public Ctor_00232660 {
  public:
    int vptr;
    int pad04[6];
    int m1c;
    Ref_1364a0* m20;
    int m24;
    int m28;
    int m2c;
    int m30;
    BounceAction(int, Ref_1364a0*);
};
BounceAction::BounceAction(int a, Ref_1364a0* r) : Ctor_00232660() {
    vptr = ((hulk_intptr)DAT_00411e18);
    int* q = &m1c;
    *q = 0;
    m20 = 0;
    m24 = 0;
    m28 = 0;
    m2c = 0;
    m30 = 0;
    m1c = a;
    if (r)
        r->Fn();
    if (m20)
        m20->Release();
    m20 = r;
}