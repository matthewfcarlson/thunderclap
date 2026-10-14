class A {
  public:
    char p[0x10];
    int m;
    char f(int x);
};

char A::f(int x) {
    m = x;
    return 1;
}
