// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* ConditionFactory_23d3d0_vftable[];

class ConditionFactory_23d3d0 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class ConditionFactoryTemplate_23d3d0 : public ConditionFactory_23d3d0 {
  public:
    ConditionFactoryTemplate_23d3d0* vfunc_5(signed char flags);
};

extern "C" void __cdecl FUN_00267090(void* p); // thunk_FUN_00267090

ConditionFactoryTemplate_23d3d0* ConditionFactoryTemplate_23d3d0::vfunc_5(signed char flags) {
    *(void***)this = ConditionFactory_23d3d0_vftable;
    Destroy();
    if (flags & 1) {
        FUN_00267090(this);
    }
    return this;
}
