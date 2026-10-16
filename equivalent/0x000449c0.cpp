// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000449c0 @ 0x000449c0
// Look up two named entries in the global registry and seed the six handles (reverse order of FUN_00044910).
#include "decls/address.h"
#include "decls/data/engine/fight.h"
#include "decls/data/game/global.h"

struct Entry_449c0 {
    char pad[0x5c];
    int value;                      // 0x5c
};

struct Registry_449c0 {
    Entry_449c0 *FUN_00232840(unsigned __int64 key);
};

struct Handle_449c0 {
    int first;
    int second;
    int third;
    void FUN_00234090(int v);
};


struct Obj_449c0 {
    char pad[0xe0];
    Handle_449c0 h[6];                    // 0xe0 .. 0x128
    bool FUN_000449c0();
};

bool Obj_449c0::FUN_000449c0()
{
    const char *name = (*(const char**)&DAT_0048f69c);
    Registry_449c0 *reg = (*(Registry_449c0**)&DAT_004e5af8);
    h[5].FUN_00234090(reg->FUN_00232840(FUN_002672f0(name, 0, 0))->value);
    name = (*(const char**)&DAT_0048f698);
    reg = (*(Registry_449c0**)&DAT_004e5af8);
    Entry_449c0 *entry = reg->FUN_00232840(FUN_002672f0(name, 0, 0));
    h[4].FUN_00234090(h[0].first);
    h[3].FUN_00234090(h[0].first);
    h[2].FUN_00234090(h[0].first);
    h[1].FUN_00234090(h[0].first);
    h[0].FUN_00234090(entry->value);
    return true;
}
