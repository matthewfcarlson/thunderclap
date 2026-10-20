// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* DrawableContainer_2bea70_vftable[];

class DrawableContainer_2bea70 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class SpriteObject_2bea70 : public DrawableContainer_2bea70 {
  public:
    SpriteObject_2bea70* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

SpriteObject_2bea70* SpriteObject_2bea70::vfunc_5(signed char flags) {
    *(void***)this = DrawableContainer_2bea70_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
