typedef unsigned int u32;
extern "C" void* __cdecl alloc(unsigned int);
class CWeaponCollisionTrack { public: u32 Init(); };
class TrackFactoryTemplate { public: virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual u32 vfunc_5(); };
u32 TrackFactoryTemplate::vfunc_5() {
    CWeaponCollisionTrack* p = (CWeaponCollisionTrack*)alloc(0x100);
    if (p) return p->Init();
    return 0;
}