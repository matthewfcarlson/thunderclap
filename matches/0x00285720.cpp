// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Entity_285720_vftable[];

class Entity_285720 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class FrameController_285720 : public Entity_285720 {
  public:
    FrameController_285720* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

FrameController_285720* FrameController_285720::vfunc_5(signed char flags) {
    *(void***)this = Entity_285720_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
