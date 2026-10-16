// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* CTrack_vftable[];

class CTrack {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

namespace hulkfight { namespace motion { class TargetLocomotionMotionStateCondition : public CTrack {
  public:
    TargetLocomotionMotionStateCondition* vfunc_5(signed char flags);
}; }}

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

hulkfight::motion::TargetLocomotionMotionStateCondition* hulkfight::motion::TargetLocomotionMotionStateCondition::vfunc_5(signed char flags) {
    *(void***)this = CTrack_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
