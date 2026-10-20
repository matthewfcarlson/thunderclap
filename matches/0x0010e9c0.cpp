// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Condition_10e9c0_vftable[];

class Condition_10e9c0 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

namespace hulkfight { namespace ai { class RandomKeyWordWaitCondition : public Condition_10e9c0 {
  public:
    RandomKeyWordWaitCondition* vfunc_5(signed char flags);
}; }}

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

hulkfight::ai::RandomKeyWordWaitCondition* hulkfight::ai::RandomKeyWordWaitCondition::vfunc_5(signed char flags) {
    *(void***)this = Condition_10e9c0_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
