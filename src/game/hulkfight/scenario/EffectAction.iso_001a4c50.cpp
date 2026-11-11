// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001a1ed0..0x001aace0 (kind game, layer game, confidence high), dominant class hulkfight::scenario::EffectAction
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x001a4c50 hulkfight::scenario::Event_LocomotionStateNamePreviousCondition::vfunc_6 (95 B): matches/0x001a4c50.cpp [isolated: conflict: DAT_00494b44; DAT_004c13d0; on include/gen/ and not mergeable]
// sym: ?vfunc_6@Event_LocomotionStateNamePreviousCondition@scenario@hulkfight@@UAE_NPAX00@Z
#include "gen/hulkfight.h"

extern "C" char DAT_00494b44[];
extern "C" char DAT_004c13d0[];
struct R_1a4c50 {
    char a[4];
    int type;
    char b[12];
    int name;
};
extern void* Find(void*, int, void*, void*, int);
struct Obj_1a4c50 {
    R_1a4c50* Get_001d03c0();
};

bool hulkfight::scenario::Event_LocomotionStateNamePreviousCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { void * x = (void *)__p0; void * y = (void *)__p1; void * z = (void *)__p2;

    void* p = Find(y, 0, (void*)((hulk_intptr)DAT_00494b44), (void*)((hulk_intptr)DAT_004c13d0), 0);
    if (!p)
        return false;
    R_1a4c50* q = ((Obj_1a4c50*)p)->Get_001d03c0();
    if (q->type != 15)
        return false;
    int n = q->name;
    switch (this->compare) {
    case 0:
        return n == this->oldState;
    case 1:
        return n != this->oldState;
    }
    return false;
}

