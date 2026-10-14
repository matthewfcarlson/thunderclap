typedef unsigned int u32_327d20;
class Obj_327d20 {
  public:
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
    virtual int l();
    virtual void m();
    virtual void n();
    virtual void o(u32_327d20);
    void target(u32_327d20);
};
extern u32_327d20 gSentinel_327d20;
extern Obj_327d20* gObj_327d20;
void Obj_327d20::target(u32_327d20 arg) {
    if (*(u32_327d20*)((char*)this + 12) != gSentinel_327d20) {
        if (gObj_327d20)
            gObj_327d20->n();
        gSentinel_327d20 = *(u32_327d20*)((char*)this + 12);
        m();
        o(arg);
        gObj_327d20 = this;
    } else if (l() != 1)
        o(arg);
}