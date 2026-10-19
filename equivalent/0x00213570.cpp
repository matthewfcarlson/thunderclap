// STATUS: equivalent (tools/equiv.py level 3: 19279 inputs, branch coverage 0/0)
// FUN_00213570 @ 0x00213570
// FUN_00213570 @ 0x00213570
struct Item { char pad[8]; int length; };
int __fastcall FUN_00212bb0(int other, Item* item);
void __cdecl FUN_00217830(Item* item, int result, int size1, int size2);
void __cdecl FUN_00213570(Item* item, int other)
{
    int size = item->length - 8;
    int result = FUN_00212bb0(other, item);
    FUN_00217830(item, result, size, size);
}
