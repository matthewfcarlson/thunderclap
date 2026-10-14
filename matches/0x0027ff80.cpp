class D {
  public:
    void f();
};
class C_27ff80 {
  public:
    char pad[0x10];
    D* member;
    void target();
};
void C_27ff80::target() {
    member->f();
}