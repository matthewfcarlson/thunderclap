// STATUS: equivalent (tools/equiv.py level 3: 70 inputs, branch coverage 16/20, incomplete)
// TextSelector::vfunc_20 @ 0x000ea1b0
#include "compat/ptr.h"
struct Elem_ea1b0 {
    char data[0x24];
    void FUN_000f7930();
    Elem_ea1b0 *FUN_000f83c0(const Elem_ea1b0 *src);
    void FUN_000f7960();
};

struct Entry_ea1b0 {
    Elem_ea1b0 *items;
    int field_04;
    int count;
    char rest[0x38 - 0x0c];
};

int __cdecl FUN_00266da0(int tag);
void *__cdecl FUN_0008d6d0(hulk_uintptr size);
void __stdcall FUN_00011520(void *arr, unsigned int size, int count, void (Elem_ea1b0::*ctor)());
void __cdecl FUN_0008d340(void *p);

class TextSelector {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void vfunc_20(int index, const Elem_ea1b0 *value);
    char pad[0x17c - 4];
    Entry_ea1b0 entries[127];
    char pad2[0x14];
    int entryCount;
};

void TextSelector::vfunc_20(int index, const Elem_ea1b0 *value)
{
    if (index < 0 || index >= entryCount)
        return;
    Entry_ea1b0 *e = &entries[index];
    if (e->count >= 0x80)
        return;

    int saved = FUN_00266da0(0xe);
    int n = e->count + 1;
    int *mem = (int *)FUN_0008d6d0(n * sizeof(Elem_ea1b0) + 4);
    if (mem) {
        *mem = n;
        Elem_ea1b0 *arr = (Elem_ea1b0 *)(mem + 1);
        FUN_00011520(arr, sizeof(Elem_ea1b0), n, &Elem_ea1b0::FUN_000f7930);
        for (int i = 0; i < e->count; i++)
            arr[i].FUN_000f83c0(&e->items[i]);
        arr[e->count].FUN_000f83c0(value);
        e->count++;

        Elem_ea1b0 *old = e->items;
        if (old) {
            int oldCount = ((int *)old)[-1];
            for (int i = oldCount - 1; i >= 0; i--)
                old[i].FUN_000f7960();
            FUN_0008d340((int *)old - 1);
            e->items = 0;
        }
        e->items = arr;
    }
    FUN_00266da0(saved);
}
