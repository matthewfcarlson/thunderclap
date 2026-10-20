// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Track_10eb40_vftable[];

class Track_10eb40 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

namespace hulkfight { namespace ai { class ButtonTrack : public Track_10eb40 {
  public:
    ButtonTrack* vfunc_5(signed char flags);
}; }}

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

hulkfight::ai::ButtonTrack* hulkfight::ai::ButtonTrack::vfunc_5(signed char flags) {
    *(void***)this = Track_10eb40_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
