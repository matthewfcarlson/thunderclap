// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Condition_116730_vftable[];

class Condition_116730 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class ComputeDropZoneCondition_116730 : public Condition_116730 {
  public:
    ComputeDropZoneCondition_116730* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

ComputeDropZoneCondition_116730* ComputeDropZoneCondition_116730::vfunc_5(signed char flags) {
    *(void***)this = Condition_116730_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
