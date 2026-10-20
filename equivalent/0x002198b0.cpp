// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_002198b0 @ 0x002198b0
#include "compat/ptr.h"
struct Entry_2198b0 { char data[20]; };
struct Table_2198b0 { char pad[7]; unsigned char shift; char pad2[8]; Entry_2198b0* entries; };
struct Key_2198b0 { unsigned int kind; hulk_uintptr value; };
struct ObjectKey { char pad[8]; unsigned int hash; };
// equiv-conv: FUN_00219870 esi stack
Entry_2198b0* __cdecl FUN_00219870(Table_2198b0* table, hulk_uintptr value);
Entry_2198b0* __cdecl FUN_002198b0(Table_2198b0* table, const Key_2198b0* key) {
    if (key->kind == 3) return FUN_00219870(table, key->value);
    unsigned int mask = (1U << (table->shift & 31)) - 1U;
    unsigned int index;
    switch (key->kind) {
    case 1: index = key->value & mask; break;
    case 4: index = ((const ObjectKey*)key->value)->hash & mask; break;
    default: index = key->value % (mask | 1U); break;
    }
    return table->entries + index;
}
