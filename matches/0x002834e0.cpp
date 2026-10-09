// Same code shape as 0x001c37f0 (propagated; names are from that function)
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