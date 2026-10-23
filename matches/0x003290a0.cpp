#include "compat/ptr.h"
extern "C" char hulk_at_00433770[];
extern void* DAT_00433774[];
struct Obj_3290a0 {
    void* vptr;
    Obj_3290a0() { vptr = DAT_00433774; }
};
extern void* DAT_00433774[] = {(void*)((hulk_intptr)(hulk_at_00433770 + 0x4))};
void* __fastcall FUN_003290a0(Obj_3290a0* self) {
    self->vptr = DAT_00433774;
    return self;
}
