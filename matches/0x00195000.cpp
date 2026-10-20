// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Track_195000_vftable[];

class Track_195000 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class AccuracyLatencyTrack_195000 : public Track_195000 {
  public:
    AccuracyLatencyTrack_195000* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

AccuracyLatencyTrack_195000* AccuracyLatencyTrack_195000::vfunc_5(signed char flags) {
    *(void***)this = Track_195000_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
