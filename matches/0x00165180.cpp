typedef unsigned int u32_165180;
struct Factory_165180 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual u32_165180 vfunc_5();
};
extern void* Allocate(unsigned int);
struct Product {
    u32_165180 Initialize();
};
struct HeliFactory : Factory_165180 {
    u32_165180 vfunc_5();
};
u32_165180 HeliFactory::vfunc_5() {
    Product* p = (Product*)Allocate(0xd8);
    if (p)
        return p->Initialize();
    return 0;
}