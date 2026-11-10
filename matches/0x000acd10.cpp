// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* CGameCamera_acd10_vftable[];

class CGameCamera_acd10 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class CScriptCamera_acd10 : public CGameCamera_acd10 {
  public:
    CScriptCamera_acd10* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

CScriptCamera_acd10* CScriptCamera_acd10::vfunc_5(signed char flags) {
    *(void***)this = CGameCamera_acd10_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
