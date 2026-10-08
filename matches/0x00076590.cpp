typedef unsigned int u32;
void* __cdecl Allocate(unsigned int);
class Track { public: void Init(); };
class Template { public: virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual void* f(); };
void* Template::f() { void* p = Allocate(0x3c); if (p) { ((Track*)p)->Init(); *(u32*)p = 0x3fe6c8; return p; } return 0; }