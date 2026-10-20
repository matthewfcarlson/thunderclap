#include "compat/ptr.h"
extern "C" char hulk_at_00433770[];
extern void* g_vftable_3290a0[];
struct Obj_3290a0 {
    void* vptr;
    Obj_3290a0() { vptr = g_vftable_3290a0; }
};
extern void* g_vftable_3290a0[] = {(void*)((hulk_intptr)(hulk_at_00433770 + 0x4))};
void* __fastcall FUN_003290a0(Obj_3290a0* self) {
    self->vptr = g_vftable_3290a0;
    return self;
}
