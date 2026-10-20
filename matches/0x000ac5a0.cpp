#include "compat/ptr.h"
extern int vtable_ac5a0;
class Ref_ac5a0 {
  public:
    virtual void f0();
    virtual void f1();
};
class CNISCamera {
  public:
    virtual void f0();
    virtual void f1();
    virtual CNISCamera* vfunc_2(unsigned char flag);
    char pad[0x16c];
    Ref_ac5a0* mRef;
};
void __fastcall init(CNISCamera*);
void __cdecl thunk(CNISCamera*);
CNISCamera* CNISCamera::vfunc_2(unsigned char flag) {
    *(volatile hulk_intptr*)this = (hulk_intptr)&vtable_ac5a0;
    Ref_ac5a0* r = *(Ref_ac5a0* volatile*)&mRef;
    if (r) {
        r->f1();
        mRef = 0;
    }
    init(this);
    if (flag & 1)
        thunk(this);
    return this;
}
