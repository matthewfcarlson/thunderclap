// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Entity_2a0ad0_vftable[];

class Entity_2a0ad0 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class Light_2a0ad0 : public Entity_2a0ad0 {
  public:
    Light_2a0ad0* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

Light_2a0ad0* Light_2a0ad0::vfunc_5(signed char flags) {
    *(void***)this = Entity_2a0ad0_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
