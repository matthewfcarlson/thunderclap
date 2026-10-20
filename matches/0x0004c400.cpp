// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* CCondition_4c400_vftable[];

class CCondition_4c400 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class CCollisionPushbackYAngleCondition : public CCondition_4c400 {
  public:
    CCollisionPushbackYAngleCondition* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

CCollisionPushbackYAngleCondition* CCollisionPushbackYAngleCondition::vfunc_5(signed char flags) {
    *(void***)this = CCondition_4c400_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
