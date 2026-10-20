// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Condition_167900_vftable[];

class Condition_167900 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class HealthPercentCondition_167900 : public Condition_167900 {
  public:
    HealthPercentCondition_167900* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

HealthPercentCondition_167900* HealthPercentCondition_167900::vfunc_5(signed char flags) {
    *(void***)this = Condition_167900_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
