// Same code shape as 0x001c37f0 (propagated; names are from that function)
class Y_2834e0 {
  public:
    void g();
};
class X_2834e0 {
    char pad[0x18];
    Y_2834e0* p;

  public:
    void f();
};
void X_2834e0::f() {
    p->g();
}