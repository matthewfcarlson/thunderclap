// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* SubCollisionDetector_301620_vftable[];

class SubCollisionDetector_301620 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class CollisionDetector_301620 : public SubCollisionDetector_301620 {
  public:
    CollisionDetector_301620* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

CollisionDetector_301620* CollisionDetector_301620::vfunc_5(signed char flags) {
    *(void***)this = SubCollisionDetector_301620_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
