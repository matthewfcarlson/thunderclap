// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Track_1482c0_vftable[];

class Track_1482c0 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class CivilianAttachTrack_1482c0 : public Track_1482c0 {
  public:
    CivilianAttachTrack_1482c0* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

CivilianAttachTrack_1482c0* CivilianAttachTrack_1482c0::vfunc_5(signed char flags) {
    *(void***)this = Track_1482c0_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
