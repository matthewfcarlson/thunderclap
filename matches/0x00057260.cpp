// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* CButtonValueCondition_57260_vftable[];

class CButtonValueCondition_57260 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class CButtonDownCondition : public CButtonValueCondition_57260 {
  public:
    CButtonDownCondition* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

CButtonDownCondition* CButtonDownCondition::vfunc_5(signed char flags) {
    *(void***)this = CButtonValueCondition_57260_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
