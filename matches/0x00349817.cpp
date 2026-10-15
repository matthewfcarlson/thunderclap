// Same code shape as 0x00060920 (propagated; names are from that function)
extern int CEffectStopTrack_vftable;
class CEffectStopTrack {
  public:
};
void __fastcall FUN_00068c70(CEffectStopTrack*);
void __fastcall FUN_00349817(CEffectStopTrack* self) {
    *(int*)self = (int)&CEffectStopTrack_vftable;
    FUN_00068c70(self);
}