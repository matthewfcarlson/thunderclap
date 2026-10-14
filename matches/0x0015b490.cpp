class X {
  public:
    char Set(int v);
    char pad[0x58];
    int m58;
};

char X::Set(int v) {
    m58 = v;
    return 1;
}
