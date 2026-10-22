#include "compat/ptr.h"
extern "C" char DAT_0042b914[];
extern "C" char DAT_0042b9bc[];
// Same code shape as 0x00274590 (propagated; names are from that function)
class V {
  public:
    virtual void A();
    virtual void B();
};
class Obj_2749a0 {
  public:
    char pad[4];
    V sub;
    char rest[0x10];
    int count;
};
class DriveRequest_2749a0 {
  public:
    void Fn();
    char pad[8];
    Obj_2749a0* mObj;
};
void DriveRequest_2749a0::Fn() {
    Obj_2749a0* p = mObj;
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_0042b9bc);
    p->sub.A();
    --(*(int*)((char*)mObj + 0x14));
    p = mObj;
    p->sub.B();
    p = mObj;
    ((V*)p)->B();
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_0042b914);
}