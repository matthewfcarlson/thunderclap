// Same code shape as 0x00060920 (propagated; names are from that function)
#include "compat/ptr.h"
extern int CEffectStopTrack_vftable;
class CEffectStopTrack {
  public:
};
void __fastcall FUN_00068c70(CEffectStopTrack*);
void __fastcall FUN_002343d0(CEffectStopTrack* self) {
    *(hulk_intptr*)self = (hulk_intptr)&CEffectStopTrack_vftable;
    FUN_00068c70(self);
}