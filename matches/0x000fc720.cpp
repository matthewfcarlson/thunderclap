#include "compat/ptr.h"
extern "C" char DAT_0040cfb4[];
typedef unsigned char u8_fc720;
typedef unsigned int u32_fc720;
struct Ref_fc720 {
    virtual void a();
    virtual void b();
};
struct CActorAgent {
    u32_fc720 vt;
    char pad[0x54];
    Ref_fc720* mRef;
    void Cleanup();
    CActorAgent* vfunc_2(u8_fc720 flag);
};
extern void thunk(CActorAgent*);
CActorAgent* CActorAgent::vfunc_2(u8_fc720 flag) {
    vt = ((hulk_intptr)DAT_0040cfb4);
    mRef->b();
    mRef = 0;
    Cleanup();
    if (flag & 1)
        thunk(this);
    return this;
}
