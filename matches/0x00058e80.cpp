// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* CNameFlagConditionBase_58e80_vftable[];

class CNameFlagConditionBase_58e80 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class CCollisionFlagCondition : public CNameFlagConditionBase_58e80 {
  public:
    CCollisionFlagCondition* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

CCollisionFlagCondition* CCollisionFlagCondition::vfunc_5(signed char flags) {
    *(void***)this = CNameFlagConditionBase_58e80_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
