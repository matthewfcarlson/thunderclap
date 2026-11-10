// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* BillboardQuadGroup_2bc760_vftable[];

class BillboardQuadGroup_2bc760 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class BillboardCutOffQuadGroup_2bc760 : public BillboardQuadGroup_2bc760 {
  public:
    BillboardCutOffQuadGroup_2bc760* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

BillboardCutOffQuadGroup_2bc760* BillboardCutOffQuadGroup_2bc760::vfunc_5(signed char flags) {
    *(void***)this = BillboardQuadGroup_2bc760_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
