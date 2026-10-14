// Same code shape as 0x00045820 (propagated; names are from that function)
class X_c6a70 {
  public:
    virtual void a();
    virtual void b();
};
struct C_c6a70 {
    X_c6a70* p;
    void f();
};
void C_c6a70::f() {
    if (p) {
        p->b();
        p = 0;
    }
}