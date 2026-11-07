#include "decls/data/engine/audio.h"
#include "decls/data/records.h"
// data: gCount_260680 = DAT_004e7a18.count

#include "compat/ptr.h"
#include "gen/owners.h"
extern "C" char DAT_0042aa7c[];
typedef unsigned int u32_260680;
extern "C" void __cdecl FUN_002603e0(void *, void *);
struct Sub_260680 {
};
struct Obj_260680 {
    hulk_uintptr vf;
    char pad[0x54];
    void FUN_002580e0();
};
extern "C" void __fastcall FUN_00260680(Obj_260680* self) {
    void* p = (*(void**)&DAT_004cd380);
    self->vf = ((hulk_intptr)DAT_0042aa7c);
    FUN_002603e0(p, self);
    --DAT_004e7a18.count;
    ((owners::Str_240060 *)&((SeqEventTypeHead *)self)->name)->FUN_00240060();
    self->FUN_002580e0();
}
