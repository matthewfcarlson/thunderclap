// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Condition_194f10_vftable[];

class Condition_194f10 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class PropIsMissileCondition_194f10 : public Condition_194f10 {
  public:
    PropIsMissileCondition_194f10* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

PropIsMissileCondition_194f10* PropIsMissileCondition_194f10::vfunc_5(signed char flags) {
    *(void***)this = Condition_194f10_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
