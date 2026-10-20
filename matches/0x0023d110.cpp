// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* ConditionFactory_23d110_vftable[];

class ConditionFactory_23d110 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class CSweepTrack_23d110 : public ConditionFactory_23d110 {
  public:
    CSweepTrack_23d110* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

CSweepTrack_23d110* CSweepTrack_23d110::vfunc_5(signed char flags) {
    *(void***)this = ConditionFactory_23d110_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
