#include "compat/ptr.h"
typedef unsigned int u32_66a50;
struct Obj_66a50 {
    u32_66a50 a;
};
extern u32_66a50 __fastcall FUN_00230ea0(Obj_66a50*);
u32_66a50* __fastcall target(Obj_66a50* self, void*, u32_66a50* out) {
    u32_66a50 v = FUN_00230ea0(self);
    out[0] = v;
    out[1] = (hulk_uintptr)self;
    return out;
}