// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Track_125190_vftable[];

class Track_125190 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class AcquireTargetTrack_125190 : public Track_125190 {
  public:
    AcquireTargetTrack_125190* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

AcquireTargetTrack_125190* AcquireTargetTrack_125190::vfunc_5(signed char flags) {
    *(void***)this = Track_125190_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
