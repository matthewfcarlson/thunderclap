// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// FUN_0024b060 @ 0x0024b060
struct Item { char pad[8]; void* value; };
struct Pair_24b060;
void __cdecl FUN_00258bf0(void*, Pair_24b060*, int);
void __cdecl FUN_0024b060(Item* item, Pair_24b060* pairs, int count) { FUN_00258bf0(item->value, pairs, count); }
