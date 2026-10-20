// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* CSoundTrack_76aa0_vftable[];

class CSoundTrack_76aa0 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class CGrappleSoundTrack : public CSoundTrack_76aa0 {
  public:
    CGrappleSoundTrack* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

CGrappleSoundTrack* CGrappleSoundTrack::vfunc_5(signed char flags) {
    *(void***)this = CSoundTrack_76aa0_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
