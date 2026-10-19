// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00035ab0 @ 0x00035ab0
#include "decls/data/game/unknown.h"

struct Item { __int64 FUN_000443c0(); };
struct Object {
    char padding[0x11c];
    void *item;
    bool FUN_00035ab0();
};
bool Object::FUN_00035ab0() {
    Item *p = (Item *)item;
    if (!p) return false;
    __int64 value = p->FUN_000443c0();
    return (unsigned int)value == (*(unsigned int*)&DAT_004dc0e0) && (unsigned int)(value >> 32) == (*(unsigned int*)((char*)&DAT_004dc0e0 + 4));
}