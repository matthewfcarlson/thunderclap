#include "compat/ptr.h"
typedef unsigned int u32_87e30;
extern unsigned __int64 FUN_00267f40();
extern hulk_intptr FUN_001d4c90();
struct Obj_87e30;
struct Handler_87e30 {
    void Register(const char*, Obj_87e30*, void (*)());
};
extern void FUN_000860c0();
struct Obj_87e30 {
    u32_87e30 v;
    u32_87e30 x;
    u32_87e30 a, b, c, d, e, f;
    u32_87e30 pad[6];
    u32_87e30 limit;
    u32_87e30 other;
};
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
    Handler_87e30* h = (Handler_87e30*)FUN_001d4c90();
    if (h)
        h->Register("time_GetElapsedTime", p, FUN_000860c0);
    return p;
}