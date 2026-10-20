// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* pddiObject_3278e0_vftable[];

class pddiObject_3278e0 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class pddiShader_3278e0 : public pddiObject_3278e0 {
  public:
    pddiShader_3278e0* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

pddiShader_3278e0* pddiShader_3278e0::vfunc_5(signed char flags) {
    *(void***)this = pddiObject_3278e0_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
