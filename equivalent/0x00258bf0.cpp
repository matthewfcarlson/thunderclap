// STATUS: equivalent (tools/equiv.py level 3: 129 inputs, branch coverage 8/8)
// FUN_00258bf0 @ 0x00258bf0
struct Target { char pad[0x20]; int value; };
struct Table { char pad[0x20]; Target* slot[1]; };
struct Pair { int value; int index; };
void __cdecl ApplyPairs(Table* table, Pair* pairs, unsigned count) {
    for (unsigned i = 0; i < count; i++)
        table->slot[pairs[i].index]->value = pairs[i].value;
}
