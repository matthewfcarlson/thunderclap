class X {
  public:
    char pad[8];
    class Y* p;
    void f();
};
class Y {
  public:
    virtual void a();
    virtual void b();
};
void X::f() {
    if (p) {
        p->b();
        p = 0;
    }
}