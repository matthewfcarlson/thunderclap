// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* CCondition_4c2f0_vftable[];

class CCondition_4c2f0 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class CCollisionPushbackYCondition : public CCondition_4c2f0 {
  public:
    CCollisionPushbackYCondition* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

CCollisionPushbackYCondition* CCollisionPushbackYCondition::vfunc_5(signed char flags) {
    *(void***)this = CCondition_4c2f0_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
