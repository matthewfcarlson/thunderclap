// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* PartitionDriver_22a800_vftable[];

class PartitionDriver_22a800 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

class RestPoseDriver_22a800 : public PartitionDriver_22a800 {
  public:
    RestPoseDriver_22a800* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

RestPoseDriver_22a800* RestPoseDriver_22a800::vfunc_5(signed char flags) {
    *(void***)this = PartitionDriver_22a800_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
