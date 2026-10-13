class O {
  public:
    char f(int a);
    char pad[0xc];
    int m;
};
char O::f(int a) {
    m = a;
    return 1;
}
