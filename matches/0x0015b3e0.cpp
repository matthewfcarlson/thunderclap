class O {
  public:
    char f(int x);
    char pad[0x20];
    int m;
};
char O::f(int x) {
    m = x;
    return 1;
}