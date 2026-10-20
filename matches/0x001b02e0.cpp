// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* CollisionSolverAgent_1b02e0_vftable[];

class CollisionSolverAgent_1b02e0 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class AICollisionSolverAgent_1b02e0 : public CollisionSolverAgent_1b02e0 {
  public:
    AICollisionSolverAgent_1b02e0* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

AICollisionSolverAgent_1b02e0* AICollisionSolverAgent_1b02e0::vfunc_5(signed char flags) {
    *(void***)this = CollisionSolverAgent_1b02e0_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
