// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* pddiObject_31ac90_vftable[];

class pddiObject_31ac90 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class pddiDisplay_31ac90 : public pddiObject_31ac90 {
  public:
    pddiDisplay_31ac90* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

pddiDisplay_31ac90* pddiDisplay_31ac90::vfunc_5(signed char flags) {
    *(void***)this = pddiObject_31ac90_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
