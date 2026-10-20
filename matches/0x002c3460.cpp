// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Camera_2c3460_vftable[];

class Camera_2c3460 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class PointCamera_2c3460 : public Camera_2c3460 {
  public:
    PointCamera_2c3460* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

PointCamera_2c3460* PointCamera_2c3460::vfunc_5(signed char flags) {
    *(void***)this = Camera_2c3460_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
