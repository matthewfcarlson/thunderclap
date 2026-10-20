// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Condition_10e800_vftable[];

class Condition_10e800 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class PropsToChuckCondition_10e800 : public Condition_10e800 {
  public:
    PropsToChuckCondition_10e800* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

PropsToChuckCondition_10e800* PropsToChuckCondition_10e800::vfunc_5(signed char flags) {
    *(void***)this = Condition_10e800_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
