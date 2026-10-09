// Same code shape as 0x00272b60 (propagated; names are from that function)
class B {
  public:
    void f();
};
class A {
  public:
    char pad[0xb8];
    B* p;
    void run();
};
void A::run() {
    p->f();
}