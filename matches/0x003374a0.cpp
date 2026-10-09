class D {
  public:
    void f();
};
class C {
  public:
    char pad[0x510c];
    D* p;
    void f();
};
void C::f() {
    p->f();
}