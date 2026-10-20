// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* CAxisTimeCondition_57010_vftable[];

class CAxisTimeCondition_57010 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class CAxisReleaseCondition : public CAxisTimeCondition_57010 {
  public:
    CAxisReleaseCondition* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

CAxisReleaseCondition* CAxisReleaseCondition::vfunc_5(signed char flags) {
    *(void***)this = CAxisTimeCondition_57010_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
