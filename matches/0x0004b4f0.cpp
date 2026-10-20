// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* CAxisTimeCondition_4b4f0_vftable[];

class CAxisTimeCondition_4b4f0 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class CAxisValueCondition : public CAxisTimeCondition_4b4f0 {
  public:
    CAxisValueCondition* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

CAxisValueCondition* CAxisValueCondition::vfunc_5(signed char flags) {
    *(void***)this = CAxisTimeCondition_4b4f0_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
