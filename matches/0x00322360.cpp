typedef unsigned char u8;
class D {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void f4(D*, char);
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual void a16();
    virtual void a17();
    virtual void a18();
    virtual void a19();
    virtual void a20();
    virtual void a21();
    virtual void a22();
    char pad[0x79];
    u8 flag;
};
void D::f4(D* self, char on) {
    if (on)
        self->flag = 1;
    self->a22();
    if (on)
        self->flag = 0;
}