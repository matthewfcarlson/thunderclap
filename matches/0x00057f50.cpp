// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* CMotionStateCondition_57f50_vftable[];

class CMotionStateCondition_57f50 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class CGrappleMotionStateCondition : public CMotionStateCondition_57f50 {
  public:
    CGrappleMotionStateCondition* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

CGrappleMotionStateCondition* CGrappleMotionStateCondition::vfunc_5(signed char flags) {
    *(void***)this = CMotionStateCondition_57f50_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
