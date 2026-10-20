// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* DisplayList_29c050_vftable[];

class DisplayList_29c050 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class DrawableDisplayList_29c050 : public DisplayList_29c050 {
  public:
    DrawableDisplayList_29c050* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

DrawableDisplayList_29c050* DrawableDisplayList_29c050::vfunc_5(signed char flags) {
    *(void***)this = DisplayList_29c050_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
