// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Condition_10e870_vftable[];

class Condition_10e870 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class LeashedCondition_10e870 : public Condition_10e870 {
  public:
    LeashedCondition_10e870* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

LeashedCondition_10e870* LeashedCondition_10e870::vfunc_5(signed char flags) {
    *(void***)this = Condition_10e870_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
