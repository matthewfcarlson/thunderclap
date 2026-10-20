// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Condition_167870_vftable[];

class Condition_167870 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class VelocityAnimatedXZAngleCondition_167870 : public Condition_167870 {
  public:
    VelocityAnimatedXZAngleCondition_167870* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

VelocityAnimatedXZAngleCondition_167870* VelocityAnimatedXZAngleCondition_167870::vfunc_5(signed char flags) {
    *(void***)this = Condition_167870_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
