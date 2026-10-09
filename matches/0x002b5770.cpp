typedef unsigned int u32;
struct ShadowSkinImpl { virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual u32 vfunc_4(); virtual void e(); virtual void f(); virtual void g(); virtual void h(); virtual void i(); virtual void j(); };
struct Helper { u32 run(ShadowSkinImpl*); };
extern Helper* __cdecl thunk_FUN_0008d690(unsigned int);
u32 ShadowSkinImpl::vfunc_4() {
 Helper* p = thunk_FUN_0008d690(0x80);
 if (p) return p->run(this);
 return 0;
}