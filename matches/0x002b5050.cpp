// Same code shape as 0x00045820 (propagated; names are from that function)
class X_2b5050 {
  public:
    virtual void a();
    virtual void b();
};
struct C_2b5050 {
    X_2b5050* p;
    void f();
};
void C_2b5050::f() {
    if (p) {
        p->b();
        p = 0;
    }
}