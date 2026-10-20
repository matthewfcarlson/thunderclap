// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Entity_234560_vftable[];

class Entity_234560 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class ConditionFactory_234560 : public Entity_234560 {
  public:
    ConditionFactory_234560* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

ConditionFactory_234560* ConditionFactory_234560::vfunc_5(signed char flags) {
    *(void***)this = Entity_234560_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
