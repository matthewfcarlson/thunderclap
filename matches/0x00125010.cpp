// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Condition_125010_vftable[];

class Condition_125010 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class TargetDistanceXZCondition_125010 : public Condition_125010 {
  public:
    TargetDistanceXZCondition_125010* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

TargetDistanceXZCondition_125010* TargetDistanceXZCondition_125010::vfunc_5(signed char flags) {
    *(void***)this = Condition_125010_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
