// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* FEObject_f1370_vftable[];

class FEObject_f1370 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class FEControl_f1370 : public FEObject_f1370 {
  public:
    FEControl_f1370* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

FEControl_f1370* FEControl_f1370::vfunc_5(signed char flags) {
    *(void***)this = FEObject_f1370_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
