// Same code shape as 0x0005dd70 (propagated; names are from that function)
class CHitAnimationTrack { public: int vfunc_12(int); };
extern "C" void* __cdecl FUN_0008d690(unsigned int);
struct Helper { int FUN_0001cfd0(CHitAnimationTrack*, int); };
int CHitAnimationTrack::vfunc_12(int param) {
    Helper* p = (Helper*)FUN_0008d690(0x28);
    if (p) return p->FUN_0001cfd0(this, param);
    return 0;
}