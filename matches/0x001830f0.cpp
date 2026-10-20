// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Condition_1830f0_vftable[];

class Condition_1830f0 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

namespace hulkfight { namespace motion { class PropCollidedWithWorldCondition : public Condition_1830f0 {
  public:
    PropCollidedWithWorldCondition* vfunc_5(signed char flags);
}; }}

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

hulkfight::motion::PropCollidedWithWorldCondition* hulkfight::motion::PropCollidedWithWorldCondition::vfunc_5(signed char flags) {
    *(void***)this = Condition_1830f0_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
