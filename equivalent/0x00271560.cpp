// STATUS: equivalent (tools/equiv.py level 3: 71 inputs, branch coverage 12/12)
// FUN_00271560 @ 0x00271560
struct Item { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual signed char v6(); };
struct Entry { Item* item; char extra[0x118]; };
extern Entry DAT_0052842c[];
extern char DAT_004cdc04;
extern char DAT_0052a0f0;
extern int DAT_0052a120;
extern void __cdecl FUN_002697c0(void*,void*,void*,void*,void*);
extern void __cdecl FUN_0026d850(void*);
extern void __cdecl FUN_0026d840(void*);
extern int __cdecl FUN_00270c10(void*);
extern void __cdecl FUN_00270f10(void*,int);
extern void __cdecl FUN_00277b70(void*,Item*,int,int,int);
struct Work { int primary; int secondary; int tertiary; int alternate; char reserved[16]; int data; char rest[0xfc]; };
void __cdecl FUN_00271560(int* output, int name, int flags, int extra) {
    Work work;
    work.secondary = 0;
    work.tertiary = 0;
    FUN_002697c0((void*)name,&work.data,&work.alternate,&work.tertiary,&work.secondary);
    FUN_0026d850(&DAT_0052a0f0);
    int index = FUN_00270c10(&work.alternate);
    Entry* entry = 0;
    if (index != -1) entry = &DAT_0052842c[index];
    if (!entry || !entry->item) {
        if (DAT_004cdc04) {
            FUN_0026d840(&DAT_0052a0f0);
            FUN_00270f10(&work.alternate,DAT_0052a120);
            FUN_0026d850(&DAT_0052a0f0);
            index = FUN_00270c10(&work.alternate);
            entry = index > -1 ? &DAT_0052842c[index] : 0;
        }
    }
    if (!entry || !entry->item) {
        *output = 0;
        FUN_0026d840(&DAT_0052a0f0);
        return;
    }
    Item* item = entry->item;
    int selected = work.tertiary;
    if (item->v6() < 0) selected = work.secondary;
    FUN_00277b70(output,entry->item,selected,flags,extra);
    FUN_0026d840(&DAT_0052a0f0);
}