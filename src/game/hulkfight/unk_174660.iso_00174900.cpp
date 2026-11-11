// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00174660..0x00174940 (kind game, layer game, confidence low)
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x00174900 FUN_00174900 (50 B): matches/0x00174900.cpp [isolated: conflict: PushOutAction; on include/gen/ and not mergeable]
// sym: ?Clear@PushOutAction@@QAEXXZ
#include "gen/fight.h"
extern "C" char DAT_00417ea0[];
extern "C" void _ReadWriteBarrier();
class Action {
  public:
    virtual void A();
    virtual void B();
};
class Action_174900 {
  public:
};
class PushOutAction : public Action_174900 {
  public:
    volatile hulk_intptr vptr;
    char pad[0x18];
    int* m1;
    Action* m2;
    void Clear();
};
void PushOutAction::Clear() {
    vptr = ((hulk_intptr)DAT_00417ea0);
    _ReadWriteBarrier();
    if (m2) {
        m2->B();
        m2 = 0;
    }
    if (m1)
        m1 = 0;
    ((fight::Action *)(Action_174900 *)this)->FUN_002326a0();
}

