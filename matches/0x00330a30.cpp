// Same code shape as 0x0027ff80 (propagated; names are from that function)
class D {
  public:
    void f();
};
class C_330a30 {
  public:
    char pad[0x10];
    D* member;
    void target();
};
void C_330a30::target() {
    member->f();
}