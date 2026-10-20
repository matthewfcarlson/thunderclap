// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Track_134c00_vftable[];

class Track_134c00 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class FlyingDashTrack_134c00 : public Track_134c00 {
  public:
    FlyingDashTrack_134c00* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

FlyingDashTrack_134c00* FlyingDashTrack_134c00::vfunc_5(signed char flags) {
    *(void***)this = Track_134c00_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
