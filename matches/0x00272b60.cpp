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