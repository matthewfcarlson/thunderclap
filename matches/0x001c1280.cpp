class B {
  public:
    void F();
};
class A {
  public:
    char pad[4];
    B* m;
    void F();
};
void A::F() {
    m->F();
}
