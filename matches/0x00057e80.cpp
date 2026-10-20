// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* CAlertStatusCondition_57e80_vftable[];

class CAlertStatusCondition_57e80 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class CGrappleAlertStatusCondition : public CAlertStatusCondition_57e80 {
  public:
    CGrappleAlertStatusCondition* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

CGrappleAlertStatusCondition* CGrappleAlertStatusCondition::vfunc_5(signed char flags) {
    *(void***)this = CAlertStatusCondition_57e80_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
