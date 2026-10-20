// Same code shape as 0x00066a50 (propagated; names are from that function)
#include "compat/ptr.h"
typedef unsigned int u32_1ad6d0;
struct Obj_1ad6d0 {
    u32_1ad6d0 a;
};
extern u32_1ad6d0 __fastcall FUN_00230ea0(Obj_1ad6d0*);
u32_1ad6d0* __fastcall target(Obj_1ad6d0* self, void*, u32_1ad6d0* out) {
    u32_1ad6d0 v = FUN_00230ea0(self);
    out[0] = v;
    out[1] = (hulk_uintptr)self;
    return out;
}