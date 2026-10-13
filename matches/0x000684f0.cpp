class X {
  public:
    char Set(int n);
    int pad1;
    int pad2;
    int pad3;
    int m;
};

char X::Set(int n) {
    m = n;
    return 1;
}
