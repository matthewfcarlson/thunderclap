// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0024b040 @ 0x0024b040
struct Item { char pad[8]; int value; };
void __cdecl FUN_00258b80(int value);
void __cdecl FUN_0024b040(Item *item) {
    FUN_00258b80(item->value);
}