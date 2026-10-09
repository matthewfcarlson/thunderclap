typedef unsigned int u32;
void* __cdecl Allocate(unsigned int);
struct CGrappleEffectTrack { virtual void a(); void Init(); };
struct TrackFactoryTemplate { virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual void* vfunc_5(); };
void* TrackFactoryTemplate::vfunc_5() { CGrappleEffectTrack* p = (CGrappleEffectTrack*)Allocate(0x60); if (p != 0) { p->Init(); *(u32*)p = 0x3fd044; return p; } return 0; }