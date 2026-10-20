// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* CAxisCondition_4b6f0_vftable[];

class CAxisCondition_4b6f0 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class CAxisDoubleTapCondition : public CAxisCondition_4b6f0 {
  public:
    CAxisDoubleTapCondition* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

CAxisDoubleTapCondition* CAxisDoubleTapCondition::vfunc_5(signed char flags) {
    *(void***)this = CAxisCondition_4b6f0_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
