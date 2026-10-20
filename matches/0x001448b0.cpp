// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Track_1448b0_vftable[];

class Track_1448b0 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class MotionTrailStopTrack_1448b0 : public Track_1448b0 {
  public:
    MotionTrailStopTrack_1448b0* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

MotionTrailStopTrack_1448b0* MotionTrailStopTrack_1448b0::vfunc_5(signed char flags) {
    *(void***)this = Track_1448b0_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
