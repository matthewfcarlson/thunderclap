// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* CCondition_4ce10_vftable[];

class CCondition_4ce10 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class CPropActorStateCondition : public CCondition_4ce10 {
  public:
    CPropActorStateCondition* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

CPropActorStateCondition* CPropActorStateCondition::vfunc_5(signed char flags) {
    *(void***)this = CCondition_4ce10_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
