#include "compat/ptr.h"
#include "decls/data/engine/audio.h"
#include "gen/audio.h"

extern "C" char DAT_00429434[];
typedef unsigned int u32_24d690;
struct ListenerEffectXBoxType_nv_24d690 {
    void Init(void*, void*, int, int);
};
struct Obj_24d690 {
    void* vf;
};
Obj_24d690* __fastcall Target(Obj_24d690* self) {
    ((ListenerEffectXBoxType_nv_24d690*)(((audio::ListenerEffectXBoxType*)(((audio::ListenerEffectXBoxType*)(self))))))->Init((void*)((hulk_intptr)DAT_004e6328), (void*)((hulk_intptr)DAT_004e6320), 0x30, 4);
    self->vf = (void*)((hulk_intptr)DAT_00429434);
    return self;
}