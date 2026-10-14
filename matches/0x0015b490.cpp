class X_15b490 {
  public:
    char Set(int v);
    char pad[0x58];
    int m58;
};

char X_15b490::Set(int v) {
    m58 = v;
    return 1;
}
