// Same code shape as 0x00060920 (propagated; names are from that function)
#include "compat/ptr.h"
extern int CEffectStopTrack_vftable;
class CEffectStopTrack {
  public:
};
void __fastcall FUN_002345b0(CEffectStopTrack*);
void __fastcall FUN_00235c40(CEffectStopTrack* self) {
    *(hulk_intptr*)self = (hulk_intptr)&CEffectStopTrack_vftable;
    FUN_002345b0(self);
}