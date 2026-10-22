#include "compat/ptr.h"
extern "C" char DAT_00411e34[];
class Ref_136850 {
  public:
    virtual void Fn();
    virtual void Release();
};
class AirToGroundTargetAction_136850 {
  public:
    void Init();
};
class AirToGroundTargetAction {
  public:
    int vf;
    char pad[0x18];
    int a, b, c, d, e, f;
    AirToGroundTargetAction(int x, Ref_136850* r);
};
AirToGroundTargetAction::AirToGroundTargetAction(int x, Ref_136850* r) {
    ((AirToGroundTargetAction_136850*)this)->Init();
    Ref_136850* q = r;
    volatile int* p = &vf;
    *p = ((hulk_intptr)DAT_00411e34);
    volatile int* z = &a;
    *z = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 0;
    f = 0;
    a = x;
    if (q)
        q->Fn();
    if (b)
        ((Ref_136850*)b)->Release();
    b = (hulk_intptr)q;
}