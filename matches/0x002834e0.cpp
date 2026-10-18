// Same code shape as 0x001c37f0 (propagated; names are from that function)
class Y_2834e0 {
  public:
    void g(int);
};
class X_2834e0 {
    char pad[0x18];
    Y_2834e0* p;

  public:
    void f(int);
};
void X_2834e0::f(int a0) {
    p->g(a0);
}