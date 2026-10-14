class O {
  public:
    char pad[12];
    int m;
    char f(int x);
};
char O::f(int x) {
    m = x;
    return 1;
}
