// Same code shape as 0x000ae640 (propagated; names are from that function)
class C_af3a0 {
  public:
    int pad;
    int a;
    int f(int i);
};
int C_af3a0::f(int i) {
    if (i >= 0 && i < 1)
        return *(&a + i);
    return 0;
}