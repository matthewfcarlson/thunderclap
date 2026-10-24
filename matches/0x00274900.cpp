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
class Obj_274900 {
  public:
    char pad[4];
    V sub;
    char rest[0x10];
    int count;
};

void core::DriveRequest::FUN_00274900() {
    Obj_274900* p = (*(Obj_274900 * *)&this->f_08);
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_0042b9bc);
    p->sub.A();
    --(*(int*)((char*)(*(Obj_274900 * *)&this->f_08) + 0x14));
    p = (*(Obj_274900 * *)&this->f_08);
    p->sub.B();
    p = (*(Obj_274900 * *)&this->f_08);
    ((V*)p)->B();
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_0042b914);
}
