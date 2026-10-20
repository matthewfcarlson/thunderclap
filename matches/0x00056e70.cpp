// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* CAxisValueCondition_56e70_vftable[];

class CAxisValueCondition_56e70 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class CAxisDownCondition : public CAxisValueCondition_56e70 {
  public:
    CAxisDownCondition* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

CAxisDownCondition* CAxisDownCondition::vfunc_5(signed char flags) {
    *(void***)this = CAxisValueCondition_56e70_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
