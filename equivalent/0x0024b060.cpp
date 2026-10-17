// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0024b060 @ 0x0024b060
struct Item { char pad[8]; void* value; };
void __cdecl FUN_00258bf0(void*);
void __cdecl FUN_0024b060(Item* item) { FUN_00258bf0(item->value); }