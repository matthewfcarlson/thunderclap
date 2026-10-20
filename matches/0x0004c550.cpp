// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* CCondition_4c550_vftable[];

class CCondition_4c550 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class CCollisionStunTimeCondition : public CCondition_4c550 {
  public:
    CCollisionStunTimeCondition* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

CCollisionStunTimeCondition* CCollisionStunTimeCondition::vfunc_5(signed char flags) {
    *(void***)this = CCondition_4c550_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
