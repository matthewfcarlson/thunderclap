// STATUS: equivalent (tools/equiv.py level 3: 19941 inputs, branch coverage 0/0)
// FUN_00219cc0 @ 0x00219cc0
// FUN_00219cc0 @ 0x00219cc0
struct Item { char pad0[6]; unsigned char flag; unsigned char other; int field8; int fieldC; int field10; char pad14[8]; int field1C; }; 
Item* __cdecl FUN_0021add0(void*, int, int, int);
void __cdecl FUN_00217130(void*, Item*, int);
// equiv-conv: FUN_00219be0 esi edi stack
void __cdecl FUN_00219be0(Item*, void*, void*);
// equiv-conv: FUN_00219c30 ebx esi stack
void __cdecl FUN_00219c30(void*, Item*, void*);
Item* __cdecl FUN_00219cc0(void* owner, void* unused, void* arg) {
    Item* item = FUN_0021add0(owner, 0, 0, 0x20);
    FUN_00217130(owner, item, 5);
    item->field8 = 0;
    item->flag = 0xff;
    item->fieldC = 0;
    item->field1C = 0;
    item->other = 0;
    item->field10 = 0;
    FUN_00219be0(item, unused, owner);
    FUN_00219c30(owner, item, arg);
    return item;
}
