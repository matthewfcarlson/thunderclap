// Same code shape as 0x00060920 (propagated; names are from that function)
#include "compat/ptr.h"
extern int CEffectStopTrack_vftable;
class CEffectStopTrack {
  public:
};
void __fastcall FUN_000e9030(CEffectStopTrack*);
void __fastcall FUN_000e92b0(CEffectStopTrack* self) {
    *(hulk_intptr*)self = (hulk_intptr)&CEffectStopTrack_vftable;
    FUN_000e9030(self);
}