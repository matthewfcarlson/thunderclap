// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Condition_23cfc0_vftable[];

class Condition_23cfc0 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class NotCondition_23cfc0 : public Condition_23cfc0 {
  public:
    NotCondition_23cfc0* vfunc_5(signed char flags);
};

extern "C" void __cdecl FUN_00267090(void* p); // thunk_FUN_00267090

NotCondition_23cfc0* NotCondition_23cfc0::vfunc_5(signed char flags) {
    *(void***)this = Condition_23cfc0_vftable;
    Destroy();
    if (flags & 1) {
        FUN_00267090(this);
    }
    return this;
}
