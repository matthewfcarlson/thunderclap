struct V {
    int x, y, z;
};
class A {
    char pad[0xb8];

  public:
    class B* b;
    void F(V v, int n);
};
class B {
  public:
    void G(V v, int n);
};
void A::F(V v, int n) {
    if (b)
        b->G(v, n);
}