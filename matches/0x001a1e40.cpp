struct LuaTrack { void* vf; char pad[8]; int x; int y; int z; int q; void initialize(); };
extern void* alloc(unsigned int);
class Factory { public: virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual LuaTrack* vfunc_5(); };
LuaTrack* Factory::vfunc_5() { LuaTrack* p=(LuaTrack*)alloc(0x1c); if(p) { p->initialize(); p->vf=(void*)0x41c318; p->x=0; p->y=(int)0xbf800000; p->z=0; p->q=0; return p; } return 0; }