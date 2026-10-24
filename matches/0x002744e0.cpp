#include "gen/core.h"

#include "compat/ptr.h"
extern "C" char DAT_0042b914[];
extern "C" char DAT_0042b9bc[];
// Same code shape as 0x00274590 (propagated; names are from that function)
class V {
  public:
    virtual void A();
    virtual void B();
};
class Obj_2744e0 {
  public:
    char pad[4];
    V sub;
    char rest[0x10];
    int count;
};

void core::DriveRequest::FUN_002744e0() {
    Obj_2744e0* p = (*(Obj_2744e0 * *)&this->f_08);
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_0042b9bc);
    p->sub.A();
    --(*(int*)((char*)(*(Obj_2744e0 * *)&this->f_08) + 0x14));
    p = (*(Obj_2744e0 * *)&this->f_08);
    p->sub.B();
    p = (*(Obj_2744e0 * *)&this->f_08);
    ((V*)p)->B();
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_0042b914);
}
