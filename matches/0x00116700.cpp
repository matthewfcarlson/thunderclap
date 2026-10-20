// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Condition_116700_vftable[];

class Condition_116700 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class LocatorDistanceCondition_116700 : public Condition_116700 {
  public:
    LocatorDistanceCondition_116700* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

LocatorDistanceCondition_116700* LocatorDistanceCondition_116700::vfunc_5(signed char flags) {
    *(void***)this = Condition_116700_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
