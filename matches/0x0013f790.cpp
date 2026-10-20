// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Track_13f790_vftable[];

class Track_13f790 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class WallJumpTrack_13f790 : public Track_13f790 {
  public:
    WallJumpTrack_13f790* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

WallJumpTrack_13f790* WallJumpTrack_13f790::vfunc_5(signed char flags) {
    *(void***)this = Track_13f790_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
