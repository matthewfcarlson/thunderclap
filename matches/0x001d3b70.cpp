#include "compat/ptr.h"
#include "gen/owners.h"
extern "C" void __cdecl FUN_001d22a0();
typedef unsigned int u32_1d3b70;
class A_1d3b70 {
  public:
    void f(u32_1d3b70);
};
class B_1d3b70 {
  public:
    void f(hulk_uintptr);
};
void __cdecl F3(void*, hulk_uintptr);
void __cdecl F4(void*, void*, int);
void __cdecl F5(void*, int, u32_1d3b70);
void owners::Obj_1d3b70::FUN_001d3b70(hulk_uintptr a, hulk_intptr b) {
    ((A_1d3b70*)((hulk_uintptr)b))->f(((u32_1d3b70)a));
    ((B_1d3b70*)((char*)this + 0xc))->f(((hulk_uintptr)b));
    void* x = field8;
    F3(x, ((hulk_uintptr)b));
    F4(x, (void*)((hulk_intptr)(void (__cdecl*)())&FUN_001d22a0), 1);
    F5(x, 0xffffd8ef, ((u32_1d3b70)a));
}
