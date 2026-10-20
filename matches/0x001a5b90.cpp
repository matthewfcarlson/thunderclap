// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Condition_1a5b90_vftable[];

class Condition_1a5b90 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class Event_PropStateDescCondition_1a5b90 : public Condition_1a5b90 {
  public:
    Event_PropStateDescCondition_1a5b90* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

Event_PropStateDescCondition_1a5b90* Event_PropStateDescCondition_1a5b90::vfunc_5(signed char flags) {
    *(void***)this = Condition_1a5b90_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
