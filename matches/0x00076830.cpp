// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* CIntangibleTrack_76830_vftable[];

class CIntangibleTrack_76830 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class CGrappleIntangibleTrack : public CIntangibleTrack_76830 {
  public:
    CGrappleIntangibleTrack* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

CGrappleIntangibleTrack* CGrappleIntangibleTrack::vfunc_5(signed char flags) {
    *(void***)this = CIntangibleTrack_76830_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
