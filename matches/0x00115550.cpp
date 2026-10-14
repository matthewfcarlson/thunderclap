class X_115550 {
  public:
    char pad[0x28];
    int m28;
    char Set(int v);
};

char X_115550::Set(int v) {
    m28 = v;
    return 1;
}
