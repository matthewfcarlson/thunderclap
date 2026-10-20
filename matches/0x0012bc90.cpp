// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Condition_12bc90_vftable[];

class Condition_12bc90 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class ShotFailCountCondition_12bc90 : public Condition_12bc90 {
  public:
    ShotFailCountCondition_12bc90* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

ShotFailCountCondition_12bc90* ShotFailCountCondition_12bc90::vfunc_5(signed char flags) {
    *(void***)this = Condition_12bc90_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
