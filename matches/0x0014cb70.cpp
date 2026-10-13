class X {
  public:
    char Set(int v);
    char pad[0x20 - 1];
    int m;
};

char X::Set(int v) {
    m = v;
    return 1;
}
