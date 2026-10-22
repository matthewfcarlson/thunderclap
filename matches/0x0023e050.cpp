// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Track_23e050_vftable[];

class Track_23e050 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class WaitTrack_23e050 : public Track_23e050 {
  public:
    WaitTrack_23e050* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

WaitTrack_23e050* WaitTrack_23e050::vfunc_5(signed char flags) {
    *(void***)this = Track_23e050_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
