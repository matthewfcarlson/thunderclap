class X_10c230 {
  public:
    char pad[0x14];
    int m;
    char Set(int x);
};

char X_10c230::Set(int x) {
    m = x;
    return 1;
}
