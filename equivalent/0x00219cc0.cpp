// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 0/0)
// FUN_00219cc0 @ 0x00219cc0
struct Item { char pad0[6]; unsigned char flag; unsigned char other; int field8; int fieldC; int field10; char pad14[8]; int field1C; }; 
Item* __cdecl FUN_0021add0(void*, int, int, int);
void __cdecl FUN_00217130(void*, Item*, int);
void __cdecl FUN_00219be0(void*);
void __cdecl FUN_00219c30(void*);
Item* __cdecl FUN_00219cc0(void* owner, void* unused, void* arg) {
    Item* item = FUN_0021add0(owner, 0, 0, 0x20);
    FUN_00217130(owner, item, 5);
    item->field8 = 0;
    item->flag = 0xff;
    item->fieldC = 0;
    item->field1C = 0;
    item->other = 0;
    item->field10 = 0;
    FUN_00219be0(owner);
    FUN_00219c30(arg);
    return item;
}