#include "compat/ptr.h"
typedef unsigned int u32_1a1c40;
struct Track {
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
struct Param {};
struct LuaTrack : Track, Param {
    virtual u32_1a1c40 f10(u32_1a1c40, u32_1a1c40, u32_1a1c40);
};
struct Helper_1a1c40 {
    u32_1a1c40 call(u32_1a1c40, u32_1a1c40, u32_1a1c40);
};
extern "C" void* __cdecl FUN_0008d690(int);
u32_1a1c40 LuaTrack::f10(u32_1a1c40 a, u32_1a1c40 b, u32_1a1c40 c) {
    Helper_1a1c40* p = (Helper_1a1c40*)FUN_0008d690(0x108);
    if (p)
        return p->call(a, (hulk_uintptr)this, c);
    return 0;
}
