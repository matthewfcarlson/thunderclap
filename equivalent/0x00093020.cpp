// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 22/22)
// FUN_00093020 @ 0x00093020
extern char DAT_0049dab8;
extern char DAT_0049dafc;
struct Value { void FUN_0027b040(void* source); char bytes[20]; };
struct Item { char pad[16]; Value value; int kind; char data[8]; };
extern Item* __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern void __cdecl FUN_00267760(void*, int, void*);
struct Container { void* items[50]; void FUN_00093020(int index, void* source, void* data); };
void Container::FUN_00093020(int index, void* source, void* data) {
 if (index < 0 || index > 49) return;
 Item* item = FUN_00344e74(items[index], 0, &DAT_0049dab8, &DAT_0049dafc, 0);
 if (!item) return;
 item->value.FUN_0027b040(source);
 FUN_00267760(item->data, 8, data);
 switch(index) {
 case 2: item->kind=0x58; break;
 case 26: item->kind=0x67; break;
 case 37: item->kind=0x77; break;
 case 47: item->kind=0x87; break;
 case 38: item->kind=0x88; break;
 case 20: item->kind=0x89; break;
 case 19: item->kind=0x8d; break;
 case 1: item->kind=0x21; break;
 }
}
