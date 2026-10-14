struct O {
  public:
    int m0;
    int m4;
    int m8;
    int mC;
    char f(int x);
};

char O::f(int x) {
    mC = x;
    return 1;
}
