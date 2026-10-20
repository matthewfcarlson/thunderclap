// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* FEObject_f1130_vftable[];

class FEObject_f1130 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class TextLabel_f1130 : public FEObject_f1130 {
  public:
    TextLabel_f1130* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

TextLabel_f1130* TextLabel_f1130::vfunc_5(signed char flags) {
    *(void***)this = FEObject_f1130_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
