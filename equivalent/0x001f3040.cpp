// STATUS: equivalent (tools/equiv.py level 3: 20010 inputs, branch coverage 6/6)
// FUN_001f3040 @ 0x001f3040
// FUN_001f3040: look up an entry and fetch two sound handles from it (or default to "hulk")
#include "decls/address.h"
#include "decls/data/game/global.h"
typedef unsigned __int64 u64_1f3040;

struct Node {
    char pad00[8];
    int nameA;
    int nameB;
    int nameC;
    int nameD;
    int flag;
};

struct Key_1f3040 {
    u64_1f3040 key;
};

struct Dest_1f3040 {
    char pad00[0x10];
    int handleA;
    int handleB;
    char pad18[0x5c];
    int flag;
};

struct Sound_1f3040 {
    int FUN_001e9860(int a, int b);
    int FUN_001ea010(const char *name);
};


Node *__cdecl FUN_001f2ff0(Key_1f3040 *k);

void __cdecl FUN_001f3040(Dest_1f3040 *d, Key_1f3040 *k)
{
    Node *n = FUN_001f2ff0(k);
    if (n != 0) {
        d->handleA = (*(Sound_1f3040**)&DAT_004e3690)->FUN_001e9860(n->nameA, n->nameB);
        d->handleB = (*(Sound_1f3040**)&DAT_004e3690)->FUN_001e9860(n->nameC, n->nameD);
        d->flag = n->flag;
        return;
    }
    u64_1f3040 hulk = FUN_0027b020("hulk"); // MSVC calls it before reading k->key
    if (k->key == hulk) {
        d->handleA = (*(Sound_1f3040**)&DAT_004e3690)->FUN_001ea010("hulk_sfx");
        d->handleB = (*(Sound_1f3040**)&DAT_004e3690)->FUN_001ea010("hulk_vox");
        d->flag = 1;
    }
}
