class A {
  public:
    char pad[0x1c];
    int m;
    char f(int x);
};

char A::f(int x) {
    m = x;
    return 1;
}
