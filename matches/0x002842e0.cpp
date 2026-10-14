// Same code shape as 0x0027ff80 (propagated; names are from that function)
class D {
  public:
    void f();
};
class C_2842e0 {
  public:
    char pad[0x10];
    D* member;
    void target();
};
void C_2842e0::target() {
    member->f();
}