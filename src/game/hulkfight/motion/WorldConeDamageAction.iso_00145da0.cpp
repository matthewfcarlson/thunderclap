// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00143100..0x00146900 (kind game, layer game, confidence high), dominant class hulkfight::motion::WorldConeDamageAction
// (tree_prelude.h: not needed)


// 0x00145da0 hulkfight::motion::HitEffectAction::vfunc_2 (90 B): matches/0x00145da0.cpp [isolated: conflict: HitEffectAction; on include/gen/ and not mergeable]
// sym: ?f2@HitEffectAction@@QAEPAV1@E@Z
#include "gen/fight.h"
extern "C" void _ReadWriteBarrier();
extern char hulk_at_004130c0[];
class Ref_145da0 {
  public:
    virtual void f0();
    virtual void f1();
};
class WorldConeDamageAction_145da0 {
  public:
};
extern void __cdecl thunk_FUN_00267090(void*);
class HitEffectAction {
  public:
    void* vptr;
    char p[0x18];
    Ref_145da0* m1c;
    int m20;
    Ref_145da0* m24;
    HitEffectAction* f2(unsigned char);
};
HitEffectAction* HitEffectAction::f2(unsigned char flags) {
    vptr = hulk_at_004130c0;
    _ReadWriteBarrier();
    if (m24) {
        m24->f1();
        m24 = 0;
    }
    if (m20)
        m20 = 0;
    if (m1c) {
        m1c->f1();
        m1c = 0;
    }
    ((fight::Action *)(((WorldConeDamageAction_145da0*)this)))->FUN_002326a0();
    if (flags & 1)
        thunk_FUN_00267090(this);
    return this;
}

