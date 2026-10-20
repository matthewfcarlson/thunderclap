// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Entity_1fc390_vftable[];

class Entity_1fc390 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class CLocator_1fc390 : public Entity_1fc390 {
  public:
    CLocator_1fc390* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

CLocator_1fc390* CLocator_1fc390::vfunc_5(signed char flags) {
    *(void***)this = Entity_1fc390_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
