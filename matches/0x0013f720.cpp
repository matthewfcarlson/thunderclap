// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Condition_13f720_vftable[];

class Condition_13f720 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class WallVelocityCondition_13f720 : public Condition_13f720 {
  public:
    WallVelocityCondition_13f720* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

WallVelocityCondition_13f720* WallVelocityCondition_13f720::vfunc_5(signed char flags) {
    *(void***)this = Condition_13f720_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
