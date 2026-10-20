// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* CButtonCondition_574d0_vftable[];

class CButtonCondition_574d0 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class CButtonUpCondition : public CButtonCondition_574d0 {
  public:
    CButtonUpCondition* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

CButtonUpCondition* CButtonUpCondition::vfunc_5(signed char flags) {
    *(void***)this = CButtonCondition_574d0_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
