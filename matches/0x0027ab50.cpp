// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Entity_27ab50_vftable[];

class Entity_27ab50 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class RDLObject_27ab50 : public Entity_27ab50 {
  public:
    RDLObject_27ab50* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

RDLObject_27ab50* RDLObject_27ab50::vfunc_5(signed char flags) {
    *(void***)this = Entity_27ab50_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
