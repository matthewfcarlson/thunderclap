// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_002198b0 @ 0x002198b0
struct Entry { char data[20]; };
struct Table { char pad[7]; unsigned char shift; char pad2[8]; Entry* entries; };
struct Key { unsigned int kind; unsigned int value; };
struct ObjectKey { char pad[8]; unsigned int hash; };
// equiv-conv: FUN_00219870 esi stack
Entry* __cdecl FUN_00219870(Table* table, unsigned int value);
Entry* __cdecl FUN_002198b0(Table* table, const Key* key) {
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
