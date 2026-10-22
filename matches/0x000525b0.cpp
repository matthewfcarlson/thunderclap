// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* ConditionFactory_525b0_vftable[];

class ConditionFactory_525b0 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class ConditionFactoryTemplate_0525b0 : public ConditionFactory_525b0 {
  public:
    ConditionFactoryTemplate_0525b0* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

ConditionFactoryTemplate_0525b0* ConditionFactoryTemplate_0525b0::vfunc_5(signed char flags) {
    *(void***)this = ConditionFactory_525b0_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
