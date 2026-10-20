// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* FEControl_f10c0_vftable[];

class FEControl_f10c0 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class TextButton_f10c0 : public FEControl_f10c0 {
  public:
    TextButton_f10c0* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

TextButton_f10c0* TextButton_f10c0::vfunc_5(signed char flags) {
    *(void***)this = FEControl_f10c0_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
