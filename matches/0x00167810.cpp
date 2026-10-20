// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Condition_167810_vftable[];

class Condition_167810 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class InLoadedRoomCondition_167810 : public Condition_167810 {
  public:
    InLoadedRoomCondition_167810* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

InLoadedRoomCondition_167810* InLoadedRoomCondition_167810::vfunc_5(signed char flags) {
    *(void***)this = Condition_167810_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
