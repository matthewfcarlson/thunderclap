#include "compat/ptr.h"
extern "C" char DAT_0042b914[];
extern "C" char DAT_0042b9bc[];
class V {
  public:
    virtual void A();
    virtual void B();
};
class Obj_274590 {
  public:
    char pad[4];
    V sub;
    char rest[0x10];
    int count;
};
class Owner_274590 {
  public:
    void Fn();
    char pad[8];
    Obj_274590* mObj;
};
void Owner_274590::Fn() {
    Obj_274590* p = mObj;
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_0042b9bc);
    p->sub.A();
    --(*(int*)((char*)mObj + 0x14));
    p = mObj;
    p->sub.B();
    p = mObj;
    ((V*)p)->B();
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_0042b914);
}