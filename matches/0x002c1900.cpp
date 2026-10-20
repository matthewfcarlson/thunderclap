// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Entity_2c1900_vftable[];

class Entity_2c1900 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class Locator_2c1900 : public Entity_2c1900 {
  public:
    Locator_2c1900* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

Locator_2c1900* Locator_2c1900::vfunc_5(signed char flags) {
    *(void***)this = Entity_2c1900_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
