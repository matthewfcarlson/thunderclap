#include "compat/ptr.h"
#include "gen/owners.h"
extern "C" void __cdecl FUN_001d22a0();
extern "C" char DAT_00422810[];
struct Closure4_1d46d0 {
    void* vftable;
    char pad[0x1c];
    int field20;
    void init(int, int);
};
void* __cdecl alloc(hulk_uintptr);
void __cdecl taskC(int, Closure4_1d46d0*);
void __cdecl taskD(int, void*, int);
void __cdecl taskE(int, int, int);
struct List_1d46d0 {
    void attach(Closure4_1d46d0*);
};
struct ScriptHandler_1d46d0 {
    char pad[8];
    int x8;
    List_1d46d0 list;
    void target(hulk_intptr, hulk_intptr, hulk_intptr);
};
void ScriptHandler_1d46d0::target(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    Closure4_1d46d0* p = (Closure4_1d46d0*)alloc(0x24);
    if (p) {
        p->init(a, c);
        p->vftable = (void*)((hulk_intptr)DAT_00422810);
        p->field20 = b;
    } else
        p = 0;
    ((owners::CAgent_1d04b0 *)p)->FUN_001d04b0((hulk_intptr)a);
    list.attach(p);
    int x = x8;
    taskC(x, p);
    taskD(x, (void*)((hulk_intptr)(void (__cdecl*)())&FUN_001d22a0), 1);
    taskE(x, 0xffffd8ef, a);
}
