// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Condition_150270_vftable[];

class Condition_150270 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class CollisionSourceSizeCondition_150270 : public Condition_150270 {
  public:
    CollisionSourceSizeCondition_150270* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

CollisionSourceSizeCondition_150270* CollisionSourceSizeCondition_150270::vfunc_5(signed char flags) {
    *(void***)this = Condition_150270_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
