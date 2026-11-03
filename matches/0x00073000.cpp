#include "compat/ptr.h"
extern "C" char DAT_003fcd5c[];
typedef unsigned int u32_73000;
struct CHitAnimationTrack {};
struct TrackFactoryCasterTemplate {
    void* vftable;
};
extern void FUN_00236ac0(u32_73000, void**);
void FUN_00073000(u32_73000 key) {
    void* caster;
    caster = (void*)((hulk_intptr)DAT_003fcd5c);
    FUN_00236ac0(key, &caster);
}