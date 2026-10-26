#include "decls/data/game/global.h"
// data: g_zero_360b0 = DAT_003f32e0

#include "compat/ptr.h"
struct Obj_360b0 {
    char pad[0x11c];
    void* ptr;
    char pad2[0x1b14 - 0x120];
    float value;
};
hulk_freg __fastcall FUN_000360b0(Obj_360b0* p) {
    if (p->ptr)
        return p->value * *(float*)((char*)p->ptr + 0x134);
    return DAT_003f32e0;
}