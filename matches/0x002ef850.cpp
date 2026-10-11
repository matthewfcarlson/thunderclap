extern "C" char DAT_003f6098[];
extern "C" char DAT_00431214[];
void freeit(void*);
class Obj {
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
    virtual void l();
    virtual void m();
    virtual void n();
    virtual void o();
    virtual void p();
    virtual void q();
    virtual void r();
    virtual void s();
    virtual void t();
    virtual void u();
    virtual void v();
    virtual void w();
    virtual void x();
    virtual void y();
    virtual void z();
    virtual void aa();
    virtual void ab();
    virtual void ac();
    virtual void ad(int);
};
class SimState {
  public:
    virtual void f0();
    virtual void f1();
    virtual SimState* f2(unsigned char);
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    char pad[0x6c];
    Obj* m70;
    Obj* m74;
};
SimState* SimState::f2(unsigned char flag) {
    Obj* a = m74;
    if (a) {
        *(void**)this = (void*)((int)DAT_00431214);
        *(int*)((char*)a + 0x18) = 0;
        m74->b();
    } else {
        *(void**)this = (void*)((int)DAT_00431214);
    }
    if (m70) {
        m70->ad(0);
        m70->b();
    }
    *(void**)this = (void*)((int)DAT_003f6098);
    if (flag & 1)
        freeit(this);
    return this;
}
