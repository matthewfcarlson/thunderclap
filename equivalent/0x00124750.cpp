// STATUS: equivalent (tools/equiv.py level 3: 3017 inputs, branch coverage 16/16)
// hulkfight::ai::TargetTypeCondition::vfunc_6 @ 0x00124750
#include "gen/hulkfight.h"

extern "C" char DAT_00494b44[];
extern "C" char DAT_00494b60[];
extern void* __cdecl FUN_00344e74(void*, int, const char*, const char*, int);

struct Kind_124750 {
    char pad0[0xc];
    int kind;               // 0x0c
};

struct Mixer_124750 {
    char pad0[0x328];
    Kind_124750* target;           // 0x328
};

struct Context_124750 {
    Mixer_124750* FUN_00059a30();
};

struct Entity_124750 {
    Context_124750* FUN_000592a0();
};

namespace hulkfight {
namespace ai {
}
}
bool hulkfight::ai::TargetTypeCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { int unused1 = (int)__p0; Entity_124750 * entity = (Entity_124750 *)__p1; int unused2 = (int)__p2;

    if (!FUN_00344e74(entity, 0, DAT_00494b44, DAT_00494b60, 0))
        return false;
    Kind_124750* target = entity->FUN_000592a0()->FUN_00059a30()->target;
    if (!target)
        return false;
    int want;
    switch (this->f_10) {
    case 0:
        want = 1;
        break;
    case 1:
        want = 5;
        break;
    default:
        return false;
    }
    int kind = target->kind;
    switch (this->f_0c) {
    case 0:
        return kind == want;
    case 1:
        return kind != want;
    }
    return false;
}
