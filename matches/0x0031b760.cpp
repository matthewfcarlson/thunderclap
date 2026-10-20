// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* pddiObject_31b760_vftable[];

class pddiObject_31b760 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class pddiDevice_31b760 : public pddiObject_31b760 {
  public:
    pddiDevice_31b760* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

pddiDevice_31b760* pddiDevice_31b760::vfunc_5(signed char flags) {
    *(void***)this = pddiObject_31b760_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
