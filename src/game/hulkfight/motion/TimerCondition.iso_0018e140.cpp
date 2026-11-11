// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0018cab0..0x0018ecb0 (kind game, layer game, confidence high), dominant class hulkfight::motion::TimerCondition
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x0018e140 hulkfight::motion::VarAssignTrack::vfunc_10 (70 B): matches/0x0018e140.cpp [isolated: conflict: Check; on include/gen/ and not mergeable]
// sym: ?vfunc_10@VarAssignTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_18e140 {
  public:
    int x;
};
extern Params_18e140 TypeA_18e140;
extern Params_18e140 TypeB_18e140;
int __cdecl Check(void*, int, Params_18e140*, Params_18e140*, int);
struct VarAssignAction_nv_18e140 {
    int Init(hulkfight::motion::VarAssignTrack*, hulk_intptr);
};
hulkfight::motion::VarAssignAction* __cdecl Alloc(int);

hulk_intptr hulkfight::motion::VarAssignTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &TypeA_18e140, &TypeB_18e140, 0);
    if (result) {
        hulkfight::motion::VarAssignAction* p = Alloc(0x24);
        if (p)
            return ((VarAssignAction_nv_18e140*)(((hulkfight::motion::VarAssignAction*)(p))))->Init(this, c);
    }
    return 0;
}

