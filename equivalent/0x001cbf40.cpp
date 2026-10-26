// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001cbf40 @ 0x001cbf40
#include "decls/address.h"
#include "decls/data/engine/fight.h"
#include "decls/data/game/global.h"
typedef unsigned __int64 U64;

class Listener {
public:
    virtual void vfunc_0();
};

struct Entry {
    char pad[0x5c];
    Listener* listener;
};

class Registry {
public:
    Entry* FUN_00232840(U64 id);
};


class Obj_1cbf40 {
public:
    char pad0[8];
    int field8;
    int fieldC;
    int field10;
    char pad14[0xc];
    Listener* listener;
    char pad24[0x3d8];
    char flag3fc;
    void FUN_001cbf40(int value);
};

void Obj_1cbf40::FUN_001cbf40(int value)
{
    field8 = value;
    Registry* reg = (*(Registry**)&DAT_004e5af8);
    Entry* e = reg->FUN_00232840(FUN_002672f0(DAT_004c548c, 0, 0));
    listener = e->listener;
    listener->vfunc_0();
    field10 = fieldC;
    flag3fc = 0;
}
