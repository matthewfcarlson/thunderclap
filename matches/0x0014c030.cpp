typedef unsigned int u32;
struct GrappleStruggleTrack { u32 a0,a4,a8,ac,a10,a14,a18,a1c,a20; void initialize(); };
void* __cdecl alloc(unsigned int);
struct Factory { virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual void* make(); };
void* Factory::make() {
 GrappleStruggleTrack* p=(GrappleStruggleTrack*)alloc(0x24);
 if (p) {
  p->initialize(); p->ac=0; p->a14=0; p->a18=0; p->a1c=0; p->a20=0;
  p->a0=0x413678; p->a10=0xbf800000; p->a8=1;
  return p;
 }
 return 0;
}
