class X_165660 {
  public:
    char pad[0x2c];
    int m;
    char Set(int v);
};

char X_165660::Set(int v) {
    m = v;
    return 1;
}