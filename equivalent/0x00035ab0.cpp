// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00035ab0 @ 0x00035ab0
#include "decls/data/game/unknown.h"

struct Object { char padding[0x11c]; void *item; };
struct Item { __int64 FUN_000443c0(); };
// equiv-conv: FUN_00035ab0 eax ecx
unsigned int FUN_00035ab0(unsigned int incoming, Object *self) {
    Item *p = (Item *)self->item;
    if (!p) return incoming & 0xffffff00;
    __int64 value = p->FUN_000443c0();
    return (unsigned int)value == (*(unsigned int*)&DAT_004dc0e0) && (unsigned int)(value >> 32) == (*(unsigned int*)((char*)&DAT_004dc0e0 + 4));
}