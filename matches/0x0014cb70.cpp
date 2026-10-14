class X_14cb70 {
  public:
    char Set(int v);
    char pad[0x20 - 1];
    int m;
};

char X_14cb70::Set(int v) {
    m = v;
    return 1;
}
