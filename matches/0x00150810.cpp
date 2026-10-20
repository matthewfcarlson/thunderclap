// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Track_150810_vftable[];

class Track_150810 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class HitDamageTrack_150810 : public Track_150810 {
  public:
    HitDamageTrack_150810* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

HitDamageTrack_150810* HitDamageTrack_150810::vfunc_5(signed char flags) {
    *(void***)this = Track_150810_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
