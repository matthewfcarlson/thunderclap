// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Condition_10e750_vftable[];

class Condition_10e750 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class DefendingCondition_10e750 : public Condition_10e750 {
  public:
    DefendingCondition_10e750* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

DefendingCondition_10e750* DefendingCondition_10e750::vfunc_5(signed char flags) {
    *(void***)this = Condition_10e750_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
