class B {
  public:
    void H();
};
class A {
    char pad[0x70];
    B* p;

  public:
    void F(int);
    void O();
};
void A::F(int x) {
    if (p)
        p->H();
    O();
}