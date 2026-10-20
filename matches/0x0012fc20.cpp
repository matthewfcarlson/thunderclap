// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Condition_12fc20_vftable[];

class Condition_12fc20 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class UnlockableCondition_12fc20 : public Condition_12fc20 {
  public:
    UnlockableCondition_12fc20* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

UnlockableCondition_12fc20* UnlockableCondition_12fc20::vfunc_5(signed char flags) {
    *(void***)this = Condition_12fc20_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
