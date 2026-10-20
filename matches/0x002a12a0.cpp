// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Light_2a12a0_vftable[];

class Light_2a12a0 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class AmbientLight_2a12a0 : public Light_2a12a0 {
  public:
    AmbientLight_2a12a0* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

AmbientLight_2a12a0* AmbientLight_2a12a0::vfunc_5(signed char flags) {
    *(void***)this = Light_2a12a0_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
