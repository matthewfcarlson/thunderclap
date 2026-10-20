// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Track_148200_vftable[];

class Track_148200 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class CivilianDetachTrack_148200 : public Track_148200 {
  public:
    CivilianDetachTrack_148200* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

CivilianDetachTrack_148200* CivilianDetachTrack_148200::vfunc_5(signed char flags) {
    *(void***)this = Track_148200_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
