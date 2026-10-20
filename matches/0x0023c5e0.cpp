// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Bank_23c5e0_vftable[];

class Bank_23c5e0 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class Store_23c5e0 : public Bank_23c5e0 {
  public:
    Store_23c5e0* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

Store_23c5e0* Store_23c5e0::vfunc_5(signed char flags) {
    *(void***)this = Bank_23c5e0_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
