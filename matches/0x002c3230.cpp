extern "C" char DAT_0042ed30[];
struct Caller_2c3230 {
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
extern unsigned int g_flag_2c3230;
extern unsigned int g_slot_2c3230;
void target(Caller_2c3230* p) {
    unsigned int one = 1;
    if ((((unsigned char)g_flag_2c3230) & one) == 0) {
        g_flag_2c3230 |= one;
        g_slot_2c3230 = ((int)DAT_0042ed30);
    }
    p->n((void*)&g_slot_2c3230);
}
