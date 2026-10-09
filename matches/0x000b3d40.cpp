class B {
  public:
    void call(int);
};
class A {
  public:
    int pad;
    B* member;
    void target();
};
void A::target() {
    member->call(1);
}