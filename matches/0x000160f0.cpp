#include "gen/global.h"

class CAction_160f0 {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual bool vfunc_6(int);
    virtual void a7();
    virtual void a8();
};
struct Obj_160f0 {
    Obj_160f0* f592a0();
    Obj_160f0* f59a30();
    unsigned int f40140(int, int, int, int, int);
};

bool CSmartPropDetachAction::vfunc_6(int unused) {
    Obj_160f0* o = *(Obj_160f0**)((char*)this + 0x1c);
    o = o->f592a0();
    o = o->f59a30();
    o->f40140(0, -1, 0, 0, 0);
    return false;
}
