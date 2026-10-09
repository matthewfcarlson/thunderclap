struct Caller {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual void m();
    virtual void n(void* p);
};
extern unsigned int g_flag;
extern unsigned int g_slot;
void target(Caller* p) {
    unsigned int one = 1;
    if ((((unsigned char)g_flag) & one) == 0) {
        g_flag |= one;
        g_slot = 0x42ed30;
    }
    p->n((void*)&g_slot);
}
