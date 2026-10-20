// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Entity_236d10_vftable[];

class Entity_236d10 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class CSweepTrack_236d10 : public Entity_236d10 {
  public:
    CSweepTrack_236d10* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

CSweepTrack_236d10* CSweepTrack_236d10::vfunc_5(signed char flags) {
    *(void***)this = Entity_236d10_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
