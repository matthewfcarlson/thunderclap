// Same code shape as 0x0023c920 (propagated; names are from that function)
#include "gen/core.h"

class IRefCount_26f150 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
};
class Param_26f150 {
  public:
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual void p4();
};
class Helper_26f150 {
  public:
    void f();
};

void core::Drive::vfunc_1() {
    ((Helper_26f150*)((char*)this + 0xc))->f();
}
