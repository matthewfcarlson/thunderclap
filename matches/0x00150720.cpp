// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Track_150720_vftable[];

class Track_150720 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class HitOrientToPushbackTrack_150720 : public Track_150720 {
  public:
    HitOrientToPushbackTrack_150720* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

HitOrientToPushbackTrack_150720* HitOrientToPushbackTrack_150720::vfunc_5(signed char flags) {
    *(void***)this = Track_150720_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
