// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Entity_2ece00_vftable[];

class Entity_2ece00 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class Environment_2ece00 : public Entity_2ece00 {
  public:
    Environment_2ece00* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

Environment_2ece00* Environment_2ece00::vfunc_5(signed char flags) {
    *(void***)this = Entity_2ece00_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
