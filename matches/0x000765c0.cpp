// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* CAutoTargetTrack_765c0_vftable[];

class CAutoTargetTrack_765c0 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class CGrappleAutoTargetTrack : public CAutoTargetTrack_765c0 {
  public:
    CGrappleAutoTargetTrack* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

CGrappleAutoTargetTrack* CGrappleAutoTargetTrack::vfunc_5(signed char flags) {
    *(void***)this = CAutoTargetTrack_765c0_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
