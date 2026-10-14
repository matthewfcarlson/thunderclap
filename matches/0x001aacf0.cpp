class X {
  public:
    char m0;
    int m4;
    char m8;
    int mC;
    char Set(int v);
};

char X::Set(int v) {
    mC = v;
    return 1;
}
