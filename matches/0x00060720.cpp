#include "compat/ptr.h"
extern "C" char DAT_003faa80[];
typedef unsigned int u32_60720;
struct Helper_60720 {
    void Init();
};
struct CEffectTrack {
    u32_60720 vft;
    char pad[0x30 - 4];
    void Finish();
};
void __fastcall FUN_00060720(CEffectTrack* self) {
    self->vft = ((hulk_intptr)DAT_003faa80);
    ((Helper_60720*)((char*)self + 0x30))->Init();
    ((Helper_60720*)((char*)self + 0x28))->Init();
    ((Helper_60720*)((char*)self + 0x18))->Init();
    self->Finish();
}
