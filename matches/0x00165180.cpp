typedef unsigned int u32;
struct Factory { virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual u32 vfunc_5(); };
extern void* Allocate(unsigned int);
struct Product { u32 Initialize(); };
struct HeliFactory : Factory { u32 vfunc_5(); };
u32 HeliFactory::vfunc_5() {
    Product* p = (Product*)Allocate(0xd8);
    if (p) return p->Initialize();
    return 0;
}