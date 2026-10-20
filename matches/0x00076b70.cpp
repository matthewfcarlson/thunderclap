// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* CUninterruptibleTrack_76b70_vftable[];

class CUninterruptibleTrack_76b70 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class CGrappleUninterruptibleTrack : public CUninterruptibleTrack_76b70 {
  public:
    CGrappleUninterruptibleTrack* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

CGrappleUninterruptibleTrack* CGrappleUninterruptibleTrack::vfunc_5(signed char flags) {
    *(void***)this = CUninterruptibleTrack_76b70_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
