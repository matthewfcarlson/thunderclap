class FlyingDashTrack { public: unsigned int vt; unsigned int pad[2]; unsigned int a; unsigned int b; unsigned int c; unsigned int d; unsigned int e; unsigned int f; void Init(); };
class Factory { public: virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual FlyingDashTrack* vfunc_5(); };
extern void* __cdecl Alloc(unsigned int);
FlyingDashTrack* Factory::vfunc_5() { FlyingDashTrack* p=(FlyingDashTrack*)Alloc(0x24); if(p) { p->Init(); p->vt=0x411bb8; p->a=0; p->b=0xbf800000; p->c=0x42480000; p->d=0xfffffffb; p->e=0; p->f=0; return p; } return 0; }