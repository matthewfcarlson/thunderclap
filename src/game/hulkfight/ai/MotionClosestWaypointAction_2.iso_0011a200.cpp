// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00117ce0..0x0011b800 (kind game, layer game, confidence high), dominant class hulkfight::ai::MotionClosestWaypointAction
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x0011a200 hulkfight::ai::MotionClosestWaypointAction::vfunc_2 (79 B): matches/0x0011a200.cpp [isolated: conflict: MotionClosestWaypointAction; on include/gen/ and not mergeable]
// sym: ?vfunc_2@MotionClosestWaypointAction@@QAEPAXE@Z
#include "gen/fight.h"
struct RefObj_11a200 {
  public:
    virtual void v0();
    virtual void Release();
};

struct Sub60 {
  public:
    void Dtor_0027af50();
};

class MotionClosestWaypointAction {
  public:
    void* mVptr;          // 0x00
    char pad1[24];        // 0x04..0x1B
    int m1c;              // 0x1C
    RefObj_11a200* volatile m20; // 0x20
    char pad2[60];        // 0x24..0x5F
    Sub60 m60;            // 0x60

    void* vfunc_2(unsigned char flag);
};

extern int hulk_at_0040ed74;
void operator delete(void*);

void* MotionClosestWaypointAction::vfunc_2(unsigned char flag) {
    *(volatile hulk_intptr*)this = (hulk_intptr)&hulk_at_0040ed74;
    RefObj_11a200* p = m20;
    if (p) {
        p->Release();
        m20 = 0;
    }
    if (m1c) {
        m1c = 0;
    }
    m60.Dtor_0027af50();
    ((fight::Action *)this)->FUN_002326a0();
    if (flag & 1) {
        operator delete(this);
    }
    return this;
}

