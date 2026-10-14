// STATUS: equivalent (tools/equiv.py level 3: 129 inputs, branch coverage 8/8)
// FUN_00258bf0 @ 0x00258bf0
struct Target_258bf0 { char pad[0x20]; int value; };
struct Table_258bf0 { char pad[0x20]; Target_258bf0* slot[1]; };
struct Pair_258bf0 { int value; int index; };
void __cdecl ApplyPairs(Table_258bf0* table, Pair_258bf0* pairs, unsigned count) {
    for (unsigned i = 0; i < count; i++)
        table->slot[pairs[i].index]->value = pairs[i].value;
}
