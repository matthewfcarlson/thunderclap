#include "gen/hulkfight.h"

#include "compat/ptr.h"
typedef unsigned int u32_1a1c40;
struct Track_1a1c40 {
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
};
struct Param_1a1c40 {};
struct LuaAction_1a1c40 {
    u32_1a1c40 call(u32_1a1c40, hulk_uintptr, u32_1a1c40);
};
extern "C" void* __cdecl FUN_0008d690(int);

int hulkfight::scenario::LuaTrack::vfunc_10(int __p0, int __p1, int __p2) { u32_1a1c40 a = (u32_1a1c40)__p0; u32_1a1c40 b = (u32_1a1c40)__p1; u32_1a1c40 c = (u32_1a1c40)__p2;

    LuaAction_1a1c40* p = (LuaAction_1a1c40*)FUN_0008d690(0x108);
    if (p)
        return (int)(p->call(a, (hulk_uintptr)this, c));
    return (int)(0);
}
