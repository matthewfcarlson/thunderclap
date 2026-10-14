class X_192d50 {
  public:
    char Set(int);
    char pad[0xf8];
    int m;
};

char X_192d50::Set(int v) {
    m = v;
    return 1;
}
