class X {
  public:
    char pad[0x18];
    int m18;
    char f(int a);
};
char X::f(int a) {
    m18 = a;
    return 1;
}
