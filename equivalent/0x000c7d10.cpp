// STATUS: equivalent (tools/equiv.py level 3: 71 inputs, branch coverage 9/10, incomplete)
// FUN_000c7d10 @ 0x000c7d10
#include "decls/address.h"
struct Key_c7d10 {
    int lo, hi;
    void FUN_0027af50();
};

struct Str8 {
    char pad[8];
    void FUN_0027af70(Key_c7d10 *k);
};

struct Entry_c7d10 {
    int key;
    int f4, f8, fc, f10, f14, f18, f1c, f20;
    char pad24[4];
    Str8 str;
    int flag;
    int f34;
    int f38;
    char b3c;
    char b3d;
    char pad3e[2];
};

struct Registry_c7d10 {
    int FUN_00024280(int id0, int id1);
};

struct Lookup_c7d10 {
    bool FUN_001dd7b0(Key_c7d10 *k);
};

struct World {
    char pad0[0xc];
    Lookup_c7d10 *lookup;
    char pad10[0x20 - 0x10];
    Registry_c7d10 *registry;
};


void __cdecl FUN_00096e50(Key_c7d10 *k, int name);

class Table_c7d10 {
public:
    char pad0[0x258];
    Entry_c7d10 entries[128];
    int FUN_000c7c60(int a, int b);
    int FUN_000c7d10(int a, int b);
};

int Table_c7d10::FUN_000c7d10(int a, int b)
{
    int slot = FUN_000c7c60(a, b);
    if (slot != -1)
        return slot;

    Key_c7d10 key;
    int flag;
    FUN_00096e50(&key, b);
    if (DAT_004dd700->registry->FUN_00024280(key.lo, key.hi)) {
        flag = 0;
    } else {
        if (!DAT_004dd700->lookup->FUN_001dd7b0(&key)) {
            key.FUN_0027af50();
            return -1;
        }
        flag = 1;
    }

    int i;
    for (i = 0; i < 128; i++) {
        if (entries[i].key == -1)
            break;
    }
    if (i == 128) {
        key.FUN_0027af50();
        return slot;
    }

    Entry_c7d10 *e = &entries[i];
    e->key = a;
    e->str.FUN_0027af70(&key);
    e->flag = flag;
    e->f4 = 0;
    e->f8 = 0;
    e->fc = 0;
    e->f10 = 0;
    e->f14 = 0;
    e->f18 = 0;
    e->f1c = 0;
    e->f20 = 0;
    e->f34 = 0;
    e->f38 = 0;
    e->b3c = 0;
    e->b3d = 0;
    key.FUN_0027af50();
    return i;
}
