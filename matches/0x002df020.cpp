// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Shadow_2df020_vftable[];

class Shadow_2df020 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class ShadowSkin_2df020 : public Shadow_2df020 {
  public:
    ShadowSkin_2df020* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

ShadowSkin_2df020* ShadowSkin_2df020::vfunc_5(signed char flags) {
    *(void***)this = Shadow_2df020_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
