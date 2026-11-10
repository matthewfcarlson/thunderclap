// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* RenderObjectLoader_2ba8a0_vftable[];

class RenderObjectLoader_2ba8a0 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class BillboardQuadGroupLoader_2ba8a0 : public RenderObjectLoader_2ba8a0 {
  public:
    BillboardQuadGroupLoader_2ba8a0* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

BillboardQuadGroupLoader_2ba8a0* BillboardQuadGroupLoader_2ba8a0::vfunc_5(signed char flags) {
    *(void***)this = RenderObjectLoader_2ba8a0_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
