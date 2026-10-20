#include "compat/ptr.h"
extern "C" void __cdecl FUN_001d22a0();
extern "C" char DAT_00422810[];
struct Closure4 {
    void* vftable;
    char pad[0x1c];
    int field20;
    void init(int, int);
    void task(int);
};
void* __cdecl alloc(hulk_uintptr);
void __cdecl taskC(int, Closure4*);
void __cdecl taskD(int, void*, int);
void __cdecl taskE(int, int, int);
struct List_1d46d0 {
    void attach(Closure4*);
};
struct Handler_1d46d0 {
    char pad[8];
    int x8;
    List_1d46d0 list;
    void target(int, int, int);
};
void Handler_1d46d0::target(int a, int b, int c) {
    Closure4* p = (Closure4*)alloc(0x24);
    if (p) {
        p->init(a, c);
        p->vftable = (void*)((hulk_intptr)DAT_00422810);
        p->field20 = b;
    } else
        p = 0;
    p->task(a);
    list.attach(p);
    int x = x8;
    taskC(x, p);
    taskD(x, (void*)((hulk_intptr)(void (__cdecl*)())&FUN_001d22a0), 1);
    taskE(x, 0xffffd8ef, a);
}
