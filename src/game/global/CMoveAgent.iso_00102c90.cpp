// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00102a50..0x00103340 (kind game, layer game, confidence high), dominant class CMoveAgent
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x00102c90 CMoveAgent::vfunc_2 (53 B): matches/0x00102c90.cpp [isolated: compile error C2664: 'fn_00102c90::thunk' : cannot convert parameter 1 from 'fn_00102c90::CMoveAgent *const ' to 'CMoveAgent *']
// sym: ?vfunc_2@CMoveAgent@fn_fcaa2eec@@UAEPAU12@E@Z
namespace fn_fcaa2eec {} using namespace fn_fcaa2eec;
namespace fn_fcaa2eec {
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
} // namespace fn_fcaa2eec

