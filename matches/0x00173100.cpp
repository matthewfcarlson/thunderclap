// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* Track_173100_vftable[];

class Track_173100 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};

namespace hulkfight { namespace motion { class SurfTrack : public Track_173100 {
  public:
    SurfTrack* vfunc_5(signed char flags);
}; }}

void __cdecl SweepTrack_DeleteThis(void* p); // thunk_FUN_00267090

hulkfight::motion::SurfTrack* hulkfight::motion::SurfTrack::vfunc_5(signed char flags) {
    *(void***)this = Track_173100_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}
