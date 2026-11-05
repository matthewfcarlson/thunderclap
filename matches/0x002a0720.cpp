// Same code shape as 0x00060920 (propagated; names are from that function)
#include "compat/ptr.h"
extern int CEffectStopTrack_vftable;
class CEffectStopTrack {
  public:
};
void __fastcall FUN_0027afd0(CEffectStopTrack*);
extern "C" void __fastcall FUN_002a0720(CEffectStopTrack* self) {
    *(hulk_intptr*)self = (hulk_intptr)&CEffectStopTrack_vftable;
    FUN_0027afd0(self);
}