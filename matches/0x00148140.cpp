// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Condition_148140_vftable[];

class Condition_148140 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class GrappleAttachedCondition_148140 : public Condition_148140 {
  public:
    GrappleAttachedCondition_148140* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

GrappleAttachedCondition_148140* GrappleAttachedCondition_148140::vfunc_5(signed char flags) {
    *(void***)this = Condition_148140_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
