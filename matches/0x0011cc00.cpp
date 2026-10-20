// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Track_11cc00_vftable[];

class Track_11cc00 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class RoutTrack_11cc00 : public Track_11cc00 {
  public:
    RoutTrack_11cc00* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

RoutTrack_11cc00* RoutTrack_11cc00::vfunc_5(signed char flags) {
    *(void***)this = Track_11cc00_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
