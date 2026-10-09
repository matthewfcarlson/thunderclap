struct PolySkin { virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual int vfunc_4(); };
struct Helper { int f(PolySkin*); };
extern void* __cdecl thunk_FUN_0008d690(unsigned int);
int PolySkin::vfunc_4() {
    Helper* p = (Helper*)thunk_FUN_0008d690(0x78);
    if (p) return p->f(this);
    return 0;
}