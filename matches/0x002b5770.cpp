typedef unsigned int u32_2b5770;
struct ShadowSkinImpl {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual u32_2b5770 vfunc_4();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
};
struct Helper_2b5770 {
    u32_2b5770 run(ShadowSkinImpl*);
};
extern Helper_2b5770* __cdecl thunk_FUN_0008d690(unsigned int);
u32_2b5770 ShadowSkinImpl::vfunc_4() {
    Helper_2b5770* p = thunk_FUN_0008d690(0x80);
    if (p)
        return p->run(this);
    return 0;
}