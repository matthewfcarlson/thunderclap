// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Condition_125130_vftable[];

class Condition_125130 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class CanSeeTargetCondition_125130 : public Condition_125130 {
  public:
    CanSeeTargetCondition_125130* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

CanSeeTargetCondition_125130* CanSeeTargetCondition_125130::vfunc_5(signed char flags) {
    *(void***)this = Condition_125130_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
