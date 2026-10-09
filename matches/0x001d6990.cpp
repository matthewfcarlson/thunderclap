// Same code shape as 0x001d64a0 (propagated; names are from that function)
class B {
  public:
    void G();
};
class A {
  public:
    char pad[0xec];
    B* p;
    void F();
};
void A::F() {
    p->G();
}