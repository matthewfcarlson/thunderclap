// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Camera_a97b0_vftable[];

class Camera_a97b0 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class CGameCamera_a97b0 : public Camera_a97b0 {
  public:
    CGameCamera_a97b0* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

CGameCamera_a97b0* CGameCamera_a97b0::vfunc_5(signed char flags) {
    *(void***)this = Camera_a97b0_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
