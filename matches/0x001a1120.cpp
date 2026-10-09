typedef unsigned int u32;
struct Obj { u32 Init(); };
extern void* __cdecl Alloc(unsigned int);
struct TrackFactoryTemplate { virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual u32 f(); };
u32 TrackFactoryTemplate::f() { Obj* p = (Obj*)Alloc(0x138); if (p) return p->Init(); return 0; }