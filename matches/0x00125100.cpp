// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Condition_125100_vftable[];

class Condition_125100 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class TargetInvincibleCondition_125100 : public Condition_125100 {
  public:
    TargetInvincibleCondition_125100* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

TargetInvincibleCondition_125100* TargetInvincibleCondition_125100::vfunc_5(signed char flags) {
    *(void***)this = Condition_125100_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
