// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Entity_2a5120_vftable[];

class Entity_2a5120 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class DrawablePrimitive_2a5120 : public Entity_2a5120 {
  public:
    DrawablePrimitive_2a5120* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

DrawablePrimitive_2a5120* DrawablePrimitive_2a5120::vfunc_5(signed char flags) {
    *(void***)this = Entity_2a5120_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
