class X_10c610 {
  public:
    char pad[0x10];
    int m;
    char Set(int v);
};
char X_10c610::Set(int v) {
    m = v;
    return 1;
}
