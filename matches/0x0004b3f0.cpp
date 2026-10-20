// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* CAxisCondition_4b3f0_vftable[];

class CAxisCondition_4b3f0 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class CAxisSpeedCondition : public CAxisCondition_4b3f0 {
  public:
    CAxisSpeedCondition* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

CAxisSpeedCondition* CAxisSpeedCondition::vfunc_5(signed char flags) {
    *(void***)this = CAxisCondition_4b3f0_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
