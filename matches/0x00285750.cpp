// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* FrameController_285750_vftable[];

class FrameController_285750 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class AnimationFrameController_285750 : public FrameController_285750 {
  public:
    AnimationFrameController_285750* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

AnimationFrameController_285750* AnimationFrameController_285750::vfunc_5(signed char flags) {
    *(void***)this = FrameController_285750_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
