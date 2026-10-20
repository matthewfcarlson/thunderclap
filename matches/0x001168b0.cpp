// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Track_1168b0_vftable[];

class Track_1168b0 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

namespace hulkfight { namespace ai { class MotionChaseTrack : public Track_1168b0 {
  public:
    MotionChaseTrack* vfunc_5(signed char flags);
}; }}

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

hulkfight::ai::MotionChaseTrack* hulkfight::ai::MotionChaseTrack::vfunc_5(signed char flags) {
    *(void***)this = Track_1168b0_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
