// Same code shape as 0x00045820 (propagated; names are from that function)
class X_f68a0 {
  public:
    virtual void a();
    virtual void b();
};
struct C_f68a0 {
    X_f68a0* p;
    void f();
};
void C_f68a0::f() {
    if (p) {
        p->b();
        p = 0;
    }
}