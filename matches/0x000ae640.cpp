class C_ae640 {
  public:
    int pad;
    int a;
    int f(int i);
};
int C_ae640::f(int i) {
    if (i >= 0 && i < 1)
        return *(&a + i);
    return 0;
}