// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Track_148260_vftable[];

class Track_148260 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class GrappleStruggleTrack_148260 : public Track_148260 {
  public:
    GrappleStruggleTrack_148260* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

GrappleStruggleTrack_148260* GrappleStruggleTrack_148260::vfunc_5(signed char flags) {
    *(void***)this = Track_148260_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
