// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* CCondition_4d680_vftable[];

class CCondition_4d680 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class CAlertStatusCondition : public CCondition_4d680 {
  public:
    CAlertStatusCondition* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

CAlertStatusCondition* CAlertStatusCondition::vfunc_5(signed char flags) {
    *(void***)this = CCondition_4d680_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
