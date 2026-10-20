// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Track_173160_vftable[];

class Track_173160 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

namespace hulkfight { namespace motion { class CriticalMassDrainTrack : public Track_173160 {
  public:
    CriticalMassDrainTrack* vfunc_5(signed char flags);
}; }}

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

hulkfight::motion::CriticalMassDrainTrack* hulkfight::motion::CriticalMassDrainTrack::vfunc_5(signed char flags) {
    *(void***)this = Track_173160_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
