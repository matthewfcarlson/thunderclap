// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Condition_148170_vftable[];

class Condition_148170 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class CivilianAttachedCondition_148170 : public Condition_148170 {
  public:
    CivilianAttachedCondition_148170* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

CivilianAttachedCondition_148170* CivilianAttachedCondition_148170::vfunc_5(signed char flags) {
    *(void***)this = Condition_148170_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
