// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Condition_167560_vftable[];

class Condition_167560 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

namespace hulkfight { namespace motion { class TurningVelocityCondition : public Condition_167560 {
  public:
    TurningVelocityCondition* vfunc_5(signed char flags);
}; }}

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

hulkfight::motion::TurningVelocityCondition* hulkfight::motion::TurningVelocityCondition::vfunc_5(signed char flags) {
    *(void***)this = Condition_167560_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
