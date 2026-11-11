// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001a1ed0..0x001aace0 (kind game, layer game, confidence high), dominant class hulkfight::scenario::EffectAction
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x001aaa10 fight::ConditionFactoryTemplate<hulkfight::scenario::Event_StringCondition>::vfunc_5 (48 B): matches/0x001aaa10.cpp [isolated: conflict: Alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VEvent_StringCondition@scenario@hulkfight@@@fight@@UAEPAXXZ
#include "gen/fight.h"

extern "C" char DAT_0041c4f0[];
extern void* __cdecl Alloc(hulk_uintptr);
struct Event_StringCondition_1aaa10 {
    int x[6];
    void Initialize(int);
};
struct Sub_1aaa10 {
    void Init();
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::scenario::Event_StringCondition>::vfunc_5() {
    Event_StringCondition_1aaa10* p = (Event_StringCondition_1aaa10*)Alloc(0x18);
    if (p) {
        p->Initialize(0);
        p->x[0] = ((hulk_intptr)DAT_0041c4f0);
        ((Sub_1aaa10*)((char*)p + 0x10))->Init();
        return (void*)(p);
    }
    return (void*)(0);
}

