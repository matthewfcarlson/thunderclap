// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00234ba0..0x00234cc0 (kind game, layer engine, confidence medium), dominant class fight::ParamValueScript
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x00234ba0 FUN_00234ba0 (34 B): matches/0x00234ba0.cpp [isolated: on include/gen/, and its TU merges more functions without the headers; on include/gen/ and not mergeable]
// sym: ?FUN_00234ba0@ParamValueNameList@fight@@QAEPAV12@PBD@Z
#include "gen/fight.h"

extern "C" char DAT_004279fc[];
extern "C" char DAT_00427adc[];
struct Member_234ba0 {
    void Init_0027b0e0(const char*);
};

fight::ParamValueNameList* fight::ParamValueNameList::FUN_00234ba0(const char* name) {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_004279fc);
    ((Member_234ba0*)((char*)this + 8))->Init_0027b0e0(name);
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00427adc);
    return (fight::ParamValueNameList*)(this);
}

