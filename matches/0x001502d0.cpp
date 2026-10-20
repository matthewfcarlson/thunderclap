// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Condition_1502d0_vftable[];

class Condition_1502d0 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class CollisionTargetPriorityCondition_1502d0 : public Condition_1502d0 {
  public:
    CollisionTargetPriorityCondition_1502d0* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

CollisionTargetPriorityCondition_1502d0* CollisionTargetPriorityCondition_1502d0::vfunc_5(signed char flags) {
    *(void***)this = Condition_1502d0_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
