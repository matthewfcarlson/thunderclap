// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Branch_23c870_vftable[];

class Branch_23c870 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class Bank_23c870 : public Branch_23c870 {
  public:
    Bank_23c870* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

Bank_23c870* Bank_23c870::vfunc_5(signed char flags) {
    *(void***)this = Branch_23c870_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
