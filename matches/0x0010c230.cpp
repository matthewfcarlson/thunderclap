class X {
  public:
    char pad[0x14];
    int m;
    char Set(int x);
};

char X::Set(int x) {
    m = x;
    return 1;
}
