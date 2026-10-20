// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Condition_1501e0_vftable[];

class Condition_1501e0 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class InterruptAccumulatorCondition_1501e0 : public Condition_1501e0 {
  public:
    InterruptAccumulatorCondition_1501e0* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

InterruptAccumulatorCondition_1501e0* InterruptAccumulatorCondition_1501e0::vfunc_5(signed char flags) {
    *(void***)this = Condition_1501e0_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
