// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0023a0f0..0x0023a3f0 (kind game, layer engine, confidence high), dominant class fight::QueuedNodeAction
// (tree_prelude.h: not needed)


// 0x0023a360 fight::QueuedNodeAction::vfunc_2 (84 B): matches/0x0023a360.cpp [isolated: conflict: QueuedNodeAction; on include/gen/ and not mergeable]
// sym: ?vfunc_2@QueuedNodeAction@@QAEPAV1@H@Z
#include "gen/fight.h"
extern "C" void _ReadWriteBarrier();
class IRef_23a360 {
  public:
    virtual void f0();
    virtual void Release();
};
class Member_23a360 {
  public:
    void dtor_002325f0();
    char x;
};
extern char hulk_at_00428558[];
void __cdecl opDelete_0008d330(void*);
class QueuedNodeAction {
  public:
    void* vptr;
    QueuedNodeAction* vfunc_2(int flag);
    char pad1[0x18];
    IRef_23a360* mA;
    char pad2[8];
    IRef_23a360* mB;
    Member_23a360 mC;
};
QueuedNodeAction* QueuedNodeAction::vfunc_2(int flag) {
    vptr = hulk_at_00428558;
    _ReadWriteBarrier();
    if (mB) {
        mB->Release();
        mB = 0;
    }
    if (mA) {
        mA->Release();
        mA = 0;
    }
    mC.dtor_002325f0();
    ((fight::Action *)this)->FUN_002326a0();
    if (flag & 1)
        opDelete_0008d330(this);
    return this;
}

