// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0015cd10..0x00161c10 (kind game, layer game, confidence high), dominant class hulkfight::motion::HeliLocomotionAction
// (tree_prelude.h: not needed)


// 0x001616c0 hulkfight::motion::ClimbLocomotionAction::vfunc_2 (95 B): matches/0x001616c0.cpp [isolated: conflict: ClimbLocomotionAction; on include/gen/ and not mergeable]
// sym: ?vfunc_2@ClimbLocomotionAction@@QAEPAU1@E@Z
#include "gen/fight.h"
extern void* hulk_at_00415bd0[];

class RefObj_1616c0 {
  public:
    virtual ~RefObj_1616c0();
    virtual void Release();
};

void __cdecl DeleteObj_0008d330(void*);

struct ClimbLocomotionAction {
    void* mVptr;
    char pad[0x18];
    RefObj_1616c0* m1c;
    RefObj_1616c0* m20;
    RefObj_1616c0* m24;
    ClimbLocomotionAction* vfunc_2(unsigned char flags);
};

ClimbLocomotionAction* ClimbLocomotionAction::vfunc_2(unsigned char flags) {
    volatile ClimbLocomotionAction* v = this;
    RefObj_1616c0* p;
    v->mVptr = hulk_at_00415bd0;
    p = v->m24;
    if (p) {
        p->Release();
        v->m24 = 0;
    }
    p = v->m20;
    if (p) {
        p->Release();
        v->m20 = 0;
    }
    p = v->m1c;
    if (p) {
        p->Release();
        v->m1c = 0;
    }
    ((fight::Action *)this)->FUN_002326a0();
    if (flags & 1)
        DeleteObj_0008d330(this);
    return this;
}

