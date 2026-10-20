// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Track_10b950_vftable[];

class Track_10b950 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class FaceMotionTrack_10b950 : public Track_10b950 {
  public:
    FaceMotionTrack_10b950* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

FaceMotionTrack_10b950* FaceMotionTrack_10b950::vfunc_5(signed char flags) {
    *(void***)this = Track_10b950_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
