// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Condition_150450_vftable[];

class Condition_150450 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class CollisionExplosionCondition_150450 : public Condition_150450 {
  public:
    CollisionExplosionCondition_150450* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

CollisionExplosionCondition_150450* CollisionExplosionCondition_150450::vfunc_5(signed char flags) {
    *(void***)this = Condition_150450_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
