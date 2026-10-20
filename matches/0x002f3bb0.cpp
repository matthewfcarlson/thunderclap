// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* CollisionVolume_2f3bb0_vftable[];

class CollisionVolume_2f3bb0 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class WorldCollisionVolume_2f3bb0 : public CollisionVolume_2f3bb0 {
  public:
    WorldCollisionVolume_2f3bb0* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

WorldCollisionVolume_2f3bb0* WorldCollisionVolume_2f3bb0::vfunc_5(signed char flags) {
    *(void***)this = CollisionVolume_2f3bb0_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
