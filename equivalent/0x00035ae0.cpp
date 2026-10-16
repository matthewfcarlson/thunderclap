// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 22/22)
// FUN_00035ae0 @ 0x00035ae0
#include "decls/data/game/hulkfight.h"

class Target_35ae0 {
public:
    bool FUN_000456e0();
    __int64 FUN_000443c0();
};


class Actor_35ae0 {
public:
    char pad0[0x11c];
    Target_35ae0* target;
    char pad120[0x140 - 0x120];
    int state;
    bool FUN_00035ae0();
};

bool Actor_35ae0::FUN_00035ae0() {
    if (!target)
        return false;
    if (target->FUN_000456e0())
        return true;
    __int64 id = target->FUN_000443c0();
    if (id == DAT_004dc0a8)
        return true;
    if (id == DAT_004dc068)
        return true;
    if (id == DAT_004dc0b8)
        return state == 3;
    if (id == DAT_004dc0c8)
        return state == 3;
    return false;
}
