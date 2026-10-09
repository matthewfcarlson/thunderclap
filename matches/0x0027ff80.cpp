class D {
  public:
    void f();
};
class C {
  public:
    char pad[0x10];
    D* member;
    void target();
};
void C::target() {
    member->f();
}