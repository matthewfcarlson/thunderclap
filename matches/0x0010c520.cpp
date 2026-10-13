class C {
  public:
    char pad[0xc];
    int m;
    char f(int x);
};
char C::f(int x) {
    m = x;
    return 1;
}
