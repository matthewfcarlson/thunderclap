// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00213570 @ 0x00213570
struct Item { char pad[8]; int length; };
// equiv-conv: FUN_00212bb0 edx ecx stack stack
int __cdecl FUN_00212bb0(Item* item, int other, int size1, int size2);
void __cdecl FUN_00217830(Item* item, int result, int size1, int size2);
void __cdecl FUN_00213570(Item* item, int other)
{
    int size = item->length - 8;
    int result = FUN_00212bb0(item, other, size, size);
    FUN_00217830(item, result, size, size);
}