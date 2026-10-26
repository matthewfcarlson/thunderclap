// STATUS: equivalent (tools/equiv.py level 3: 129 inputs, branch coverage 4/4)
// FUN_00258ba0 @ 0x00258ba0
#include "compat/ptr.h"
struct Entry { unsigned a,b,c,d; unsigned index; }; struct Item { char pad[16]; hulk_uintptr a,b,c,d; }; struct Owner { char pad[32]; Item* items[1]; }; void __cdecl FUN_00258ba0(Owner* owner, Entry* entries, unsigned count) { for (unsigned i=0; i<count; ++i) { Item* item=owner->items[entries[i].index]; item->a=entries[i].a; item->b=entries[i].b; item->c=entries[i].c; item->d=entries[i].d; } }