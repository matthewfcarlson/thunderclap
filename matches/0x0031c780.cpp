// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* pddiObject_31c780_vftable[];

class pddiObject_31c780 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class pddiRenderContext_31c780 : public pddiObject_31c780 {
  public:
    pddiRenderContext_31c780* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

pddiRenderContext_31c780* pddiRenderContext_31c780::vfunc_5(signed char flags) {
    *(void***)this = pddiObject_31c780_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
