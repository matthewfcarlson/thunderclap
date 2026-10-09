class Y {
  public:
    void g();
};
class X {
    char pad[0x18];
    Y* p;

  public:
    void f();
};
void X::f() {
    p->g();
}