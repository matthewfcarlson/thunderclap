class O_61f30 {
  public:
    char pad[12];
    volatile int m;
    char f(int x);
};
char O_61f30::f(int x) {
    m = x;
    return 1;
}
