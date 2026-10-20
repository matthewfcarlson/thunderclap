// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Condition_167840_vftable[];

class Condition_167840 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class VelocityXZCondition_167840 : public Condition_167840 {
  public:
    VelocityXZCondition_167840* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

VelocityXZCondition_167840* VelocityXZCondition_167840::vfunc_5(signed char flags) {
    *(void***)this = Condition_167840_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
