// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Condition_10e920_vftable[];

class Condition_10e920 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class InActiveCondition_10e920 : public Condition_10e920 {
  public:
    InActiveCondition_10e920* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

InActiveCondition_10e920* InActiveCondition_10e920::vfunc_5(signed char flags) {
    *(void***)this = Condition_10e920_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
