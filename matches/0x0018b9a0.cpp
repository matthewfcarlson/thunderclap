// Same code shape as 0x0018b6f0 (propagated; names are from that function)
typedef unsigned int u32;
void* __cdecl alloc(unsigned int);
struct InitObj { void init(int); };
extern int vtable;
struct Factory { virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual void* f(); };
void* Factory::f() { char* p=(char*)alloc(0x14); if(p){ ((InitObj*)p)->init(0); *(u32*)p=(u32)&vtable; *(u32*)(p+0xc)=0xffffffff; p[0x10]=1; return p; } return 0; }