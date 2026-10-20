// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* DrawableContainer_2dee20_vftable[];

class DrawableContainer_2dee20 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class Shadow_2dee20 : public DrawableContainer_2dee20 {
  public:
    Shadow_2dee20* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

Shadow_2dee20* Shadow_2dee20::vfunc_5(signed char flags) {
    *(void***)this = DrawableContainer_2dee20_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
