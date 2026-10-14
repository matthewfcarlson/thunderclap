// Same code shape as 0x00045820 (propagated; names are from that function)
class X_232a30 {
  public:
    virtual void a();
    virtual void b();
};
struct C_232a30 {
    X_232a30* p;
    void f();
};
void C_232a30::f() {
    if (p) {
        p->b();
        p = 0;
    }
}