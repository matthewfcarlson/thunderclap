// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_001aeae0 @ 0x001aeae0
#include "compat/ptr.h"
struct Item { char pad[0x2c]; float value; };
struct Entry { Item *item; void *unused; };
struct Group { char pad[0x10]; Item *item; void *unused; };
int __cdecl FUN_001aeae0(Entry *left, Group *right)
{
    Item *a = left->item;
    Item *b = right->item;
    if (a->value == b->value) {
        hulk_uintptr pa = (hulk_uintptr)((char *)a + 0x10);
        hulk_uintptr pb = (hulk_uintptr)((char *)b + 0x10);
        if (pb > pa) return -1;
        return pb < pa ? 1 : 0;
    }
    return !(a->value <= b->value) ? 1 : -1;
}