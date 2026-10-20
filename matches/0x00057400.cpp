// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* CButtonCondition_57400_vftable[];

class CButtonCondition_57400 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class CButtonReleaseCondition : public CButtonCondition_57400 {
  public:
    CButtonReleaseCondition* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

CButtonReleaseCondition* CButtonReleaseCondition::vfunc_5(signed char flags) {
    *(void***)this = CButtonCondition_57400_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
