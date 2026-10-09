class A {
  public:
    char pad0[4];
    int x;
    char pad8[4];
    int y;
    void f();
};
void A::f() {
    y = x;
}