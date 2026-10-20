// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* d3dShader_328770_vftable[];

class d3dShader_328770 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class d3dFBEffectsShader_328770 : public d3dShader_328770 {
  public:
    d3dFBEffectsShader_328770* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

d3dFBEffectsShader_328770* d3dFBEffectsShader_328770::vfunc_5(signed char flags) {
    *(void***)this = d3dShader_328770_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
