class X_45820 {
  public:
    virtual void a();
    virtual void b();
};
struct C_45820 {
    X_45820* p;
    void f();
};
void C_45820::f() {
    if (p) {
        p->b();
        p = 0;
    }
}