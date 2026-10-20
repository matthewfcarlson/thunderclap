// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* pddiObject_325f00_vftable[];

class pddiObject_325f00 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class pddiTexture_325f00 : public pddiObject_325f00 {
  public:
    pddiTexture_325f00* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

pddiTexture_325f00* pddiTexture_325f00::vfunc_5(signed char flags) {
    *(void***)this = pddiObject_325f00_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
