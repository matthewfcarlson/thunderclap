struct R_e1cd0 {
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void go(void*);
};
struct Q_e1cd0 {
    char pad[4];
    R_e1cd0* r;
};
class FEDoScreen {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    char pad[0x10 - 4];
    Q_e1cd0* q;
    char pad2[0x34 - 0x14];
    char buf[1];
};
void FEDoScreen::v1() {
    q->r->go((char*)this + 0x34);
}