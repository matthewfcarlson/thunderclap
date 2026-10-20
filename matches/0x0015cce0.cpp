// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Condition_15cce0_vftable[];

class Condition_15cce0 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class LocomotingCondition_15cce0 : public Condition_15cce0 {
  public:
    LocomotingCondition_15cce0* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

LocomotingCondition_15cce0* LocomotingCondition_15cce0::vfunc_5(signed char flags) {
    *(void***)this = Condition_15cce0_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
