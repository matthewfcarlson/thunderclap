class X_2987b0 {
  public:
    char pad[8];
    class Y_2987b0* p;
    void f();
};
class Y_2987b0 {
  public:
    virtual void a();
    virtual void b();
};
void X_2987b0::f() {
    if (p) {
        p->b();
        p = 0;
    }
}