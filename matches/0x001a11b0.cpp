typedef unsigned int u32;
struct Track { char x[0x148]; u32 Init(); };
struct Factory { virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual u32 f(); };
void* operator new(unsigned int);
u32 Factory::f() { Track* p = (Track*)::operator new(0x148); if (p) return p->Init(); return 0; }