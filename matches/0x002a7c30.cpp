class C { public: virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual C* vfunc_4(); char pad[0x3c]; int x40; int x44; void init(C*); void setup(int); };
extern void* __cdecl alloc(unsigned int);
extern int vtable;
C* C::vfunc_4() { C* p=(C*)alloc(0x48); if(p) { p->init(this); *(int*)p=(int)&vtable; p->x40=x40; p->x44=0; p->setup(1); p->x44=x44; return p; } return 0; }