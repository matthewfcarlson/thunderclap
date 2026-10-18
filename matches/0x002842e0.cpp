// Same code shape as 0x0027ff80 (propagated; names are from that function)
class D {
  public:
    int f(int, int, int, int, int, int, int, int);
};
class C_2842e0 {
  public:
    char pad[0x10];
    D* member;
    int target(int, int, int, int, int, int, int, int);
};
int C_2842e0::target(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) {
    return member->f(a0, a1, a2, a3, a4, a5, a6, a7);
}