// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* FEObject_f1ba0_vftable[];

class FEObject_f1ba0 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class MapThing_f1ba0 : public FEObject_f1ba0 {
  public:
    MapThing_f1ba0* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

MapThing_f1ba0* MapThing_f1ba0::vfunc_5(signed char flags) {
    *(void***)this = FEObject_f1ba0_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
