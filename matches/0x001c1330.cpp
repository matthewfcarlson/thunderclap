class D {
  public:
    void f(int);
};
class C_1c1330 {
  public:
    char pad[0xbc];
    D* member;
    void g(int);
};
void C_1c1330::g(int a0) {
    member->f(a0);
}