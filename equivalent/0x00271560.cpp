// STATUS: equivalent (tools/equiv.py level 3: 71 inputs, branch coverage 12/12)
// FUN_00271560 @ 0x00271560
#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"

struct Item_271560 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual signed char v6(); };
// the drive registry (records.h CoreDriveRegistryEntry): the entry's drive
extern void __cdecl FUN_002697c0(void*,void*,void*,void*,void*);
extern void __cdecl FUN_0026d850(void*);
extern void __cdecl FUN_0026d840(void*);
extern "C" int __cdecl FUN_00270c10(const char *);
extern "C" int __cdecl FUN_00270f10(const char *, void *);
extern void __cdecl FUN_00277b70(void*,Item_271560*,int,int,int);
struct Work_271560 { int primary; int secondary; int tertiary; int alternate; char reserved[16]; int data; char rest[0xfc]; };
extern "C" void __cdecl FUN_00271560(int* output, hulk_intptr name, int flags, int extra) {
    Work_271560 work;
    work.secondary = 0;
    work.tertiary = 0;
    FUN_002697c0((void*)name,&work.data,&work.alternate,&work.tertiary,&work.secondary);
    FUN_0026d850(((char*)DAT_0052a0f0));
    int index = FUN_00270c10((const char *)(void *)(&work.alternate));
    void** entry = 0;
    if (index != -1) entry = &DAT_00528418[index].drive;
    if (!entry || !*entry) {
        if ((*(char*)&DAT_004cdc04)) {
            FUN_0026d840(((char*)DAT_0052a0f0));
            FUN_00270f10((const char *)(void *)(&work.alternate),(void *)(hulk_uintptr)(int)DAT_0052a120);
            FUN_0026d850(((char*)DAT_0052a0f0));
            index = FUN_00270c10((const char *)(void *)(&work.alternate));
            entry = index > -1 ? &DAT_00528418[index].drive : 0;
        }
    }
    if (!entry || !*entry) {
        *output = 0;
        FUN_0026d840(((char*)DAT_0052a0f0));
        return;
    }
    Item_271560* item = (Item_271560*)*entry;
    int selected = work.tertiary;
    if (item->v6() < 0) selected = work.secondary;
    FUN_00277b70(output,(Item_271560*)*entry,selected,flags,extra);
    FUN_0026d840(((char*)DAT_0052a0f0));
}