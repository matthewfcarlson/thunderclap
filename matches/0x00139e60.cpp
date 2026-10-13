class X {
  public:
    char pad[0x3d];
    int m40;
    char Set(int v);
};

char X::Set(int v) {
    m40 = v;
    return 1;
}
