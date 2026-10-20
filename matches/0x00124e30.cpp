// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Condition_124e30_vftable[];

class Condition_124e30 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class TargetTypeCondition_124e30 : public Condition_124e30 {
  public:
    TargetTypeCondition_124e30* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

TargetTypeCondition_124e30* TargetTypeCondition_124e30::vfunc_5(signed char flags) {
    *(void***)this = Condition_124e30_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
