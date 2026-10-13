class O {
  public:
    char f(int v);
    char pad[0xc];
    int m;
};

char O::f(int v) {
    m = v;
    return 1;
}
