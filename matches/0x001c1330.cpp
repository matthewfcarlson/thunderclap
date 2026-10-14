class D {
  public:
    void f();
};
class C_1c1330 {
  public:
    char pad[0xbc];
    D* member;
    void g();
};
void C_1c1330::g() {
    member->f();
}