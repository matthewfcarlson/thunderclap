extern int CEffectStopTrack_vftable;
class CEffectStopTrack { public: };
void __fastcall FUN_00068c70(CEffectStopTrack*);
void __fastcall FUN_00060920(CEffectStopTrack* self) { *(int*)self = (int)&CEffectStopTrack_vftable; FUN_00068c70(self); }