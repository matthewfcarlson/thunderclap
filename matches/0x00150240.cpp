// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Condition_150240_vftable[];

class Condition_150240 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class CollisionThrowCondition_150240 : public Condition_150240 {
  public:
    CollisionThrowCondition_150240* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

CollisionThrowCondition_150240* CollisionThrowCondition_150240::vfunc_5(signed char flags) {
    *(void***)this = Condition_150240_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
