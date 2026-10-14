class X {
  public:
    char pad[0x24];
    int m24;
    char Set(int v);
};

char X::Set(int v) {
    m24 = v;
    return 1;
}
