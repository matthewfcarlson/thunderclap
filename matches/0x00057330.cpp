// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* CButtonValueCondition_57330_vftable[];

class CButtonValueCondition_57330 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class CButtonPressCondition : public CButtonValueCondition_57330 {
  public:
    CButtonPressCondition* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

CButtonPressCondition* CButtonPressCondition::vfunc_5(signed char flags) {
    *(void***)this = CButtonValueCondition_57330_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
