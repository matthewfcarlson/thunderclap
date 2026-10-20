// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Condition_194ee0_vftable[];

class Condition_194ee0 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class PropGrabbableIsMissileCondition_194ee0 : public Condition_194ee0 {
  public:
    PropGrabbableIsMissileCondition_194ee0* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

PropGrabbableIsMissileCondition_194ee0* PropGrabbableIsMissileCondition_194ee0::vfunc_5(signed char flags) {
    *(void***)this = Condition_194ee0_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
