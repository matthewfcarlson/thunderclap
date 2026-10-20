// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Condition_150570_vftable[];

class Condition_150570 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class CollisionInterruptPriorityCondition_150570 : public Condition_150570 {
  public:
    CollisionInterruptPriorityCondition_150570* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

CollisionInterruptPriorityCondition_150570* CollisionInterruptPriorityCondition_150570::vfunc_5(signed char flags) {
    *(void***)this = Condition_150570_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
