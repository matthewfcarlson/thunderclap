// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Condition_124ef0_vftable[];

class Condition_124ef0 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

namespace hulkfight { namespace ai { class TargetDistanceYCondition : public Condition_124ef0 {
  public:
    TargetDistanceYCondition* vfunc_5(signed char flags);
}; }}

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

hulkfight::ai::TargetDistanceYCondition* hulkfight::ai::TargetDistanceYCondition::vfunc_5(signed char flags) {
    *(void***)this = Condition_124ef0_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
