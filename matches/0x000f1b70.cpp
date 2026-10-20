// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* TextSelector_f1b70_vftable[];

class TextSelector_f1b70 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class MenuSelector_f1b70 : public TextSelector_f1b70 {
  public:
    MenuSelector_f1b70* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

MenuSelector_f1b70* MenuSelector_f1b70::vfunc_5(signed char flags) {
    *(void***)this = TextSelector_f1b70_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
