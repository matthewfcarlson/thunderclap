#include "decls/data/engine/audio.h"
// data: gCount_260680 = DAT_004e7a2c

#include "compat/ptr.h"
extern "C" char DAT_0042aa7c[];
typedef unsigned int u32_260680;
extern "C" void __cdecl FUN_002603e0(void *, void *);
struct Sub_260680 {
    void Close();
};
struct Obj_260680 {
    hulk_uintptr vf;
    char pad[0x54];
    void Tail();
};
extern "C" void __fastcall FUN_00260680(Obj_260680* self) {
    void* p = (*(void**)&DAT_004cd380);
    self->vf = ((hulk_intptr)DAT_0042aa7c);
    FUN_002603e0(p, self);
    --(*(int*)&DAT_004e7a2c);
    ((Sub_260680*)((char*)self + 0x58))->Close();
    self->Tail();
}
