// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Condition_150360_vftable[];

class Condition_150360 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class CollisionTargetIsTargetCondition_150360 : public Condition_150360 {
  public:
    CollisionTargetIsTargetCondition_150360* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

CollisionTargetIsTargetCondition_150360* CollisionTargetIsTargetCondition_150360::vfunc_5(signed char flags) {
    *(void***)this = Condition_150360_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
