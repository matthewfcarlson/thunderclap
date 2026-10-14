class X_16ea90 {
  public:
    char pad[0x24];
    int m24;
    char Set(int v);
};

char X_16ea90::Set(int v) {
    m24 = v;
    return 1;
}
