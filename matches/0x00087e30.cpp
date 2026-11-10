#include "compat/ptr.h"
typedef unsigned int u32_87e30;
extern "C" unsigned __int64 FUN_00267f40();
// CTimeManager (0x00087e30 constructs it): its fields, and the member 0x000860c0 (time_GetElapsedTime) it binds to
// Lua through ScriptHandler's Closure0<CTimeManager, float> helper 0x00087d50 (a real member-function pointer: one
// code pointer on every build, docs/native-build.md sh2).
struct Obj_87e30 {
    u32_87e30 v;
    u32_87e30 x;
    u32_87e30 a, b, c, d, e, f;
    u32_87e30 pad[6];
    u32_87e30 limit;
    u32_87e30 other;
    float FUN_000860c0();
};
struct Handler_87e30 {
    void FUN_00087d50(const char*, Obj_87e30*, float (Obj_87e30::*)());
};
extern "C" Handler_87e30* __cdecl FUN_001d4c90();
Obj_87e30* __fastcall FUN_00087e30(Obj_87e30* p) {
    p->limit = 0x10000;
    p->other = 0;
    unsigned __int64 q = FUN_00267f40();
    p->a = (u32_87e30)q;
    p->b = (u32_87e30)(q >> 32);
    p->c = 0;
    p->d = 0;
    p->e = 0;
    p->f = 0;
    p->v = 0x1046a;
    p->x = 0;
    Handler_87e30* h = FUN_001d4c90();
    if (h)
        h->FUN_00087d50("time_GetElapsedTime", p, &Obj_87e30::FUN_000860c0);
    return p;
}
