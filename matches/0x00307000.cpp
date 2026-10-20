// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* CollisionVolume_307000_vftable[];

class CollisionVolume_307000 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class CollisionRay_307000 : public CollisionVolume_307000 {
  public:
    CollisionRay_307000* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

CollisionRay_307000* CollisionRay_307000::vfunc_5(signed char flags) {
    *(void***)this = CollisionVolume_307000_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
