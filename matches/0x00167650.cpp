// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Condition_167650_vftable[];

class Condition_167650 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

namespace hulkfight { namespace motion { class TargetingCondition : public Condition_167650 {
  public:
    TargetingCondition* vfunc_5(signed char flags);
}; }}

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

hulkfight::motion::TargetingCondition* hulkfight::motion::TargetingCondition::vfunc_5(signed char flags) {
    *(void***)this = Condition_167650_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
