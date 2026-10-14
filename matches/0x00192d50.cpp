class X {
  public:
    char Set(int);
    char pad[0xf8];
    int m;
};

char X::Set(int v) {
    m = v;
    return 1;
}
