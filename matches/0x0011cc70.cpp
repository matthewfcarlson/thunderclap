// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Track_11cc70_vftable[];

class Track_11cc70 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class StrafeRunTrack_11cc70 : public Track_11cc70 {
  public:
    StrafeRunTrack_11cc70* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

StrafeRunTrack_11cc70* StrafeRunTrack_11cc70::vfunc_5(signed char flags) {
    *(void***)this = Track_11cc70_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
