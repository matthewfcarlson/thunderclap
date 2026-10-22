#include "compat/ptr.h"
typedef unsigned int u32_262090;
extern int vtable_262090;
struct SeqEventLogicRepeat_262090 {
    void init();
};
extern u32_262090 __cdecl makeobj(const char*, int);
extern int zeroData;
struct Obj_262090 {
    hulk_uintptr vt;
    char pad[0x18];
    SeqEventLogicRepeat_262090 s;
    char pad2[0x1b];
    u32_262090 a;
    u32_262090 b;
    u32_262090 flags;
    unsigned char c[4];
};
Obj_262090* __fastcall FUN_00262090(Obj_262090* p) {
    p->vt = (hulk_uintptr)&vtable_262090;
    p->s.init();
    p->a = makeobj("MySeqTrack", 0);
    p->b = makeobj((const char*)&zeroData, 0);
    p->c[0] &= 0xfc;
    p->flags = (p->flags & 0xfffffc01) | 1;
    return p;
}