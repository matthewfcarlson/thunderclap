#include "compat/ptr.h"
extern int vftable_102c90;
extern void __cdecl thunk(struct CMoveAgent*);

struct Ref_102c90 {
    virtual void a();
    virtual void b();
};

struct CMoveAgent {
    virtual void x0();
    virtual void x1();
    virtual CMoveAgent* vfunc_2(unsigned char param);
    char pad[0x64];
    Ref_102c90* member;
    void cleanupM();
};

CMoveAgent* CMoveAgent::vfunc_2(unsigned char param) {
    *(hulk_intptr*)this = (hulk_intptr)&vftable_102c90;
    this->member->b();
    this->member = 0;
    this->cleanupM();
    if (param & 1)
        thunk(this);
    return this;
}
