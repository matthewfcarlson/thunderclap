// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Condition_18d300_vftable[];

class Condition_18d300 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class TimerCondition_18d300 : public Condition_18d300 {
  public:
    TimerCondition_18d300* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

TimerCondition_18d300* TimerCondition_18d300::vfunc_5(signed char flags) {
    *(void***)this = Condition_18d300_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
