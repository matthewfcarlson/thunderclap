class D {
  public:
    void f();
};
class C_3374a0 {
  public:
    char pad[0x510c];
    D* p;
    void f();
};
void C_3374a0::f() {
    p->f();
}